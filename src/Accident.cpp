#include "../include/Accident.hpp"

Accident::Accident(const std::string& id, const std::string& type, const std::string& loc, int grav,
                   int nbVeh) 
    : Urgence(id, type, loc, grav), nbVehicules(nbVeh) {}

std::string Accident::description() const {
    return "Accident à " + localisation + " impliquant " + std::to_string(nombreVehicules) + 
           " véhicule(s) et " + std::to_string(nombreBlesses) + " blessé(s)";
}

int Accident::evaluerPriorite() const {
    // Ajustement : plus de véhicules = plus prioritaire
    if (nbVehicules > 3) {
        return niveauGravite + 1;
    }
    return niveauGravite;
}

