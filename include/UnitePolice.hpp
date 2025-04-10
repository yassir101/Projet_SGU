/**
 * @file UnitePolice.hpp
 * @brief Ressource de type unité de police
 */

#ifndef UNITE_POLICE_HPP
#define UNITE_POLICE_HPP

#include "Ressource.hpp"

/**
 * @class UnitePolice
 * @brief Unité policière pouvant sécuriser une zone
 * 
 * Gère les effectifs policiers disponibles pour les interventions
 */
class UnitePolice : public Ressource {
private:
    int nbAgentsDisponibles; ///< Nombre d'agents actuellement disponibles

public:
    /**
     * @brief Constructeur
     * @param id Identifiant de l'unité
     * @param nbAgents Nombre initial d'agents disponibles
     */
    UnitePolice(const std::string& id, int nbAgents);
    
    // Implémentation des méthodes virtuelles
    void affecter() override;
    void liberer() override;
    
    /// @name Opérations spécifiques
    /// @{
    /**
     * @brief Déploie des agents sur zone
     * @post Décrémente nbAgentsDisponibles
     */
    void deplacerAgents();
    
    /**
     * @brief Procède à une évacuation
     */
    void evacuerZone();
    /// @}
    
    /**
     * @brief Nombre d'agents disponibles
     * @return Entier représentant les agents disponibles
     */
    int getNbAgentsDisponibles() const;
};

#endif // UNITE_POLICE_HPP
