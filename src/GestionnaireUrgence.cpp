#include "../include/GestionnaireUrgence.hpp"

// Constructeur par défaut du gestionnaire
GestionnaireUrgence::GestionnaireUrgence()
    : journal(std::make_shared<JournalSysteme>()),
      allocateur(std::make_shared<AllocateurRessources>()) {}

// Analyse les informations reçues sur une urgence
void GestionnaireUrgence::analyserUrgence() {
    // à implémenter
}

// Enregistre une nouvelle urgence dans le système
void GestionnaireUrgence::enregistrerUrgence() {
    // à implémenter
}

// Classe les urgences selon leur priorité
void GestionnaireUrgence::prioriser() {
    // à implémenter
}

// Envoie des notifications aux acteurs concernés
void GestionnaireUrgence::notifier() {
    // à implémenter
}

// Synchronise les données avec d’autres systèmes
void GestionnaireUrgence::synchroniserDonneesExternes() {
    // à implémenter
}

