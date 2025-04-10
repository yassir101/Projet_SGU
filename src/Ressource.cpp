#include "Ressource.hpp"

Ressource::Ressource(const std::string& idIntervention, const std::string& debut, const std::string& idRessource) 
    : Intervention(idIntervention, debut), id(idRessource), disponible(true) {}

std::string Ressource::getIdRessource() const {
    return id;
}

bool Ressource::estDisponible() const {
    return disponible;
}

void Ressource::affecter() {
    disponible = false;
}

void Ressource::liberer() {
    disponible = true;
}