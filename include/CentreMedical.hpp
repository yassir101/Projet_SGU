/**
 * @file CentreMedical.hpp
 * @brief Ressource de type centre médical
 */

#ifndef CENTRE_MEDICAL_HPP
#define CENTRE_MEDICAL_HPP

#include "Ressource.hpp"

/**
 * @class CentreMedical
 * @brief Centre de soins pouvant accueillir des victimes
 * 
 * Gère principalement la disponibilité des lits d'hôpital
 */
class CentreMedical : public Ressource {
private:
    int litsDisponibles;    ///< Nombre de lits actuellement disponibles

public:
    /**
     * @brief Constructeur
     * @param id Identifiant du centre
     * @param lits Nombre initial de lits disponibles
     */
    CentreMedical(const std::string& id, int lits);
    
    // Implémentation des méthodes virtuelles
    void affecter() override;
    void liberer() override;
    
    /// @name Gestion des lits
    /// @{
    /**
     * @brief Réserve un lit
     * @post Décrémente litsDisponibles
     */
    void affecterLit();
    
    /**
     * @brief Libère un lit
     * @post Incrémente litsDisponibles
     */
    void libererLit();
    /// @}
    
    /**
     * @brief Nombre de lits disponibles
     * @return Entier représentant les lits libres
     */
    int getLitsDisponibles() const;
};

#endif // CENTRE_MEDICAL_HPP
