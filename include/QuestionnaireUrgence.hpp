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
 */
class QuestionnaireUrgence {
private:
    std::vector<std::string> questions;
    std::map<std::string, std::vector<std::string>> choixParQuestion; // chaque question a une liste de choix
    std::map<std::string, std::string> reponses;
    bool complet;                                   ///< Indique si le questionnaire est complet

public:
    QuestionnaireUrgence();

    /**
     * @brief Génère dynamiquement les questions à poser
     */
    void genererQuestions();

    /**
     * @brief Simule le remplissage du questionnaire par l'utilisateur
     */
    void remplir();

    /**
     * @brief Vérifie si toutes les questions ont reçu une réponse valide
     * @return true si tout est cohérent, false sinon
     */
    bool validerReponses() const;

    /**
     * @brief Permet de compléter manuellement certaines informations
     * @param question La question à ajouter
     * @param reponse La réponse correspondante
     */
    void completerInformations(const std::string& question, const std::string& reponse);

    /**
     * @brief Marque le questionnaire comme complet ou non
     * @param etat true si complet
     */
    void setComplet(bool etat);

    /**
     * @brief Vérifie si le questionnaire est complet
     * @return true si complet
     */
    bool estComplet() const;

    /**
     * @brief Transmet toutes les réponses collectées
     */
    void transmettreReponses() const;

    // Accès brut aux questions (utile pour tests ou affichages)
    const std::vector<std::string>& getQuestions() const;
};

#endif // QUESTIONNAIRE_URGENCE_HPP
