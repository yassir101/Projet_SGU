#include "../include/CentreMedical.hpp"

#include <stdexcept>

CentreMedical::CentreMedical(const std::string& id, int lits)
    : Ressource(id), litsDisponibles(lits) {}

void CentreMedical::affecter() {
    if (litsDisponibles <= 0) {
        throw std::runtime_error("Aucun lit disponible");
    }
    Ressource::affecter();
}

void CentreMedical::liberer() {
    Ressource::liberer();
}

void CentreMedical::affecterLit() {
    if (litsDisponibles > 0) {
        litsDisponibles--;
    }
}

void CentreMedical::libererLit() {
    litsDisponibles++;
}

int CentreMedical::getLitsDisponibles() const {
    return litsDisponibles;
}
