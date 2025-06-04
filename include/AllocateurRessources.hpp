#ifndef ALLOCATEUR_RESSOURCES_HPP
#define ALLOCATEUR_RESSOURCES_HPP

#include <vector>
#include <memory>
#include <string>

#include "Intervention.hpp"
#include "Urgence.hpp"
#include "QuestionnaireUrgence.hpp"
#include "Ressource.hpp"
#include "Demandeur.hpp"
#include "Secouriste.hpp"

/**
 * @class AllocateurRessources
 * @brief Orchestrateur de l'allocation des ressources du SGU.
 *
 * Cette classe applique une logique décisionnelle pour l’affectation optimale des ressources disponibles
 * à une intervention, en tenant compte des contraintes du questionnaire renseigné.
 * Les ressources sont disponibles uniquement si elles ont au moins un secouriste disponible dans leur équipe.
 */
class AllocateurRessources {
private:
    std::vector<std::shared_ptr<Ressource>> ressources; ///< Pool de ressources disponibles

public:
    /// @brief Constructeur par défaut
    AllocateurRessources();

    /// @name Gestion du pool de ressources
    /// @{
    /**
     * @brief Ajoute une ressource disponible au pool.
     * @param ressource Ressource à ajouter
     */
    void ajouterRessource(std::shared_ptr<Ressource> ressource);

    /**
     * @brief Vérifie la disponibilité d’un type de ressource.
     * @param typeRessource Type recherché (ex: "Caserne", "CentreMedical")
     * @return true si une ressource de ce type a au moins un secouriste disponible
     */
    bool verifierDisponibilite(const std::string& typeRessource) const;
    /// @}

    /// @name Allocation des ressources
    /// @{
    /**
     * @brief Affecte des ressources pertinentes à une urgence.
     * @param urgence Urgence signalée
     * @return Pointeur vers l'intervention créée
     */
    std::shared_ptr<Intervention> affecter(std::shared_ptr<Urgence> urgence);

    /**
     * @brief Déclenche l'algorithme d’affectation (simulation actuelle).
     * Retire un secouriste disponible de chaque ressource affectée.
     */
    void declencherAffectation();
    /// @}

    /// @name Gestion des secouristes dans les ressources
    /// @{
    /**
     * @brief Libère un secouriste après intervention dans la ressource correspondante.
     * @param idRessource Identifiant de la ressource
     * @param secouriste Pointeur vers le secouriste à libérer
     */
    void libererSecouriste(const std::string& idRessource, std::shared_ptr<Secouriste> secouriste);
    /// @}

    /// @name Validation du formulaire d’urgence
    /// @{
    /**
     * @brief Vérifie si le questionnaire fourni est bien rempli.
     * @param questionnaire Questionnaire renseigné
     * @return true si toutes les réponses sont valides
     */
    bool verifierCompletude(std::shared_ptr<QuestionnaireUrgence> questionnaire) const;
    
    /**
     * @brief Demande des informations supplémentaires à l'utilisateur.
     * @param demandeur Utilisateur initial
     */
    void demanderInfos(std::shared_ptr<Demandeur> demandeur);
    /// @}

    /**
     * @brief Génère une nouvelle intervention pour une urgence.
     * @param urgence Urgence à gérer
     * @return Nouvelle intervention créée
     */
    std::shared_ptr<Intervention> creerIntervention(std::shared_ptr<Urgence> urgence);
};

#endif // ALLOCATEUR_RESSOURCES_HPP

