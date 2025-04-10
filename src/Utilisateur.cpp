#include "Utilisateur.hpp"

Utilisateur::Utilisateur(const std::string& id, const std::string& nom)
    : id(id), nom(nom) {}

std::string Utilisateur::getId() const {
    return id;
}

std::string Utilisateur::getNom() const {
    return nom;
}

void Utilisateur::setId(const std::string& nouvelId) {
    id = nouvelId;
}

void Utilisateur::setNom(const std::string& nouveauNom) {
    nom = nouveauNom;
}
