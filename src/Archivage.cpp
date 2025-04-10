#include "Archivage.hpp"

// Archive une intervention terminée
void Archivage::archiver(const Intervention& interv) {
    // à implémenter
}

// Recherche des interventions selon des filtres
std::vector<Intervention> Archivage::rechercher(const std::map<std::string, std::string>& filtres) {
    // à implémenter
    return {};
}

// Génère les statistiques sur les interventions archivées
Statistiques Archivage::genererStatistiques() {
    // à implémenter
    return Statistiques();
}

// Génère un rapport basé sur l’historique
Rapport Archivage::genererRapport() {
    // à implémenter
    return Rapport();
}

const std::vector<Intervention>& Archivage::getHistoriques() const {
    return historiques;
}

