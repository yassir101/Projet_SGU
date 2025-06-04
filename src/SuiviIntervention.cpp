#include "../include/SuiviIntervention.hpp"
#include <iostream>

SuiviIntervention::SuiviIntervention(std::shared_ptr<Intervention> intervention)
    : intervention(intervention), statut("initialisé") {}

void SuiviIntervention::mettreAJour(const std::string& position, const std::string& statut) {
    this->positionActuelle = position;
    this->statut = statut;
}

void SuiviIntervention::envoyerNotification() {
    if (auto interv = intervention.lock()) {
        std::cout << "Notification : mise à jour de l’intervention " << interv->getId()
                  << " — Position : " << positionActuelle << ", Statut : " << statut << std::endl;
    }
}

std::string SuiviIntervention::getPositionActuelle() const {
    return positionActuelle;
}

std::string SuiviIntervention::getStatut() const {
    return statut;
}

std::shared_ptr<Intervention> SuiviIntervention::getIntervention() const {
    return intervention.lock();
}
