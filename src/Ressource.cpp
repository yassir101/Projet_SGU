#include "Ressource.hpp"

Ressource::Ressource(const std::string& n) : nom(n), disponible(true) {}

bool Ressource::estDisponible() const {
    return disponible;
}

void Ressource::setDisponible(bool disp) {
    disponible = disp;
}