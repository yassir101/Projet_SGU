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
            // Ici on pourrait affiner la vérif sur le type si besoin
            return res->getType() == typeRessource && res->estDisponible();
        });
}

std::shared_ptr<Intervention> AllocateurRessources::affecter(std::shared_ptr<Urgence> urgence) {
    std::cout << "[Allocation] Affectation en cours pour l'urgence ID " << urgence->getIdUrgence() << std::endl;

    // Chercher la première ressource disponible adaptée
    for (auto& res : ressources) {
        if (res->estDisponible()) {
            auto& equipe = res->getEquipeSecouristes();
            if (!equipe.empty()) {
                auto secouriste = equipe.front();

                // Mobiliser ce secouriste
                res->retirerSecouriste(secouriste->getId());
                std::cout << " - Ressource mobilisée : " << res->getIdRessource()
                          << " (secouriste " << secouriste->getNom() << " mobilisé)" << std::endl;

                // Créer l’intervention
                auto intervention = creerIntervention(urgence);
                // On pourrait ici ajouter le secouriste à l’intervention, si la classe gère ça

                return intervention;
            } else {
                std::cout << " - Ressource " << res->getIdRessource() << " sans secouriste disponible!" << std::endl;
            }
        }
    }

    std::cerr << "[Allocation] Aucune ressource disponible pour l'urgence " << urgence->getIdUrgence() << std::endl;
    return nullptr;
}

void AllocateurRessources::declencherAffectation() {
    // Optionnel, ou à implémenter avec un algorithme plus complet plus tard
    std::cout << "[Allocation] Algorithme de dispatching des ressources non implémenté." << std::endl;
}

void AllocateurRessources::libererSecouriste(const std::string& idRessource, std::shared_ptr<Secouriste> secouriste) {
    for (auto& res : ressources) {
        if (res->getIdRessource() == idRessource) {
            res->ajouterSecouriste(secouriste);
            // Mise à jour de la disponibilité faite dans Ressource::ajouterSecouriste
            std::cout << "[Allocation] Secouriste " << secouriste->getNom() << " libéré dans la ressource " << idRessource << std::endl;
            break;
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
    std::string id = "INT-" + std::to_string(rand() % 1000); // idéalement UUID
    return std::make_shared<Intervention>(id, urgence);
}

