#include "InterfaceUtilisateur.hpp"
#include <limits> // pour std::numeric_limits

void InterfaceUtilisateur::afficherStatut(const std::string& statut) const {
    std::cout << "\n[STATUT] " << statut << "\n";
}

void InterfaceUtilisateur::afficherUrgences(const GestionnaireBDD& bdd) const {
    std::cout << "\n=== Urgences en base de données ===\n";
    auto urgences = bdd.recupererUrgences();
    if (urgences.empty()) {
        std::cout << "Aucune urgence enregistrée.\n";
        return;
    }
    for (const auto& ligne : urgences) {
        std::cout << "- " << ligne << "\n";
    }
}

void InterfaceUtilisateur::afficherInterventionsParStatut(const GestionnaireBDD& bdd, const std::string& statut) const {
    std::cout << "\n=== Interventions avec statut : " << statut << " ===\n";
    auto interventions = bdd.recupererInterventionsParStatut(statut);
    if (interventions.empty()) {
        std::cout << "Aucune intervention avec ce statut.\n";
        return;
    }
    for (const auto& ligne : interventions) {
        std::cout << "- " << ligne << "\n";
    }
}

void InterfaceUtilisateur::mettreAJourStatutIntervention(GestionnaireBDD& bdd) const {
    std::string id, nouveauStatut;
    std::cout << "ID de l'intervention à mettre à jour : ";
    std::getline(std::cin, id);
    std::cout << "Nouveau statut (ex: en cours, terminée, annulée) : ";
    std::getline(std::cin, nouveauStatut);
    bdd.mettreAJourStatutIntervention(id, nouveauStatut);
}

void InterfaceUtilisateur::genererRapportDepuisArchivage(const Archivage& archivage) const {
    Rapport rapport = archivage.genererRapport();
    std::cout << "\n=== Rapport d'Activité ===\n";
    std::cout << rapport.toString();
}

void InterfaceUtilisateur::lancerInterface(GestionnaireBDD& bdd, Archivage& archivage) const {
    int choix = 0;
    do {
        std::cout << "\n====== MENU SGU ======\n";
        std::cout << "1. Signaler une urgence\n";
        std::cout << "2. Consulter les urgences\n";
        std::cout << "3. Voir interventions par statut\n";
        std::cout << "4. Modifier le statut d'une intervention\n";
        std::cout << "5. Générer un rapport depuis les archives\n";
        std::cout << "6. Quitter\n";
        std::cout << "Choix : ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // nettoyer entrée

        switch (choix) {
            case 1: {
                auto urgence = collecterUrgence();
                if (urgence) {
                    afficherStatut("Urgence enregistrée !");
                    bdd.insererUrgence(*urgence);
                    Intervention intervention("INT-" + std::to_string(rand() % 9999), urgence);
                    intervention.demarrer();
                    intervention.cloturer();
                    bdd.insererIntervention(intervention);
                    archivage.archiver(std::make_shared<Intervention>(intervention));
                }
                break;
            }
            case 2:
                afficherUrgences(bdd);
                break;

            case 3: {
                std::string statut;
                std::cout << "Statut à filtrer (en cours, terminée, annulée) : ";
                std::getline(std::cin, statut);
                afficherInterventionsParStatut(bdd, statut);
                break;
            }

            case 4:
                mettreAJourStatutIntervention(bdd);
                break;

            case 5:
                genererRapportDepuisArchivage(archivage);
                break;

            case 6:
                std::cout << "Fermeture du SGU...\n";
                break;

            default:
                std::cout << "Choix invalide.\n";
        }
    } while (choix != 6);
}


std::shared_ptr<Urgence> InterfaceUtilisateur::collecterUrgence() const {
    std::string type, localisation, graviteTxt;
    int gravite;

    std::cout << "=== Signalement d'une urgence ===\n";
    std::cout << "Type d'urgence (incendie / accident / médicale) : ";
    std::getline(std::cin, type);

    std::cout << "Localisation exacte : ";
    std::getline(std::cin, localisation);

    std::cout << "Gravité (faible / modérée / critique) : ";
    std::getline(std::cin, graviteTxt);

    if (graviteTxt == "faible") gravite = 1;
    else if (graviteTxt == "modérée") gravite = 2;
    else gravite = 3;

    std::string id = "U" + std::to_string(rand() % 10000);

    if (type == "incendie") {
        std::string typeFeu;
        std::cout << "Type de feu (habitation, forêt, véhicule...) : ";
        std::getline(std::cin, typeFeu);
        return std::make_shared<Incendie>(id, "Incendie", localisation, gravite, typeFeu);
    } else if (type == "accident") {
        int nbVeh;
        std::cout << "Nombre de véhicules impliqués : ";
        std::cin >> nbVeh;
        std::cin.ignore();
        return std::make_shared<Accident>(id, "Accident", localisation, gravite, nbVeh);
    } else {
        int nbVict;
        std::cout << "Nombre de victimes : ";
        std::cin >> nbVict;
        std::cin.ignore();
        return std::make_shared<UrgenceMedicale>(id, "Médicale", localisation, gravite, nbVict);
    }
}
