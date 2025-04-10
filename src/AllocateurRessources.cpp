#include "AllocateurRessources.hpp"
#include <algorithm>

AllocateurRessources::AllocateurRessources() {}

void AllocateurRessources::ajouterRessource(std::shared_ptr<Ressource> ressource) {
    ressources.push_back(ressource);
}

bool AllocateurRessources::verifierDisponibilite(const std::string& typeRessource) const {
    return std::any_of(ressources.begin(), ressources.end(),
        [&typeRessource](const auto& res) {
            return res->getId().find(typeRessource) != std::string::npos && res->estDisponible();
        });
}

std::shared_ptr<Intervention> AllocateurRessources::affecter(std::shared_ptr<Urgence> urgence) {
    auto intervention = creerIntervention(urgence);
    declencherAffectation();
    return intervention;
}

void AllocateurRessources::declencherAffectation() {
    // Logique complexe d'affectation
}

bool AllocateurRessources::verifierCompletude(std::shared_ptr<QuestionnaireUrgence> questionnaire) const {
    // Vérifie que le questionnaire est complet
    return true; // Simplifié
}

void AllocateurRessources::demanderInfos(std::shared_ptr<Demandeur> demandeur) {
    // Implémentation de la demande d'informations
}

std::shared_ptr<Intervention> AllocateurRessources::creerIntervention(std::shared_ptr<Urgence> urgence) {
    return std::make_shared<Intervention>("INT-" + std::to_string(rand() % 1000), urgence);
}
