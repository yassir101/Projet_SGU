#include <iostream>
#include <cassert>
#include <memory>
#include "../include/SuiviIntervention.hpp"
#include "../include/UrgenceMedicale.hpp"
#include "../include/Intervention.hpp"

int main() {
    auto urgence = std::make_shared<UrgenceMedicale>("U0001", "Urgence médicale", "Lyon", 3, 5);
    auto intervention = std::make_shared<Intervention>("INT001", urgence);
    
    SuiviIntervention suivi(intervention);
    suivi.mettreAJour("45.76, 4.84", "En route");

    assert(suivi.getPositionActuelle() == "45.76, 4.84");
    assert(suivi.getStatut() == "En route");
    assert(suivi.getIntervention()->getId() == "INT001");

    suivi.envoyerNotification();

    std::cout << "[OK] test_suivi_intervention" << std::endl;
    return 0;
}
