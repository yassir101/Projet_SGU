/**
 * @file Caserne.hpp
 * @brief Ressource de type caserne de pompiers
 */

#ifndef CASERNE_HPP
#define CASERNE_HPP

#include "Ressource.hpp"

/**
 * @class Caserne
 * @brief Caserne de pompiers pouvant fournir des équipes d'intervention
 * 
 * Spécialisation concrète de Ressource pour les casernes de pompiers
 */
class Caserne : public Ressource {
private:
    int nbEquipesDisponibles;   ///< Nombre d'équipes actuellement disponibles

public:
    /**
     * @brief Constructeur
     * @param id Identifiant de la caserne
     * @param nbEquipes Nombre initial d'équipes disponibles
     */
    Caserne(const std::string& id, int nbEquipes);
    
    // Implémentation des méthodes virtuelles
    void affecter() override;
    void liberer() override;
    
    /// @name Opérations spécifiques
    /// @{
    /**
     * @brief Envoie une équipe sur le terrain
     * @post Décrémente nbEquipesDisponibles
     */
    void envoyerEquipe();
    
    /**
     * @brief Rappelle une équipe
     * @post Incrémente nbEquipesDisponibles
     */
    void rappelerEquipe();
    /// @}
    
    /**
     * @brief Nombre d'équipes disponibles
     * @return Entier représentant le nombre d'équipes
     */
    int getNbEquipesDisponibles() const;
};

#endif // CASERNE_HPP
