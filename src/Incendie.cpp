#include "Incendie.hpp"

Incendie::Incendie(const std::string& id, const std::string& type, const std::string& loc, int grav,
                   const std::string& typeFeu) 
    : Urgence(id, type, loc, grav), typeFeu(typeFeu) {}

int Incendie::evaluerPriorite() const {
    // Les incendies de forêt sont plus prioritaires
    if (typeFeu == "forêt") {
        return niveauGravite + 1;
    }
    return niveauGravite;
}

std::string Incendie::description() const {
    return "Incendie de type " + typeFeu + " à " + localisation;
}

std::string Incendie::getTypeFeu() const {
    return typeFeu;
}

void Incendie::setTypeFeu(const std::string& tf) {
    typeFeu = tf;
}

std::string Incendie::genererRequeteSQL() const {
    return "INSERT INTO urgences (id, type, localisation, gravite, statut, priorite, typeFeu) VALUES ('"
        + id + "', '" + type + "', '" + localisation + "', " + std::to_string(niveauGravite) + ", '" 
        + statut + "', " + std::to_string(priorite) + ", '" + typeFeu + "');";
}
