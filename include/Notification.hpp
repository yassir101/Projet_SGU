#ifndef NOTIFICATION_HPP
#define NOTIFICATION_HPP

/*!
 * \file Notification.hpp
 * \brief Déclaration de la classe Notification
 */

#include <string>
#include "Utilisateur.hpp"

/**
 * @class Notification
 * @brief Représente une notification à envoyer à un utilisateur
 *
 * Cette classe encapsule un message texte et fournit une méthode
 * pour notifier un utilisateur. Elle pourra être étendue pour intégrer
 * des canaux multiples (SMS, email, etc.) ou une journalisation.
 */
class Notification {
private:
    std::string message; ///< Contenu textuel de la notification

public:
    /**
     * @brief Constructeur par défaut
     */
    Notification();

    /**
     * @brief Constructeur avec initialisation
     * @param msg Contenu initial du message
     */
    Notification(const std::string& msg);

    /**
     * @brief Envoie la notification à un utilisateur donné
     * @param dest Référence vers l’utilisateur destinataire
     */
    void envoyer(Utilisateur& dest);

    /**
     * @brief Accesseur du message
     * @return Le message contenu dans la notification
     */
    std::string getMessage() const;

    /**
     * @brief Mutateur du message
     * @param nouveau Nouveau contenu à affecter
     */
    void setMessage(const std::string& nouveau);
};

#endif // NOTIFICATION_HPP

