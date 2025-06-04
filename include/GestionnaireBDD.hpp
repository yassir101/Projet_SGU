#ifndef GESTIONNAIRE_BDD_HPP
#define GESTIONNAIRE_BDD_HPP

#include <sqlite3.h>
#include <string>
#include <iostream>
#include <memory>
#include "Utilisateur.hpp"
#include "Demandeur.hpp"
#include "Secouriste.hpp"
#include "Administrateur.hpp"
#include "CentreMedical.hpp"
#include "UnitePolice.hpp"
#include "Caserne.hpp"
#include "Urgence.hpp"
#include "Intervention.hpp"
#include "Rapport.hpp"
#include "Statistiques.hpp"

/**
 * @class GestionnaireBDD
 * @brief Gère l'interaction avec la base de données SQLite pour le SGU
 */
class GestionnaireBDD {
private:
    sqlite3* db; ///< Pointeur vers la base de données SQLite

public:
    /**
     * @brief Constructeur : ouvre la base de données
     */
    GestionnaireBDD(const std::string& nomFichier);

    /**
     * @brief Destructeur : ferme la base de données
     */
    ~GestionnaireBDD();

    /**
     * @brief Crée les tables nécessaires à l'initialisation du système
     */
    void initialiserTables();

    /**
     * @brief Insère un utilisateur de manière générique (Demandeur, Secouriste, Admin)
     */
    void insererUtilisateur(const Utilisateur& utilisateur);

    /**
     * @brief Insère une urgence
     */
    void insererUrgence(const Urgence& urgence);

    /**
     * @brief Insère une intervention
     */
    void insererIntervention(const Intervention& intervention);

    /**
     * @brief Insère une ressource (centre, police, caserne...)
     */
    void insererRessource(const Ressource& ressource);

    /**
     * @brief Génère un rapport sous forme de fichier CSV
     */
    void exporterRapport(const Rapport& rapport);
};

#endif // GESTIONNAIRE_BDD_HPP

