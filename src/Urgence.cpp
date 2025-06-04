#include "Urgence.hpp"
#include <sstream>

Urgence::Urgence(const std::string& id, const std::string& type, const std::string& loc, int grav) 
    : id(id), type(type), localisation(loc), niveauGravite(grav), statut("en attente") {
    if (grav < 1 || grav > 3) niveauGravite = 1; // Valeur par défaut si hors limites
}

std::string Urgence::getIdUrgence() const {
    return id;
}

std::string Urgence::getTypeUrgence() const {
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



std::string Urgence::description() const {
    return toString();
}

void Urgence::setPriorite(int p) {
    priorite = p;
}

void Urgence::setRessources(const std::vector<Ressource>& r) {
    ressources = r;
}


void Urgence::mettreAJourStatut() {
    // Logique simple : si en attente, passe à "en cours", sinon à "terminée"
    if (statut == "en attente") {
        statut = "en cours";
    } else if (statut == "en cours") {
        statut = "terminée";
    }
}

int Urgence::getPriorite() const {
    return priorite;
}

std::vector<Ressource> Urgence::getRessources() const {
    return ressources;
}



std::string Urgence::toString() const {
    std::ostringstream oss;
    oss << "[" << type << "] ID=" << id << ", Gravité=" << niveauGravite 
        << ", Statut=" << statut << ", Localisation=" << localisation;
    return oss.str();
}
