#include "UrgenceMedicale.hpp"

UrgenceMedicale::UrgenceMedicale(const std::string& loc, int grav, const std::string& patho, int nbVict) 
    : Urgence(loc, grav), pathologie(patho), nombreVictimes(nbVict) {}

std::string UrgenceMedicale::description() const {
    return "Urgence médicale à " + localisation + " : " + pathologie + " affectant " + 
           std::to_string(nombreVictimes) + " victime(s)";
}