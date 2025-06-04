#ifndef DEMANDEUR_HPP
#define DEMANDEUR_HPP

#include "Utilisateur.hpp"
#include "QuestionnaireUrgence.hpp"
#include <string>

/**
 * @class Demandeur
 * @brief Utilisateur capable de signaler une urgence et de répondre à un questionnaire.
 *
 * Hérite de Utilisateur. Contient un numéro de téléphone pour contact.
 * La disponibilité est gérée via la classe Utilisateur.
 */
class Demandeur : public Utilisateur {
private:
    std::string telephone; ///< Numéro de téléphone du demandeur

public:
    /**
     * @brief Constructeur
     * @param id Identifiant unique
     * @param nom Nom du demandeur
     * @param tel Numéro de téléphone
     */
    Demandeur(const std::string& id, const std::string& nom, const std::string& tel);

    /**
     * @brief Signale une urgence auprès du système.
     */
    void signalerUrgence() const;

    /**
     * @brief Lance le processus de réponse au questionnaire.
     * @param questionnaire Référence au questionnaire à remplir
     */
    void repondreQuestionnaire(QuestionnaireUrgence& questionnaire) const;

    /**
     * @brief Récupère le numéro de téléphone du demandeur.
     * @return Numéro de téléphone
     */
    std::string getTelephone() const;

    /**
     * @brief Définit un nouveau numéro de téléphone.
     * @param tel Nouveau numéro
     */
    void setTelephone(const std::string& tel);

    /**
     * @brief Retourne le type de l'utilisateur (ici "Demandeur").
     * @return "Demandeur"
     */
    std::string getTypeUtilisateur() const override;

    /// @name Disponibilité (héritée de Utilisateur)
    /// @{
    /**
     * @brief Indique si le demandeur est disponible (hérité).
     * @return true si disponible
     */
    bool estDisponible() const; 

    /**
     * @brief Modifie la disponibilité du demandeur.
     * @param dispo true = disponible, false = indisponible
     */
    void setDisponible(bool dispo);
    /// @}
};

#endif // DEMANDEUR_HPP

