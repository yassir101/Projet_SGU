#include "Archivage.hpp"
#include <iostream>

void Archivage::archiver(const std::shared_ptr<Intervention>& interv) {
    historiques.push_back(interv);
}

std::vector<std::shared_ptr<Intervention>> Archivage::rechercher(const std::map<std::string, std::string>& filtres) {
    std::vector<std::shared_ptr<Intervention>> resultats;
    for (const auto& interv : historiques) {
        // Exemple : recherche par statut
        if (filtres.count("statut") && interv->getStatut() != filtres.at("statut")) continue;
        resultats.push_back(interv);
    }
    return resultats;
}

Statistiques Archivage::genererStatistiques() {
    Statistiques stats;
    // À implémenter plus tard avec compteur par type ou gravité
    return stats;
}

Rapport Archivage::genererRapport() {
    Rapport rapport;
    // À compléter : exporter les urgences, nb, durée...
    return rapport;
}

void Archivage::afficherHistorique() const {
    std::cout << "=== Historique des interventions ===" << std::endl;
    for (const auto& i : historiques) {
        std::cout << i->toString() << std::endl;
    }
}

const std::vector<std::shared_ptr<Intervention>>& Archivage::getHistoriques() const {
    return historiques;
}

