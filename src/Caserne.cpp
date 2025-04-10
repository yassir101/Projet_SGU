#include "../include/Caserne.hpp"

Caserne::Caserne(const std::string& id, int nbEquipes)
    : Ressource(id), nbEquipesDisponibles(nbEquipes) {}

void Caserne::affecter() {
    if (nbEquipesDisponibles <= 0) {
        throw std::runtime_error("Aucune équipe disponible");
    }
    Ressource::affecter();
}

void Caserne::liberer() {
    Ressource::liberer();
}

void Caserne::envoyerEquipe() {
    if (nbEquipesDisponibles > 0) {
        nbEquipesDisponibles--;
    }
}

void Caserne::rappelerEquipe() {
    nbEquipesDisponibles++;
}

int Caserne::getNbEquipesDisponibles() const {
    return nbEquipesDisponibles;
}
