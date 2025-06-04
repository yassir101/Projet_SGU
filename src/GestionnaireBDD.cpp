#include "../include/GestionnaireBDD.hpp"
#include <fstream>

// Constructeur
GestionnaireBDD::GestionnaireBDD(const std::string& nomFichier) {
    if (sqlite3_open(nomFichier.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Erreur d'ouverture de la BDD: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    }
}

// Destructeur
GestionnaireBDD::~GestionnaireBDD() {
    if (db) {
        sqlite3_close(db);
    }
}

// Création des tables de base
void GestionnaireBDD::initialiserTables() {
    const char* requete =
        "CREATE TABLE IF NOT EXISTS Utilisateur ("
        "id TEXT PRIMARY KEY, "
        "nom TEXT, "
        "type TEXT);"

        "CREATE TABLE IF NOT EXISTS Urgence ("
        "id TEXT PRIMARY KEY, "
        "type TEXT);"

        "CREATE TABLE IF NOT EXISTS Intervention ("
        "id TEXT PRIMARY KEY, "
        "statut TEXT);"

        "CREATE TABLE IF NOT EXISTS Ressource ("
        "id TEXT PRIMARY KEY, "
        "disponible INTEGER);";

    char* erreur = nullptr;
    int code = sqlite3_exec(db, requete, nullptr, nullptr, &erreur);

    if (code != SQLITE_OK) {
        std::cerr << "Erreur de création des tables : " << erreur << std::endl;
        sqlite3_free(erreur);
    }
}

// Insertion générique d’utilisateur
void GestionnaireBDD::insererUtilisateur(const Utilisateur& utilisateur) {
    std::string requete =
        "INSERT INTO Utilisateur (id, nom, type) VALUES ('" +
        utilisateur.getId() + "', '" + utilisateur.getNom() + "', '" + utilisateur.getTypeUtilisateur() + "');";

    char* erreur = nullptr;
    int code = sqlite3_exec(db, requete.c_str(), nullptr, nullptr, &erreur);

    if (code != SQLITE_OK) {
        std::cerr << "Erreur d’insertion utilisateur : " << erreur << std::endl;
        sqlite3_free(erreur);
    }
}

// Insertion d'une urgence
void GestionnaireBDD::insererUrgence(const Urgence& urgence) {
    std::string requete =
        "INSERT INTO Urgence (id, type) VALUES ('" +
        urgence.getIdUrgence() + "', '" + urgence.getTypeUrgence() + "');";

    char* erreur = nullptr;
    int code = sqlite3_exec(db, requete.c_str(), nullptr, nullptr, &erreur);

    if (code != SQLITE_OK) {
        std::cerr << "Erreur d’insertion urgence : " << erreur << std::endl;
        sqlite3_free(erreur);
    }
}

// Insertion d’une intervention
void GestionnaireBDD::insererIntervention(const Intervention& intervention) {
    std::string requete =
        "INSERT INTO Intervention (id, statut) VALUES ('" +
        intervention.getId() + "', '" + intervention.getStatut() + "');";

    char* erreur = nullptr;
    int code = sqlite3_exec(db, requete.c_str(), nullptr, nullptr, &erreur);

    if (code != SQLITE_OK) {
        std::cerr << "Erreur d’insertion intervention : " << erreur << std::endl;
        sqlite3_free(erreur);
    }
}

// Insertion générique de ressource
void GestionnaireBDD::insererRessource(const Ressource& ressource) {
    std::string requete =
        "INSERT INTO Ressource (id, disponible) VALUES ('" +
        ressource.getIdRessource() + "', " + (ressource.estDisponible() ? "1" : "0") + ");";

    char* erreur = nullptr;
    int code = sqlite3_exec(db, requete.c_str(), nullptr, nullptr, &erreur);

    if (code != SQLITE_OK) {
        std::cerr << "Erreur d’insertion ressource : " << erreur << std::endl;
        sqlite3_free(erreur);
    }
}

// Export du rapport
void GestionnaireBDD::exporterRapport(const Rapport& rapport) {
    if (!db) {
        std::cerr << "La base de données n’est pas ouverte." << std::endl;
        return;
    }

    std::string nomFichier = "rapport_sgu.csv";
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Impossible d’écrire le fichier de rapport." << std::endl;
        return;
    }

    fichier << "=== Rapport SGU ===\n";
    fichier << rapport.getContenu() << "\n";
    fichier.close();

    std::cout << "[INFO] Rapport exporté dans : " << nomFichier << std::endl;
}

// Récupération des urgences enregistrées
std::vector<std::string> GestionnaireBDD::recupererUrgences() const {
    std::vector<std::string> urgences;
    const char* requete = "SELECT id, type FROM Urgence;";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, requete, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            std::string type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            urgences.push_back("Urgence ID: " + id + ", Type: " + type);
        }
        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Erreur récupération urgences : " << sqlite3_errmsg(db) << std::endl;
    }

    return urgences;
}

// Récupération des interventions par statut
std::vector<std::string> GestionnaireBDD::recupererInterventionsParStatut(const std::string& statut) const{
    std::vector<std::string> interventions;
    std::string requete = "SELECT id, statut FROM Intervention WHERE statut = '" + statut + "';";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, requete.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            std::string st = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            interventions.push_back("Intervention ID: " + id + ", Statut: " + st);
        }
        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Erreur récupération interventions : " << sqlite3_errmsg(db) << std::endl;
    }

    return interventions;
}

// Mise à jour du statut d'une intervention
void GestionnaireBDD::mettreAJourStatutIntervention(const std::string& id, const std::string& nouveauStatut) {
    std::string requete =
        "UPDATE Intervention SET statut = '" + nouveauStatut +
        "' WHERE id = '" + id + "';";

    char* erreur = nullptr;
    int code = sqlite3_exec(db, requete.c_str(), nullptr, nullptr, &erreur);
    if (code != SQLITE_OK) {
        std::cerr << "Erreur mise à jour statut : " << erreur << std::endl;
        sqlite3_free(erreur);
    } else {
        std::cout << "[BDD] Statut de l'intervention " << id << " mis à jour vers \"" << nouveauStatut << "\".\n";
    }
}

// Exécution générique et affichage (mode debug/admin)
void GestionnaireBDD::executerEtAfficher(const std::string& requeteSQL) {
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, requeteSQL.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        int nbColonnes = sqlite3_column_count(stmt);
        std::cout << "Résultats de : " << requeteSQL << "\n";

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            for (int i = 0; i < nbColonnes; ++i) {
                const char* val = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
                std::cout << sqlite3_column_name(stmt, i) << ": " << (val ? val : "NULL") << "\t";
            }
            std::cout << "\n";
        }
        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Erreur requête générique : " << sqlite3_errmsg(db) << std::endl;
    }
}


