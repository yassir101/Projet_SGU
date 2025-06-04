#include "../include/SuiviIntervention.hpp"
#include "../include/Intervention.hpp"
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


std::string SuiviIntervention::toString() const {
    auto interv = intervention.lock();
    return "Suivi de l'intervention " + (interv ? interv->getId() : "inconnue") +
           " — Position : " + positionActuelle + ", Statut : " + statut;
}

std::string SuiviIntervention::genererRequeteSQL() const {
    auto interv = intervention.lock();
    std::string id = interv ? interv->getId() : "NULL";
    return "INSERT INTO suivi_intervention (intervention_id, position, statut) VALUES ('" +
           id + "', '" + positionActuelle + "', '" + statut + "');";
}

void SuiviIntervention::setPositionActuelle(const std::string& pos) {
    positionActuelle = pos;
}

void SuiviIntervention::setStatut(const std::string& st) {
    statut = st;
}

