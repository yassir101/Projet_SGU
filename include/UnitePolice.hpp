#ifndef UNITE_POLICE_HPP
#define UNITE_POLICE_HPP

/**
 * @file UnitePolice.hpp
 * @brief Déclaration de la classe UnitePolice
 */

#include "Ressource.hpp"

/**
 * @class UnitePolice
 * @brief Ressource représentant une unité policière mobilisable.
 *
 * Cette classe hérite de Ressource et permet de modéliser une unité de police
 * intervenant sur des scènes d’urgence pour sécuriser les zones, gérer les foules
 * ou appuyer les autres services.
 */
class UnitePolice : public Ressource {
private:
    int nbAgentsDisponibles; ///< Nombre d'agents opérationnels disponibles

public:
    /**
     * @brief Constructeur de l’unité policière
     * @param id Identifiant unique de la ressource
     * @param nbAgents Nombre initial d’agents disponibles
     */
    UnitePolice(const std::string& id, int nbAgents);

    /**
     * @brief Affecte un ou plusieurs agents à une opération
     *
     * Décrémente le nombre d’agents disponibles.
     * Lance une exception si aucun agent n’est disponible.
     */
    void affecter() override;

    /**
     * @brief Libère les agents après l'intervention
     */
    void liberer() override;
    
    std::string getType() const override;

    /// @name Actions spécifiques à la police
    /// @{

    /**
     * @brief Déploie des agents sur le terrain.
     *
     * Diminue le nombre d'agents disponibles.
     */
    void deplacerAgents();

    /**
     * @brief Simule une opération d’évacuation d’une zone.
     *
     * Peut être connectée au système de journalisation ou de notifications.
     */
    void evacuerZone();

    /// @}

    /**
     * @brief Retourne le nombre actuel d’agents disponibles
     * @return Nombre d’agents disponibles
     */
    int getNbAgentsDisponibles() const;

    /**
     * @brief Génère une commande SQL pour insérer cette unité en base de données
     * @return Requête SQL au format texte
     */
    std::string genererRequeteSQL() const;
};

#endif // UNITE_POLICE_HPP

