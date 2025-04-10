#include "Urgence.hpp"

Urgence::Urgence(const std::string& loc, int grav) 
    : localisation(loc), niveauGravite(grav), statut("en attente") {
    if (grav < 1 || grav > 3) niveauGravite = 1; // Valeur par défaut si hors limites
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

void Urgence::setStatut(const std::string& st) {
    statut = st;
}