#include "Urgence.hpp"

Urgence::Urgence(const std::string& id, const std::string& type, const std::string& loc, int grav) 
    : id(id), type(type), localisation(loc), niveauGravite(grav), statut("en attente") {
    if (grav < 1 || grav > 3) niveauGravite = 1; // Valeur par défaut si hors limites
}

std::string Urgence::getId() const {
    return id;
}

std::string Urgence::getType() const {
    return type;
}

std::string Urgence::getLocalisation() const {
    return localisation;
}

void Urgence::setLocalisation(const std::string& loc) {
    localisation = loc;
}

int Urgence::getNiveauGravite() const {
    return niveauGravite;
}

std::string Urgence::getStatut() const {
    return statut;
}

void Urgence::setStatut(const std::string& st) {
    statut = st;
}

int Urgence::evaluerPriorite() const {
    // Priorité basée sur le niveau de gravité (1 à 3)
    return niveauGravite;
}

void Urgence::mettreAJourStatut() {
    // Logique simple : si en attente, passe à "en cours", sinon à "terminée"
    if (statut == "en attente") {
        statut = "en cours";
    } else if (statut == "en cours") {
        statut = "terminée";
    }
}