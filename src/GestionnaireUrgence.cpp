#include "../include/GestionnaireUrgence.hpp"
#include <iostream>
#include <algorithm>
GestionnaireUrgence::GestionnaireUrgence()
    : journal(std::make_shared<JournalSysteme>()),
      allocateur(std::make_shared<AllocateurRessources>()) {}

// Analyse une urgence
void GestionnaireUrgence::analyserUrgence(const std::shared_ptr<Urgence>& urgence) {
    journal->enregistrerEvenement("Analyse de l'urgence : " + urgence->toString());
}

// Enregistre une urgence
void GestionnaireUrgence::enregistrerUrgence(const std::shared_ptr<Urgence>& urgence) {
    urgences.push_back(urgence);
    journal->enregistrerEvenement("Enregistrement de l'urgence : " + urgence->toString());
}

// Calcule la priorité d'une urgence
int GestionnaireUrgence::calculerPriorite(const std::shared_ptr<Urgence>& urgence) const {
    return urgence->evaluerPriorite();
}

// Trie les urgences par priorité décroissante
void GestionnaireUrgence::prioriser() {
    std::sort(urgences.begin(), urgences.end(),
              [](const std::shared_ptr<Urgence>& a, const std::shared_ptr<Urgence>& b) {
                  return a->getPriorite() > b->getPriorite();
              });
    journal->enregistrerEvenement("Tri des urgences selon leur priorité effectué.");
}

// Notifie le demandeur
void GestionnaireUrgence::notifier(const std::shared_ptr<Urgence>& urgence) {
    Notification notification("Une urgence de type " + urgence->getTypeUrgence() +
                              " a été détectée à " + urgence->getLocalisation() +
                              ". Gravité : " + std::to_string(urgence->getNiveauGravite()));
    
    // Exemple d'envoi générique (sans destinataire réel)
    std::cout << "[NOTIFICATION] → Message : " << notification.getMessage() << std::endl;

    journal->enregistrerEvenement("Notification envoyée pour l'urgence : " + urgence->getIdUrgence());
}

// Synchronisation (placeholder)
void GestionnaireUrgence::synchroniserDonneesExternes() {
    journal->enregistrerEvenement("Synchronisation avec les systèmes externes.");
}

