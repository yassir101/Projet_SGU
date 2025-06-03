#include <iostream>
#include "../include/CentreMedical.hpp"

int main() {
    std::cout << "=== TEST CENTRE MEDICAL ===\n";

    // Création du centre avec 2 lits disponibles
    CentreMedical cm("CM001", 2);

    std::cout << "ID ressource : " << cm.getIdRessource() << "\n";
    std::cout << "Lits disponibles (attendu 2) : " << cm.getLitsDisponibles() << "\n";

    // Affectation d’un lit
    cm.affecterLit();
    std::cout << "Lits disponibles après affectation (attendu 1) : " << cm.getLitsDisponibles() << "\n";

    // Libération d’un lit
    cm.libererLit();
    std::cout << "Lits disponibles après libération (attendu 2) : " << cm.getLitsDisponibles() << "\n";

    // Test de la méthode affecter héritée
    try {
        cm.affecter();
        std::cout << "Affectation réussie\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Erreur : " << e.what() << "\n";
    }

    // Test de la méthode liberer
    cm.liberer();
    std::cout << "Libération réussie (état disponible)\n";

    return 0;
}