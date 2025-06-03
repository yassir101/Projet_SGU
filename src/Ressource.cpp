#include "Ressource.hpp"

Ressource::Ressource(const std::string& idRessource)
    : id(idRessource), disponible(true) {}

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
