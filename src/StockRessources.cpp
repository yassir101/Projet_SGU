#include "StockRessources.hpp"

StockRessources::StockRessources() {}

StockRessources::~StockRessources() {
    for (auto r : ressources) {
        delete r;
    }
}

void StockRessources::ajouterRessource(Ressource* r) {
    ressources.push_back(r);
}

Ressource* StockRessources::trouverRessourceDisponible(const std::string& type) {
    for (auto r : ressources) {
        if (r->typeRessource() == type && r->estDisponible()) {
            return r;
        }
    }
    return nullptr;
}