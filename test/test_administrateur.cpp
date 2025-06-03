#include "../include/Administrateur.hpp"
#include <cassert>
#include <iostream>

int main() {
    Administrateur admin("ADM1", "Alice", 1);

    assert(admin.getId() == "ADM1");
    assert(admin.getNom() == "Alice");
    assert(admin.getNiveauAcces() == 1);

    admin.validerIntervention();
    admin.demanderRapport();
    admin.consulterRapport();

    admin.setNiveauAcces(2);
    assert(admin.getNiveauAcces() == 2);

    std::cout << "[OK] test_administrateur.cpp terminé avec succès\n";
    return 0;
}
