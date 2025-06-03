#include "../include/Accident.hpp"
#include <cassert>
#include <iostream>

void test_mettreAJourStatut() {
    Accident a("U01", "Accident", "Rue des Lilas", 2, 3);
    assert(a.getStatut() == "en attente");

    a.mettreAJourStatut();
    assert(a.getStatut() == "en cours");

    a.mettreAJourStatut();
    assert(a.getStatut() == "terminée");

    std::cout << "test_mettreAJourStatut passé" << std::endl;
}
