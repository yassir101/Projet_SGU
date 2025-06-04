#include "../include/UnitePolice.hpp"
#include <stdexcept>
#include <iostream>

UnitePolice::UnitePolice(const std::string& id, int nbAgents)
    : Ressource(id, "UnitePolice"), nbAgentsDisponibles(nbAgents) {}

void UnitePolice::affecter() {
    if (nbAgentsDisponibles <= 0) {
        throw std::runtime_error("Aucun agent disponible pour l’unité " + id);
    }
    nbAgentsDisponibles--;
    Ressource::affecter();
}

void UnitePolice::liberer() {
    nbAgentsDisponibles++;
    Ressource::liberer();
}

void UnitePolice::deplacerAgents() {
    if (nbAgentsDisponibles > 0) {
        nbAgentsDisponibles--;
        std::cout << "[UnitePolice] Agents déployés sur le terrain depuis l’unité " << id << "." << std::endl;
    } else {
        std::cout << "[UnitePolice] Aucun agent à déployer." << std::endl;
    }
}

void UnitePolice::evacuerZone() {
    std::cout << "[UnitePolice] Intervention en cours : évacuation de la zone par l’unité " << id << "." << std::endl;
}

int UnitePolice::getNbAgentsDisponibles() const {
    return nbAgentsDisponibles;
}

std::string UnitePolice::genererRequeteSQL() const {
    return "INSERT INTO unite_police (id, nb_agents, disponible) VALUES ('" + id + "', " 
        + std::to_string(nbAgentsDisponibles) + ", " + (estDisponible() ? "1" : "0") + ");";
}

std::string UnitePolice::getType() const {
    return "UnitePolice";
}

