#include "../include/Notification.hpp"
#include <iostream>

// Constructeur par défaut
Notification::Notification() : message("") {}

// Constructeur avec initialisation du message
Notification::Notification(const std::string& msg) : message(msg) {}

// Envoie la notification à l'utilisateur
void Notification::envoyer(Utilisateur& dest) {
    std::cout << "Notification envoyée à " << dest.getNom() << " : " << message << std::endl;
}

// Retourne le message
std::string Notification::getMessage() const {
    return message;
}

// Modifie le message
void Notification::setMessage(const std::string& nouveau) {
    message = nouveau;
}
