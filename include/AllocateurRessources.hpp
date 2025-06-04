/**
 * @file AllocateurRessources.hpp
 * @brief Gestionnaire intelligent des ressources d'urgence
 */

#ifndef ALLOCATEUR_RESSOURCES_HPP
#define ALLOCATEUR_RESSOURCES_HPP

#include "Intervention.hpp"
#include "Urgence.hpp"
#include "QuestionnaireUrgence.hpp"
#include "Ressource.hpp"
#include "Demandeur.hpp"
#include <vector>
#include <memory>

/**
 * @class AllocateurRessources
 * @brief Orchestrateur de l'allocation des ressources
 * 
 * Implémente le pattern Stratégie pour l'affectation optimale des ressources
 * selon le type et la gravité de l'urgence.
 */
class AllocateurRessources {
private:
    std::vector<std::shared_ptr<Ressource>> ressources; ///< Pool de ressources disponibles

public:
    AllocateurRessources();
    
    /// @name Gestion du pool de ressources
    /// @{
    /**
     * @brief Ajoute une ressource au pool
     * @param ressource Ressource à ajouter
     */
    void ajouterRessource(std::shared_ptr<Ressource> ressource);
    
    /**
     * @brief Vérifie la disponibilité par type
     * @param typeRessource Type de ressource recherchée
     * @return true si au moins une ressource est disponible
     */
    bool verifierDisponibilite(const std::string& typeRessource) const;
    /// @}
    
    /// @name Méthodes d'allocation
    /// @{
    /**
     * @brief Affecte des ressources à une urgence
     * @param urgence Urgence à traiter
     * @return Intervention créée ou nullptr
     */
    std::shared_ptr<Intervention> affecter(std::shared_ptr<Urgence> urgence);
    
    /**
     * @brief Lance le processus d'affectation
     */
    void declencherAffectation();
    /// @}
    
    /// @name Validation
    /// @{
    /**
     * @brief Vérifie la complétude d'un questionnaire
     * @param questionnaire Questionnaire à valider
     * @return true si le questionnaire est complet
     */
    bool verifierCompletude(std::shared_ptr<QuestionnaireUrgence> questionnaire) const;
    
    /**
     * @brief Demande des informations complémentaires
     * @param demandeur Demandeur à contacter
     */
    void demanderInfos(std::shared_ptr<Demandeur> demandeur);
    /// @}
    
    /**
     * @brief Crée une nouvelle intervention
     * @param urgence Urgence à traiter
     * @return Nouvelle intervention configurée
     */
    std::shared_ptr<Intervention> creerIntervention(std::shared_ptr<Urgence> urgence);
};

#endif // ALLOCATEUR_RESSOURCES_HPP
