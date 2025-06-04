#include "../include/JournalSysteme.hpp"
#include <iostream>

JournalSysteme::JournalSysteme() {}

void JournalSysteme::enregistrerEvenement(const std::string& evenement) {
    journal.push_back(evenement);
}

void JournalSysteme::afficherJournal() const {
    std::cout << "=== Journal du système ===" << std::endl;
    for (const auto& e : journal) {
        std::cout << "- " << e << std::endl;
    }
}

void JournalSysteme::logAnnulation(const Intervention& i) {
    std::string ligne = "Intervention " + i.getId() + " annulée. Statut: " + i.getStatut();
    journal.push_back(ligne);
}
