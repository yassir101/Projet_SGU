#include "../include/CentreMedical.hpp"
#include <stdexcept>
#include <iostream>

CentreMedical::CentreMedical(const std::string& id, int nbAmbulances)
    : Ressource(id,"CentreMedical"), ambulancesDisponibles(nbAmbulances) {}

void CentreMedical::affecter() {
    if (ambulancesDisponibles <= 0) {
        throw std::runtime_error("Aucune ambulance disponible au centre " + id);
    }
    ambulancesDisponibles--;
    std::cout << "[Centre Médical] Ambulance affectée — Restantes : " << ambulancesDisponibles << std::endl;
}

void CentreMedical::liberer() {
    ambulancesDisponibles++;
    std::cout << "[Centre Médical] Ambulance rappelée — Disponibles : " << ambulancesDisponibles << std::endl;
}

void CentreMedical::envoyerAmbulance() {
    affecter();
}

void CentreMedical::rappelerAmbulance() {
    liberer();
}

int CentreMedical::getAmbulancesDisponibles() const {
    return ambulancesDisponibles;
}

std::string CentreMedical::getType() const {
    return "CentreMedical";
}

bool CentreMedical::estDisponible() const {
    return ambulancesDisponibles > 0;
}


std::string CentreMedical::genererRequeteSQL() const {
    return "INSERT INTO centres_medicaux (id, ambulances_disponibles, disponible) VALUES ('" + id + "', " +
           std::to_string(ambulancesDisponibles) + ", " + (estDisponible() ? "1" : "0") + ");";
}

