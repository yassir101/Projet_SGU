#include "StockRessources.hpp"

StockRessources::StockRessources(const std::string& idIntervention, const std::string& debut, const std::string& idRessource) 
    : Ressource(idIntervention, debut, idRessource) {}

StockRessources::~StockRessources() {
    for (auto r : ressourcesDisponibles) {
        delete r;
    }
}

void StockRessources::mettreAJourDisponibilite() {
    // Logique fictive : vérifier si des ressources peuvent être libérées
    for (auto r : ressourcesDisponibles) {
        if (!r->estDisponible()) {
            // Exemple : libérer après un certain temps (logique à affiner)
            r->liberer();
        }
    }
}

bool StockRessources::verifierDisponibilite(const std::string& dest) {
    // Vérifie si une ressource est disponible pour cet utilisateur
    for (auto r : ressourcesDisponibles) {
        if (r->estDisponible()) {
            return true;
        }
    }
    return false;
}