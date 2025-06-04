/**
 * @file QuestionnaireUrgence.hpp
 * @brief Gère la collecte structurée d'informations après le signalement d'une urgence.
 */

#ifndef QUESTIONNAIRE_URGENCE_HPP
#define QUESTIONNAIRE_URGENCE_HPP

#include <vector>
#include <string>
#include <map>

/**
 * @class QuestionnaireUrgence
 * @brief Gère un formulaire dynamique pour décrire une situation d'urgence.
 *
 * Cette classe est utilisée par un Demandeur pour remplir un formulaire d’évaluation d’une urgence.
 * Les réponses seront ensuite analysées par le système SGU via le GestionnaireUrgence.
 */
class QuestionnaireUrgence {
private:
    std::vector<std::string> questions; ///< Questions dynamiques générées
    std::map<std::string, std::vector<std::string>> choixParQuestion; ///< Choix possibles par question
    std::map<std::string, std::string> reponses; ///< Réponses données
    bool complet; ///< Statut du remplissage

public:
    /// @brief Constructeur
    QuestionnaireUrgence();

    /// @brief Génère dynamiquement les questions du formulaire
    void genererQuestions();

    /// @brief Simule un remplissage interactif
    void remplir();

    /// @brief Vérifie la cohérence des réponses
    bool validerReponses() const;

    /**
     * @brief Ajoute ou corrige une réponse manuellement
     * @param question Question concernée
     * @param reponse Réponse à affecter
     */
    void completerInformations(const std::string& question, const std::string& reponse);

    /// @brief Modifie l’état de complétion
    void setComplet(bool etat);

    /// @brief Vérifie si le questionnaire est complet
    bool estComplet() const;

    /// @brief Transmet toutes les réponses collectées (simulation console)
    void transmettreReponses() const;

    /// @brief Accès brut à la liste des questions
    const std::vector<std::string>& getQuestions() const;
};

#endif // QUESTIONNAIRE_URGENCE_HPP

