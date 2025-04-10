#include "Demandeur.hpp"
#include <iostream>

Demandeur::Demandeur(const std::string& id, const std::string& nom, const std::string& tel)
    : Utilisateur(id, nom), telephone(tel) {}

void Demandeur::signalerUrgence() const {
    std::cout << "[Demandeur] " << nom << " signale une urgence." << std::endl;
}

void Demandeur::repondreQuestionnaire(QuestionnaireUrgence& questionnaire) const {
    std::cout << "[Demandeur] " << nom << " commence à remplir le questionnaire..." << std::endl;
    questionnaire.remplir();  // Méthode gérée par QuestionnaireUrgence
}

std::string Demandeur::getTelephone() const {
    return telephone;
}

void Demandeur::setTelephone(const std::string& tel) {
    telephone = tel;
}
