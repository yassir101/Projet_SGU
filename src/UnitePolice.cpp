#include "../include/UnitePolice.hpp"

UnitePolice::UnitePolice(const std::string& id, int nbAgents)
    : Ressource(id), nbAgentsDisponibles(nbAgents) {}

void UnitePolice::affecter() {
    if (nbAgentsDisponibles == 0) {
        throw std::runtime_error("Aucun agent disponible");
    }
    Ressource::affecter();
}

void UnitePolice::liberer() {
    Ressource::liberer();
}

void UnitePolice::deplacerAgents() {
    if (nbAgentsDisponibles > 0) {
        nbAgentsDisponibles--;
    }
}

void UnitePolice::evacuerZone() {
    // Implémentation spécifique d'évacuation
}

int UnitePolice::getNbAgentsDisponibles() const {
    return nbAgentsDisponibles;
}
