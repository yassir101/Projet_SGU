#include "Intervention.hpp"
#include <stdexcept>

Intervention::Intervention(const std::string& id, std::shared_ptr<Urgence> urgence)
    : id(id), urgence(urgence), statut("créée") {
    this->suivi = std::make_shared<SuiviIntervention>(shared_from_this());
}

void Intervention::demarrer() {
    if (statut != "créée") {
        throw std::runtime_error("Intervention déjà démarrée ou terminée");
    }
    statut = "en cours";
    debut = "2023-11-15T10:00:00Z"; // À remplacer par un vrai timestamp
}

void Intervention::cloturer() {
    statut = "terminée";
    fin = "2023-11-15T11:30:00Z"; // À remplacer
}

void Intervention::annuler(const std::string& raison) {
    statut = "annulée";
    raisonAnnulation = raison;
    fin = "2023-11-15T10:15:00Z"; // À remplacer
}

void Intervention::notifierSecouristes() {
    // Implémentation de la notification
}

void Intervention::ajouterRessource(std::shared_ptr<Ressource> ressource) {
    ressources.push_back(ressource);
}

// Getters
std::string Intervention::getId() const { return id; }
std::string Intervention::getStatut() const { return statut; }
std::shared_ptr<Urgence> Intervention::getUrgence() const { return urgence; }
std::shared_ptr<SuiviIntervention> Intervention::getSuivi() const { return suivi; }
const std::vector<std::shared_ptr<Ressource>>& Intervention::getRessources() const { return ressources; }
