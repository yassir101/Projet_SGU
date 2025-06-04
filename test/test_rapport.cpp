#include <iostream>
#include <cassert>
#include "../include/Rapport.hpp"

int main() {
    Rapport r;
    r.setContenu("Analyse des interventions du mois de mai");

    assert(r.getContenu() == "Analyse des interventions du mois de mai");

    r.exporterCSV();  // Devrait afficher le contenu
    r.exporterPDF();  // Devrait afficher le contenu

    std::cout << "[OK] test_rapport" << std::endl;
    return 0;
}
