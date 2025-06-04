#include <iostream>
#include <cassert>
#include <memory>
#include "../include/StockRessources.hpp"
#include "../include/Caserne.hpp" // ou tout type concret de Ressource

int main() {
    StockRessources stock("STOCK001");

    auto caserne1 = std::make_shared<Caserne>("CAS001", 2);
    auto caserne2 = std::make_shared<Caserne>("CAS002", 0); // vide

    stock.ajouterRessource(caserne1);
    stock.ajouterRessource(caserne2);

    assert(stock.verifierDisponibilite("pompiers"));
    caserne1->affecter(); // rend indispo
    stock.mettreAJourDisponibilite(); // remet à dispo
    assert(caserne1->estDisponible());

    std::cout << "[OK] test_stockressources\n";
    return 0;
}
