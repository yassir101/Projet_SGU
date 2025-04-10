/**
 * @file Intervention.hpp
 * @brief Déclaration de la classe Intervention pour la gestion des opérations d'urgence
 */

#ifndef INTERVENTION_HPP
#define INTERVENTION_HPP

#include "Urgence.hpp"
#include "SuiviIntervention.hpp"
#include "Ressource.hpp"
#include <vector>
#include <memory>

/**
 * @class Intervention
 * @brief Représente une opération d'intervention sur une urgence
 * 
 * Cette classe gère le cycle de vie complet d'une intervention depuis son démarrage
 * jusqu'à sa clôture ou annulation, avec suivi des ressources mobilisées.
 */
class Intervention {
private:
    std::string id;                 ///< Identifiant unique de l'intervention
    std::string debut;              ///< Date/heure de début (format ISO8601)
    std::string fin;                ///< Date/heure de fin (format ISO8601)
    std::string statut;             ///< Statut courant (en attente, en cours, terminée, annulée)
    std::string raisonAnnulation;   ///< Raison d'annulation le cas échéant
    std::shared_ptr<Urgence> urgence;           ///< Urgence associée
    std::shared_ptr<SuiviIntervention> suivi;   ///< Suivi en temps réel
    std::vector<std::shared_ptr<Ressource>> ressources; ///< Ressources mobilisées

public:
    /**
     * @brief Constructeur d'intervention
     * @param id Identifiant unique
     * @param urgence Urgence à traiter
     */
    Intervention(const std::string& id, std::shared_ptr<Urgence> urgence);
    
    /// @name Gestion du cycle de vie
    /// @{
    /**
     * @brief Démarre l'intervention
     * @throws std::runtime_error Si l'intervention ne peut démarrer
     */
    void demarrer();
    
    /**
     * @brief Clôture l'intervention
     * @post Le statut passe à "terminée"
     */
    void cloturer();
    
    /**
     * @brief Annule l'intervention
     * @param raison Motif d'annulation
     * @post Le statut passe à "annulée"
     */
    void annuler(const std::string& raison);
    /// @}
    
    /**
     * @brief Notifie les secouristes affectés
     */
    void notifierSecouristes();
    
    /// @name Gestion des ressources
    /// @{
    /**
     * @brief Ajoute une ressource à l'intervention
     * @param ressource Ressource à mobiliser
     */
    void ajouterRessource(std::shared_ptr<Ressource> ressource);
    
    /**
     * @brief Liste des ressources mobilisées
     * @return Référence constante vers le vecteur de ressources
     */
    const std::vector<std::shared_ptr<Ressource>>& getRessources() const;
    /// @}
    
    /// @name Accesseurs
    /// @{
    std::string getId() const;
    std::string getStatut() const;
    std::shared_ptr<Urgence> getUrgence() const;
    std::shared_ptr<SuiviIntervention> getSuivi() const;
    /// @}
};

#endif // INTERVENTION_HPP
