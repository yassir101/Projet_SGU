#include "../include/Intervention.hpp"
#include "../include/Urgence.hpp"
#include "../include/Ressource.hpp"
#include <iostream>
#include <memory>
#include <cassert>

// Classe de test pour Urgence
class UrgenceTest : public Urgence {
public:
    UrgenceTest(const std::string& id, const std::string& type, const std::string& loc, int grav)
        : Urgence(id, type, loc, grav) {}

    int evaluerPriorite() const override {
        return getNiveauGravite();
    }
};

// Classe de test pour Ressource
class RessourceTest : public Ressource {
public:
    RessourceTest(const std::string& id) : Ressource(id) {}

    void affecter() override { disponible = false; }
    void liberer() override { disponible = true; }
};

int main() {
    auto urgence = std::make_shared<UrgenceTest>("U1", "Incendie", "Paris", 2);
    auto intervention = std::make_shared<Intervention>("INT1", urgence);

    // Démarrage
    intervention->demarrer();
    assert(intervention->getStatut() == "en cours");

    // Ajout de ressource
    auto ressource = std::make_shared<RessourceTest>("RES1");
    intervention->ajouterRessource(ressource);
    assert(intervention->getRessources().size() == 1);

    // Clôture
    intervention->cloturer();
    assert(intervention->getStatut() == "terminée");

    std::cout << "[OK] test_intervention.cpp terminé avec succès\n";
    return 0;
}
