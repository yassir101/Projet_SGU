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