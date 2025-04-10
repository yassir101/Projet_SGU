/**
 * @file SuiviIntervention.hpp
 * @brief Suivi en temps réel d'une intervention
 */

#ifndef SUIVI_INTERVENTION_HPP
#define SUIVI_INTERVENTION_HPP

#include "Intervention.hpp"
#include <memory>

/**
 * @class SuiviIntervention
 * @brief Tracking temps réel d'une intervention
 * 
 * Enregistre la position et le statut opérationnel des équipes sur le terrain.
 */
class SuiviIntervention {
private:
    std::string positionActuelle;   ///< Dernière position connue (coordonnées GPS)
    std::string statut;             ///< Statut opérationnel
    std::weak_ptr<Intervention> intervention;  ///< Lien vers l'intervention

public:
    /**
     * @brief Constructeur
     * @param intervention Intervention à suivre
     */
    explicit SuiviIntervention(std::shared_ptr<Intervention> intervention);
    
    /**
     * @brief Met à jour le suivi
     * @param position Nouvelle position
     * @param statut Nouveau statut
     */
    void mettreAJour(const std::string& position, const std::string& statut);
    
    /**
     * @brief Envoie une notification aux superviseurs
     */
    void envoyerNotification();
    
    /// @name Accesseurs
    /// @{
    std::string getPositionActuelle() const;
    std::string getStatut() const;
    std::shared_ptr<Intervention> getIntervention() const;
    /// @}
};

#endif // SUIVI_INTERVENTION_HPP
