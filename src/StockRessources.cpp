#include "../include/StockRessources.hpp"

StockRessources::StockRessources(const std::string& id)
    : Ressource(id) {}

StockRessources::~StockRessources() = default;

void StockRessources::ajouterRessource(std::shared_ptr<Ressource> ressource) {
    ressourcesDisponibles.push_back(ressource);
}

void StockRessources::mettreAJourDisponibilite() {
    for (auto& r : ressourcesDisponibles) {
        if (!r->estDisponible()) {
            r->liberer();
        }
    }
}

bool StockRessources::verifierDisponibilite(const std::string& /*type*/) const {
    for (const auto& r : ressourcesDisponibles) {
        if (r->estDisponible()) {
            return true;
        }
    }
    return false;
}

const std::vector<std::shared_ptr<Ressource>>& StockRessources::getRessources() const {
    return ressourcesDisponibles;
}
