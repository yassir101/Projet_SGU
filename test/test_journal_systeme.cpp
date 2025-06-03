#include <iostream>
#include <cassert>
#include "../include/JournalSysteme.hpp"
#include "../include/UrgenceMedicale.hpp"
#include "../include/Intervention.hpp"

void testJournalSimple() {
    JournalSysteme js;
    js.enregistrerEvenement("Démarrage du système");
    js.enregistrerEvenement("Nouvelle urgence enregistrée");

    js.afficherJournal();
    std::cout << "[OK] testJournalSimple" << std::endl;
}

void testLogAnnulation() {
    auto urgence = std::make_shared<UrgenceMedicale>("U001", "Urgence médicale", "Paris", 2, 3);
    Intervention inter("INT123", urgence);
    inter.annuler("Test d’annulation");

    JournalSysteme js;
    js.logAnnulation(inter);
    js.afficherJournal();

    std::cout << "[OK] testLogAnnulation" << std::endl;
}

int main() {
    testJournalSimple();
    testLogAnnulation();

    std::cout << "Tous les tests JournalSysteme passent" << std::endl;
    return 0;
}
