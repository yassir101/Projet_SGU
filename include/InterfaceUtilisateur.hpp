/**
 * @file InterfaceUtilisateur.hpp
 * @brief Classe représentant l'interface utilisateur du SGU.
 */

#ifndef INTERFACEUTILISATEUR_HPP
#define INTERFACEUTILISATEUR_HPP

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Urgence.hpp"
#include "Accident.hpp"
#include "Incendie.hpp"
#include "UrgenceMedicale.hpp"
#include "GestionnaireBDD.hpp"
#include "Intervention.hpp"
#include "Statistiques.hpp"
#include "Archivage.hpp"

/**
 * @class InterfaceUtilisateur
 * @brief Gère l’affichage des menus et la saisie des données utilisateur.
 */
class InterfaceUtilisateur {
public:
    /**
     * @brief Affiche le menu principal du système.
     */
    void afficherMenu() const;

    /**
     * @brief Affiche un message de statut générique.
     * @param statut Texte à afficher à l'utilisateur.
     */
    void afficherStatut(const std::string& statut) const;

    /**
     * @brief Collecte les informations d'une urgence auprès de l'utilisateur.
     * @return Un pointeur vers une instance de sous-classe de Urgence.
     */
    std::shared_ptr<Urgence> collecterUrgence() const;

    /**
     * @brief Lance la boucle principale d’interaction utilisateur.
     * @param bdd Référence vers le gestionnaire de base de données.
     * @param archivage Module d’archivage des interventions.
     */
    void lancerInterface(GestionnaireBDD& bdd, Archivage& archivage) const;

    /**
     * @brief Affiche toutes les urgences enregistrées dans la BDD.
     * @param bdd Référence vers le gestionnaire de base de données.
     */
    void afficherUrgences(const GestionnaireBDD& bdd) const;

    /**
     * @brief Affiche les interventions par statut.
     * @param bdd Référence vers la base de données.
     * @param statut Statut à filtrer (en cours, terminée, annulée...).
     */
    void afficherInterventionsParStatut(const GestionnaireBDD& bdd, const std::string& statut) const;

    /**
     * @brief Permet de saisir une mise à jour de statut pour une intervention existante.
     * @param bdd Référence vers le gestionnaire de base de données.
     */
    void mettreAJourStatutIntervention(GestionnaireBDD& bdd) const;

    /**
     * @brief Génère un rapport simple sur la base de l’archivage.
     * @param archivage Référence vers le module d’archivage.
     */
    void genererRapportDepuisArchivage(const Archivage& archivage) const;
};

#endif // INTERFACEUTILISATEUR_HPP

