#include "../include/Statistiques.hpp"

// Constructeur par défaut
Statistiques::Statistiques() : total(0) {}

// Lance le calcul des statistiques
void Statistiques::calculer() {
    // Calcul à implémenter
}

// Getter du total
int Statistiques::getTotal() const {
    return total;
}

// Setter du total
void Statistiques::setTotal(int nouveauTotal) {
    total = nouveauTotal;
}

