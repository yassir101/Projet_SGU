#ifndef DEMANDEUR_HPP
#define DEMANDEUR_HPP

#include "Utilisateur.hpp"
#include "QuestionnaireUrgence.hpp"
#include <string>

/**
 * @class Demandeur
 * @brief Utilisateur capable de signaler une urgence et de répondre à un questionnaire.
 */
class Demandeur : public Utilisateur {
private:
    std::string telephone;

public:
    Demandeur(const std::string& id, const std::string& nom, const std::string& tel);

    void signalerUrgence() const;

    /**
     * @brief Lance le processus de réponse au questionnaire
     * @param questionnaire Référence au questionnaire à remplir
     */
    void repondreQuestionnaire(QuestionnaireUrgence& questionnaire) const;

    std::string getTelephone() const;
    void setTelephone(const std::string& tel);
};

#endif // DEMANDEUR_HPP
