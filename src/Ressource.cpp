#include "../include/Ressource.hpp"

Ressource::Ressource(const std::string& idRessource, const std::string& type)
    : id(idRessource), disponible(true), type(type) {}

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


std::string Ressource::toString() const {
    return "Ressource [" + type + "] ID=" + id + ", Disponible=" + (disponible ? "Oui" : "Non");
}


std::string Ressource::genererRequeteSQL() const {
    return "INSERT INTO ressources (id, disponible) VALUES ('" + id + "', " + (disponible ? "1" : "0") + ");";
}

std::string Ressource::getType() const {
    return type;
}
