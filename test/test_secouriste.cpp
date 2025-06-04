#include <iostream>
#include "../include/Secouriste.hpp"

int main() {
    std::cout << "=== TEST SECOURISTE ===\n";

    // Création
    Secouriste s("U123", "Martin Dupont", "S456", "Incendie");

    // Test getters
    std::cout << "ID : " << s.getId() << "\n";                  // U123
    std::cout << "Nom : " << s.getNom() << "\n";                // Martin Dupont
    std::cout << "Matricule : " << s.getMatricule() << "\n";    // S456
    std::cout << "Spécialité : " << s.getSpecialite() << "\n";  // Incendie

    // Test setters
    s.setMatricule("S789");
    s.setSpecialite("Médical");
    std::cout << "Nouveau matricule : " << s.getMatricule() << "\n"; // S789
    std::cout << "Nouvelle spécialité : " << s.getSpecialite() << "\n"; // Médical

    // Test méthodes de notification
    s.mettreAJourStatut();           // Affiche message de mise à jour
    s.confirmerIntervention();       // Affiche message de confirmation
    s.transmettrePosition();         // Affiche message de position

    return 0;
}
