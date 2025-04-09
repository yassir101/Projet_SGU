#include "Accident.hpp"

Accident::Accident(const std::string& loc, int grav, int nbVeh, int nbBless) 
    : Urgence(loc, grav), nombreVehicules(nbVeh), nombreBlesses(nbBless) {}

std::string Accident::description() const {
    return "Accident à " + localisation + " impliquant " + std::to_string(nombreVehicules) + 
           " véhicule(s) et " + std::to_string(nombreBlesses) + " blessé(s)";
}