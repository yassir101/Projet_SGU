#ifndef GESTIONNAIRE_BDD_HPP
#define GESTIONNAIRE_BDD_HPP

#include <sqlite3.h>
#include <string>
#include <vector>
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

    /**
     * @brief Récupère toutes les urgences de la base de données
     * @return Un vecteur de chaînes représentant chaque urgence
     */
    std::vector<std::string> recupererUrgences() const;

    /**
     * @brief Récupère toutes les interventions selon un statut donné
     * @param statut Le statut à filtrer (ex: "terminée", "en cours")
     * @return Un vecteur de chaînes représentant chaque intervention correspondante
     */
    std::vector<std::string> recupererInterventionsParStatut(const std::string& statut) const;

    /**
     * @brief Met à jour le statut d'une intervention
     * @param id L'identifiant de l'intervention
     * @param nouveauStatut Le nouveau statut (ex: "terminée")
     */
    void mettreAJourStatutIntervention(const std::string& id, const std::string& nouveauStatut);

    /**
     * @brief Exécute une requête SQL SELECT et affiche les résultats (debug/admin)
     * @param requeteSQL La requête à exécuter
     */
    void executerEtAfficher(const std::string& requeteSQL);
};

#endif // GESTIONNAIRE_BDD_HPP

