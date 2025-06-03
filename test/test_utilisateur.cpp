#include "../include/Administrateur.hpp"
#include <cassert>
#include <iostream>

int main() {
    Administrateur admin("ADM1", "Dupont", 1);

    assert(admin.getId() == "ADM1");
    assert(admin.getNom() == "Dupont");
    assert(admin.getNiveauAcces() == 1);

    admin.setNiveauAcces(2);
    assert(admin.getNiveauAcces() == 2);

    admin.validerIntervention();
    admin.consulterRapport();
    admin.demanderRapport();

    std::cout << "[OK] test_utilisateur.cpp terminé avec succès\n";
    return 0;
}
