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