#include "../include/AllocateurRessources.hpp"
#include <algorithm>
#include <iostream>

AllocateurRessources::AllocateurRessources() {}

void AllocateurRessources::ajouterRessource(std::shared_ptr<Ressource> ressource) {
    ressources.push_back(ressource);
}

bool AllocateurRessources::verifierDisponibilite(const std::string& typeRessource) const {
    return std::any_of(ressources.begin(), ressources.end(),
        [&typeRessource](const auto& res) {
            return res->getIdRessource().find(typeRessource) != std::string::npos && res->estDisponible();
        });
}

std::shared_ptr<Intervention> AllocateurRessources::affecter(std::shared_ptr<Urgence> urgence) {
    std::cout << "[Allocation] Affectation en cours pour l'urgence ID " << urgence->getIdUrgence() << std::endl;
    auto intervention = creerIntervention(urgence);
    declencherAffectation();
    return intervention;
}

void AllocateurRessources::declencherAffectation() {
    std::cout << "[Allocation] Simulation d’algorithme de dispatching des ressources." << std::endl;
    for (auto& res : ressources) {
        if (res->estDisponible()) {
            std::cout << " - Ressource mobilisée : " << res->getIdRessource() << std::endl;
            res->affecter();
        }
    }
}

bool AllocateurRessources::verifierCompletude(std::shared_ptr<QuestionnaireUrgence> questionnaire) const {
    return questionnaire && questionnaire->estComplet();
}

void AllocateurRessources::demanderInfos(std::shared_ptr<Demandeur> demandeur) {
    std::cout << "[SGU] Informations manquantes. Contact du demandeur : " << demandeur->getTelephone() << std::endl;
}

std::shared_ptr<Intervention> AllocateurRessources::creerIntervention(std::shared_ptr<Urgence> urgence) {
    std::string id = "INT-" + std::to_string(rand() % 1000); // à remplacer par un générateur UUID
    return std::make_shared<Intervention>(id, urgence);
}

