#include "../include/StockRessources.hpp"
#include <iostream>
#include <sstream>

StockRessources::StockRessources(const std::string& id)
    : Ressource(id, "Stock") {}

StockRessources::~StockRessources() = default;

void StockRessources::ajouterRessource(std::shared_ptr<Ressource> ressource) {
    ressourcesDisponibles.push_back(ressource);
}

void StockRessources::mettreAJourDisponibilite() {
    for (auto& r : ressourcesDisponibles) {
        // Actualiser disponibilité selon équipe secouristes dans chaque ressource
        if (!r->estDisponible()) {
            std::cout << "[MAJ] Ressource " << r->getIdRessource() << " indisponible.\n";
        }
    }
}

bool StockRessources::verifierDisponibilite(const std::string& type) const {
    for (const auto& r : ressourcesDisponibles) {
        if (r->getType() == type && r->estDisponible()) {
            return true;
        }
    }
    return false;
}

const std::vector<std::shared_ptr<Ressource>>& StockRessources::getRessources() const {
    return ressourcesDisponibles;
}

std::string StockRessources::toString() const {
    std::ostringstream oss;
    oss << "Stock[" << getIdRessource() << "] contient " << ressourcesDisponibles.size() << " ressources :\n";
    for (const auto& r : ressourcesDisponibles) {
        oss << " - " << r->getType() << " (" << r->getIdRessource() << ") "
            << (r->estDisponible() ? "[Disponible]" : "[Indisponible]") << "\n";
    }
    return oss.str();
}

std::string StockRessources::genererRequeteSQL() const {
    std::ostringstream oss;
    for (const auto& r : ressourcesDisponibles) {
        oss << "INSERT INTO stock_ressources (stock_id, ressource_id) VALUES ('"
            << getIdRessource() << "', '" << r->getIdRessource() << "');\n";
    }
    return oss.str();
}

