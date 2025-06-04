#include "../include/Caserne.hpp"
#include <iostream>
#include <stdexcept>

Caserne::Caserne(const std::string& id, int nbEquipes)
    : Ressource(id, "Caserne"), nbEquipesDisponibles(nbEquipes) {}

void Caserne::affecter() {
    if (nbEquipesDisponibles <= 0) {
        throw std::runtime_error("Aucune équipe disponible à la caserne " + id);
    }
    nbEquipesDisponibles--;
    disponible = (nbEquipesDisponibles > 0);
    std::cout << "[Caserne] Équipe envoyée depuis " << id << ", reste : " << nbEquipesDisponibles << std::endl;
}

void Caserne::liberer() {
    nbEquipesDisponibles++;
    disponible = true;
    std::cout << "[Caserne] Équipe revenue à la caserne " << id << std::endl;
}

void Caserne::envoyerEquipe() {
    affecter(); // Même logique
}

void Caserne::rappelerEquipe() {
    liberer(); // Même logique
}

std::string Caserne::getType() const {
    return "Caserne";
}
int Caserne::getNbEquipesDisponibles() const {
    return nbEquipesDisponibles;
}

std::string Caserne::genererRequeteSQL() const {
    return "INSERT INTO casernes (id, nb_equipes, disponible) VALUES ('" + id + "', " +
           std::to_string(nbEquipesDisponibles) + ", " + (disponible ? "1" : "0") + ");";
}

