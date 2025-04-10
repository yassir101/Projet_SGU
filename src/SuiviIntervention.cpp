#include "../include/SuiviIntervention.hpp"

SuiviIntervention::SuiviIntervention(std::shared_ptr<Intervention> intervention)
    : intervention(intervention), statut("initialisé") {}

void SuiviIntervention::mettreAJour(const std::string& position, const std::string& statut) {
    positionActuelle = position;
    this->statut = statut;
}

void SuiviIntervention::envoyerNotification() {
    if (auto interv = intervention.lock()) {
        // Implémenter la notification
    }
}

// Getters
std::string SuiviIntervention::getPositionActuelle() const { return positionActuelle; }
std::string SuiviIntervention::getStatut() const { return statut; }
std::shared_ptr<Intervention> SuiviIntervention::getIntervention() const { return intervention.lock(); }
