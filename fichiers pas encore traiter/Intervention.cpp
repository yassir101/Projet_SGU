#include "../include/Intervention.hpp"
#include "../include/SuiviIntervention.hpp"
#include <stdexcept>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

static std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::gmtime(&time);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%SZ");
    return oss.str();
}

Intervention::Intervention(const std::string& id, std::shared_ptr<Urgence> urgence)
    : id(id), urgence(urgence), statut("créée") {}

void Intervention::demarrer() {
    if (statut != "créée") {
        throw std::runtime_error("L'intervention ne peut être démarrée qu'une seule fois.");
    }
    statut = "en cours";
    debut = getCurrentTimestamp();
    suivi = std::make_shared<SuiviIntervention>(shared_from_this());
}

void Intervention::cloturer() {
    if (statut != "en cours") {
        throw std::runtime_error("Seule une intervention en cours peut être clôturée.");
    }
    statut = "terminée";
    fin = getCurrentTimestamp();
}

void Intervention::annuler(const std::string& raison) {
    if (statut == "terminée") {
        throw std::runtime_error("Impossible d'annuler une intervention déjà terminée.");
    }
    statut = "annulée";
    raisonAnnulation = raison;
    fin = getCurrentTimestamp();
}

void Intervention::notifierSecouristes() {
    for (const auto& ressource : ressources) {
        std::cout << "Notification envoyée à la ressource : " << ressource->getIdRessource() << std::endl;
    }
}

void Intervention::ajouterRessource(std::shared_ptr<Ressource> ressource) {
    ressources.push_back(ressource);
}

std::string Intervention::getId() const {
    return id;
}

std::string Intervention::getStatut() const {
    return statut;
}

std::shared_ptr<Urgence> Intervention::getUrgence() const {
    return urgence;
}

std::shared_ptr<SuiviIntervention> Intervention::getSuivi() const {
    return suivi;
}

const std::vector<std::shared_ptr<Ressource>>& Intervention::getRessources() const {
    return ressources;
}
