#include "../include/Statistiques.hpp"
#include <iostream>
#include <numeric>
#include <sstream>

Statistiques::Statistiques()
    : total(0), graviteMoyenne(0.0) {}

void Statistiques::calculer(const std::vector<Intervention>& historique) {
    total = historique.size();
    parType.clear();
    parStatut.clear();
    double sommeGravite = 0;

    for (const auto& interv : historique) {
        if (auto urgence = interv.getUrgence()) {
            parType[urgence->getTypeUrgence()]++;
            sommeGravite += urgence->getNiveauGravite();
        }

        parStatut[interv.getStatut()]++;
    }

    graviteMoyenne = (total > 0) ? sommeGravite / total : 0.0;

    std::cout << "[Statistiques] Calcul terminé — " << total << " interventions." << std::endl;
}

std::string Statistiques::toString() const {
    std::ostringstream oss;
    oss << "=== Statistiques SGU ===\n";
    oss << "Total interventions : " << total << "\n";
    oss << "Gravité moyenne     : " << graviteMoyenne << "\n";
    oss << "\nPar type :\n";
    for (const auto& [type, count] : parType)
        oss << " - " << type << " : " << count << "\n";
    oss << "\nPar statut :\n";
    for (const auto& [statut, count] : parStatut)
        oss << " - " << statut << " : " << count << "\n";

    return oss.str();
}

// Getters
int Statistiques::getTotal() const { return total; }
double Statistiques::getGraviteMoyenne() const { return graviteMoyenne; }
std::map<std::string, int> Statistiques::getParType() const { return parType; }
std::map<std::string, int> Statistiques::getParStatut() const { return parStatut; }

