#ifndef NOTIFICATION_HPP
#define NOTIFICATION_HPP

/*!
 * \file Notification.hpp
 * \brief Déclaration de la classe Notification
 */

#include <string>
#include "Utilisateur.hpp"

/*!
 * \class Notification
 * \brief Représente une notification à envoyer à un utilisateur
 *
 * Cette classe encapsule un message à transmettre à un utilisateur.
 */
class Notification {
private:
    std::string message; /*!< Contenu du message */

public:
    /*!
     * \brief Constructeur par défaut
     */
    Notification();

    /*!
     * \brief Constructeur avec message initial
     * \param msg Contenu à initialiser
     */
    Notification(const std::string& msg);

    /*!
     * \brief Envoie une notification à un utilisateur
     * \param dest Utilisateur destinataire
     */
    void envoyer(Utilisateur& dest);

    /*!
     * \brief Récupère le message
     * \return Le message de la notification
     */
    std::string getMessage() const;

    /*!
     * \brief Modifie le message
     * \param nouveau Nouveau contenu du message
     */
    void setMessage(const std::string& nouveau);
};

#endif // NOTIFICATION_HPP

