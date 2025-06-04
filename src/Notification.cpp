#include "../include/Notification.hpp"
#include <iostream>

Notification::Notification() : message("") {}

Notification::Notification(const std::string& msg) : message(msg) {}

void Notification::envoyer(Utilisateur& dest) {
    std::cout << "[Notification] Envoyée à " << dest.getNom() << " : " << message << std::endl;
}

std::string Notification::getMessage() const {
    return message;
}

void Notification::setMessage(const std::string& nouveau) {
    message = nouveau;
}

