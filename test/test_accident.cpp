#include "../include/Accident.hpp"
#include <cassert>
#include <iostream>

int main() {
    Accident accident("A1", "Accident", "Lyon", 3, 4);

    assert(accident.getId() == "A1");
    assert(accident.getLocalisation() == "Lyon");
    assert(accident.getType() == "Accident");
    assert(accident.evaluerPriorite() == 4); // Gravité 3 + nbVehicules > 3

    accident.mettreAJourStatut();
    assert(accident.getStatut() == "en cours");
    accident.mettreAJourStatut();
    assert(accident.getStatut() == "terminée");

    std::cout << "[OK] test_accident.cpp terminé avec succès\n";
    return 0;
}
