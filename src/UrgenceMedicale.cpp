#include "UrgenceMedicale.hpp"

UrgenceMedicale::UrgenceMedicale(const std::string& id, const std::string& type, const std::string& loc, int grav,
                                int nbVict) 
    : Urgence(id, type, loc, grav), nbVictimes(nbVict) {}

int UrgenceMedicale::evaluerPriorite() const {
    // Ajustement : plus de victimes = plus prioritaire
    if (nbVictimes > 3) {
        return niveauGravite + 1;
    }
    return niveauGravite;
}

int UrgenceMedicale::getNbVictimes() const {
    return nbVictimes;
}

void UrgenceMedicale::setNbVictimes(int nb) {
    nbVictimes = nb;
}

std::string UrgenceMedicale::genererRequeteSQL() const {
    return "INSERT INTO urgences (id, type, localisation, gravite, statut, priorite, nbVictimes) VALUES ('"
        + id + "', '" + type + "', '" + localisation + "', " + std::to_string(niveauGravite) + ", '" 
        + statut + "', " + std::to_string(priorite) + ", " + std::to_string(nbVictimes) + ");";
}

