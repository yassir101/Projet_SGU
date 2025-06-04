#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <unistd.h>     // fork, execlp
#include <sys/wait.h>   // waitpid
#include <limits>

#include "../include/Demandeur.hpp"
#include "../include/Administrateur.hpp"
#include "../include/Secouriste.hpp"
#include "../include/GestionnaireUtilisateurs.hpp"
#include "../include/GestionnaireBDD.hpp"
#include "../include/InterfaceUtilisateur.hpp"
#include "../include/Archivage.hpp"
#include "../include/AllocateurRessources.hpp"
#include "../include/Urgence.hpp"
#include "../include/Intervention.hpp"
#include "../include/Ressource.hpp"

// Charge les utilisateurs depuis fichier CSV (Administrateurs, Secouristes)
template<typename T, typename... Args>
void chargerAdministrateursDepuisFichier(const std::string& cheminFichier,
                                      GestionnaireUtilisateurs& gestionnaire,
                                      GestionnaireBDD& gestionnaireBDD,
                                      Args&&... args) {
    std::ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        std::cerr << "[Erreur] Impossible d'ouvrir le fichier : " << cheminFichier << "\n";
        return;
    }

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::stringstream ss(ligne);
        std::vector<std::string> champs;
        std::string champ;
        while (std::getline(ss, champ, ';')) {
            champs.push_back(champ);
        }

        if constexpr(std::is_same_v<T, Administrateur>) {
            if (champs.size() < 3) continue;
            auto admin = std::make_shared<Administrateur>(champs[0], champs[1], std::stoi(champs[2]));
            gestionnaire.ajouterAdministrateur(admin);
            gestionnaireBDD.insererUtilisateur(*admin);
        } else if constexpr(std::is_same_v<T, Secouriste>) {
            if (champs.size() < 4) continue;
            auto sec = std::make_shared<Secouriste>(champs[0], champs[1], champs[2], champs[3]);
            gestionnaire.ajouterSecouriste(sec);
            gestionnaireBDD.insererUtilisateur(*sec);
        }
    }
    fichier.close();
}

void chargerSecouristesDepuisFichier(const std::string& cheminFichier,
                                    GestionnaireUtilisateurs& gestionnaire,
                                    GestionnaireBDD& gestionnaireBDD) {
    std::ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        std::cerr << "[Erreur] Impossible d'ouvrir le fichier : " << cheminFichier << "\n";
        return;
    }

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::stringstream ss(ligne);
        std::string id, nom, matricule, specialite, etatStr;

        std::getline(ss, id, ';');
        std::getline(ss, nom, ';');
        std::getline(ss, matricule, ';');
        std::getline(ss, specialite, ';');
        std::getline(ss, etatStr, ';');

        auto secouriste = std::make_shared<Secouriste>(id, nom, matricule, specialite);

        // Adapter l'état
        if (etatStr == "Libre") {
            secouriste->setEtat(EtatUtilisateur::Libre);
        } else {
            secouriste->setEtat(EtatUtilisateur::HorsService); // Ou Occupe si tu veux gérer ça
        }

        gestionnaire.ajouterSecouriste(secouriste);
        gestionnaireBDD.insererUtilisateur(*secouriste);
    }
    fichier.close();
}


// Chargement des ressources depuis fichier CSV
void chargerRessourcesDepuisFichier(const std::string& cheminFichier,
                                    AllocateurRessources& allocateur,
                                    GestionnaireBDD& gestionnaireBDD,
                                    GestionnaireUtilisateurs& gestionnaireUtilisateurs) {
    std::ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        std::cerr << "[Erreur] Impossible d'ouvrir le fichier des ressources : " << cheminFichier << "\n";
        return;
    }

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::stringstream ss(ligne);
        std::string id, type, etatStr;

        std::getline(ss, id, ';');
        std::getline(ss, type, ';');
        std::getline(ss, etatStr, ';');

        std::shared_ptr<Ressource> ressource;

        if (type == "Caserne") {
            ressource = std::make_shared<Caserne>(id, 0); // nombre secouristes à compléter
        } else if (type == "UnitePolice") {
            ressource = std::make_shared<UnitePolice>(id, 0);
        } else if (type == "CentreMedical") {
            ressource = std::make_shared<CentreMedical>(id, 0);
        } else if (type == "Ambulance") {
            // Si tu as une classe Ambulance sinon ignore
            // ressource = std::make_shared<Ambulance>(id, 0);
            continue; // ou gestion personnalisée
        } else {
            std::cout << "[Info] Type ressource inconnu: " << type << "\n";
            continue;
        }

        // Affecter l’état
        /*
        if (etatStr == "Disponible") {
            ressource->setDisponible(true);
        } else {
            ressource->setDisponible(false);
        }*/

        // Lier secouristes libres (selon ta logique)
        int nbSecouristesAjoutes = 0;
        for (auto& sec : gestionnaireUtilisateurs.getSecouristes()) {
            if (nbSecouristesAjoutes >= 5) break; // ou autre critère
            if (sec->estDisponible()) {
                ressource->ajouterSecouriste(sec);
                nbSecouristesAjoutes++;
            }
        }

        allocateur.ajouterRessource(ressource);
        gestionnaireBDD.insererRessource(*ressource);
    }
    fichier.close();
}


int main(int argc, char* argv[]) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Initialisations communes
    GestionnaireBDD gestionnaireBDD("sgu.db");
    gestionnaireBDD.initialiserTables();

    GestionnaireUtilisateurs gestionnaireUtilisateurs;
    AllocateurRessources allocateur;
    Archivage archivage;
    InterfaceUtilisateur interface;

    // Chargement utilisateurs et ressources (sauf demandeurs dynamiques)
    chargerAdministrateursDepuisFichier<Administrateur>("data/administrateurs.txt", gestionnaireUtilisateurs, gestionnaireBDD);
	chargerSecouristesDepuisFichier("data/secouristes.txt", gestionnaireUtilisateurs, gestionnaireBDD);
    chargerRessourcesDepuisFichier("data/ressources.txt", allocateur, gestionnaireBDD, gestionnaireUtilisateurs);

    // Mode session appel ?
    if (argc > 1 && std::string(argv[1]) == "--appel") {
        // Traitement complet de l'appel dans un terminal dédié (processus enfant)
        std::cout << "=== Session d'appel SGU démarrée ===\n";

        // Collecte le numéro du demandeur en argument
        std::string telDemandeur;
        if (argc > 2) telDemandeur = argv[2];
        else {
            std::cerr << "Erreur: numéro du demandeur manquant\n";
            return 1;
        }

        // Recherche ou création demandeur dynamique
        std::shared_ptr<Demandeur> demandeur = nullptr;
        for (const auto& d : gestionnaireUtilisateurs.getDemandeurs()) {
            if (d->getTelephone() == telDemandeur) {
                demandeur = d;
                break;
            }
        }
        if (!demandeur) {
            std::string nom;
            std::cout << "Nouveau demandeur détecté. Entrez le nom : ";
            std::getline(std::cin, nom);
            std::string idDemandeur = "D" + std::to_string(gestionnaireUtilisateurs.getDemandeurs().size() + 1);
            demandeur = std::make_shared<Demandeur>(idDemandeur, nom, telDemandeur);
            gestionnaireUtilisateurs.ajouterDemandeur(demandeur);
            gestionnaireBDD.insererUtilisateur(*demandeur);
        }

        // Collecte de l'urgence
        auto urgence = interface.collecterUrgence();
        if (!urgence) {
            std::cerr << "Erreur lors de la collecte de l'urgence.\n";
            return 1;
        }

        // Allocation ressources
        auto intervention = allocateur.affecter(urgence);
        if (!intervention) {
            std::cerr << "Aucune ressource disponible pour cette urgence.\n";
            return 1;
        }

        intervention->demarrer();
        gestionnaireBDD.insererUrgence(*urgence);
        gestionnaireBDD.insererIntervention(*intervention);
        archivage.archiver(intervention);

        std::cout << "Intervention démarrée avec ID : " << intervention->getId() << "\n";

        // TODO: gestion suivi intervention (menu, fin, etc.)

        std::cout << "=== Fin de la session d'appel ===\n";
        return 0;
    }

    // Mode terminal principal (accueil)
    std::cout << "=== Démarrage du Système de Gestion des Urgences (SGU) - Terminal principal ===\n";

    int compteurDemandeurs = 1;

    bool continuer = true;
    while (continuer) {
        std::cout << "\n--- Menu principal ---\n";
        std::cout << "1. Recevoir un appel\n";
        std::cout << "2. Générer un rapport\n";
        std::cout << "3. Quitter\n";
        std::cout << "Choix : ";

        int choix = 0;
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choix == 1) {
            std::string tel;
            std::cout << "Numéro téléphone du demandeur : ";
            std::getline(std::cin, tel);

            // Recherche admin libre
            auto adminDispo = gestionnaireUtilisateurs.trouverAdministrateurLibre();
            if (!adminDispo) {
                std::cout << "Aucun administrateur disponible, veuillez patienter...\n";
                continue;
            }

            // L'administrateur décide d'accepter ou non l'appel
            std::cout << "Administrateur " << adminDispo->getNom() << " reçoit l'appel. Accepter ? (o/n) : ";
            std::string repAdmin;
            std::getline(std::cin, repAdmin);
            if (repAdmin != "o" && repAdmin != "O") {
                std::cout << "Appel refusé par l’administrateur.\n";
                continue;
            }

            // Ouvre un nouveau terminal pour gérer l’appel
            pid_t pid = fork();
            if (pid == 0) {
                // Processus enfant lance une nouvelle session dans un terminal
                execlp("gnome-terminal", "gnome-terminal", "--", "./sgu", "--appel", tel.c_str(), nullptr);
                std::cerr << "Erreur lors du lancement du terminal d'appel\n";
                return 1;
            } else if (pid > 0) {
                // Parent peut attendre ou pas l'enfant, ici on ne bloque pas
                std::cout << "Session d'appel ouverte dans un nouveau terminal.\n";
            } else {
                std::cerr << "Erreur fork\n";
            }

        } else if (choix == 2) {
            // À implémenter : génération de rapport global
            std::cout << "[Fonctionnalité rapport] Non implémentée.\n";

        } else if (choix == 3) {
            continuer = false;
        } else {
            std::cout << "Choix invalide.\n";
        }
    }

    std::cout << "=== Arrêt du SGU ===\n";
    return 0;
}

