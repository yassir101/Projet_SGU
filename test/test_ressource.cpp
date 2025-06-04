#include "../include/Ressource.hpp"
#include <cassert>
#include <iostream>

class RessourceTest : public Ressource {
public:
    RessourceTest(const std::string& id) : Ressource(id) {}
    void affecter() override { disponible = false; }
    void liberer() override { disponible = true; }
};

int main() {
    RessourceTest r("R1");

    assert(r.getIdRessource() == "R1");
    assert(r.estDisponible());

    r.affecter();
    assert(!r.estDisponible());

    r.liberer();
    assert(r.estDisponible());

    std::cout << "[OK] test_ressource.cpp terminé avec succès\n";
    return 0;
}
