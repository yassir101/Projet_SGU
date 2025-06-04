#include "../include/Accident.hpp"

Accident::Accident(const std::string& id, const std::string& type, const std::string& loc, int grav,
                   int nbVeh) 
    : Urgence(id, type, loc, grav), nbVehicules(nbVeh) {}

std::string Accident::description() const {
    return "Accident à " + localisation + " impliquant " + std::to_string(nbVehicules) +
           " véhicule(s)";
}

int Accident::evaluerPriorite() const {
    // Ajustement : plus de véhicules = plus prioritaire
    if (nbVehicules > 3) {
        return niveauGravite + 1;
    }
    return niveauGravite;
}

int Accident::getNbVehicules() const {
    return nbVehicules;
}

void Accident::setNbVehicules(int nbVeh) {
    nbVehicules = nbVeh;
}

std::string Accident::genererRequeteSQL() const {
    return "INSERT INTO urgences (id, type, localisation, gravite, statut, priorite, nbVehicules) VALUES ('" 
        + id + "', '" + type + "', '" + localisation + "', " + std::to_string(niveauGravite) + ", '" 
        + statut + "', " + std::to_string(priorite) + ", " + std::to_string(nbVehicules) + ");";
}

