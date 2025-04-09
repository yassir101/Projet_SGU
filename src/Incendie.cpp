#include "Incendie.hpp"

Incendie::Incendie(const std::string& loc, int grav, const std::string& type, double surf) 
    : Urgence(loc, grav), typeFeu(type), superficie(surf) {}

std::string Incendie::description() const {
    return "Incendie de type " + typeFeu + " à " + localisation + " (superficie: " + std::to_string(superficie) + " m²)";
}