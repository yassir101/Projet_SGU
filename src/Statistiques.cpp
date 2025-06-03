#include "../include/Statistiques.hpp"
#include <iostream>

// Constructeur par défaut
Statistiques::Statistiques() : total(0) {}

// Lance le calcul des statistiques
void Statistiques::calculer() {
    // Simulation d'un traitement : ici on incrémente simplement pour illustrer
    std::cout << "[Statistiques] Calcul des interventions archivées...\n";
    total += 5; // Simule l'ajout de 5 nouvelles interventions archivées
    std::cout << "[Statistiques] Total mis à jour : " << total << std::endl;
}

// Getter du total
int Statistiques::getTotal() const {
    return total;
}

// Setter du total
void Statistiques::setTotal(int nouveauTotal) {
    total = nouveauTotal;
}
