#include "../include/Caserne.hpp"
#include <cassert>
#include <iostream>

int main() {
    Caserne c("C1", 2);

    assert(c.getIdRessource() == "C1");
    assert(c.getNbEquipesDisponibles() == 2);
    assert(c.estDisponible() == true);

    c.envoyerEquipe();
    assert(c.getNbEquipesDisponibles() == 1);

    c.rappelerEquipe();
    assert(c.getNbEquipesDisponibles() == 2);

    c.affecter();
    assert(c.estDisponible() == false);

    c.liberer();
    assert(c.estDisponible() == true);

    std::cout << "[OK] test_caserne.cpp terminé avec succès\n";
    return 0;
}
