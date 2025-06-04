#include "../include/QuestionnaireUrgence.hpp"
#include <iostream>

QuestionnaireUrgence::QuestionnaireUrgence() : complet(false) {}

void QuestionnaireUrgence::genererQuestions() {
    questions = {
        "Quel est le type d'urgence ?",
        "Quelle est la localisation ?",
        "Combien de personnes sont impliquées ?",
        "Y a-t-il des blessés ?",
        "Quel est le niveau de gravité ?"
    };

    choixParQuestion[questions[0]] = { "Incendie", "Accident", "Urgence médicale" };
    choixParQuestion[questions[1]] = { "Nord", "Sud", "Est", "Ouest" };
    choixParQuestion[questions[2]] = { "1", "2 à 5", "Plus de 5" };
    choixParQuestion[questions[3]] = { "Oui", "Non" };
    choixParQuestion[questions[4]] = { "Faible", "Modérée", "Critique" };
}

void QuestionnaireUrgence::remplir() {
    genererQuestions();

    for (const auto& question : questions) {
        std::cout << question << std::endl;

        const auto& choix = choixParQuestion[question];
        for (size_t i = 0; i < choix.size(); ++i) {
            std::cout << "  " << i + 1 << ". " << choix[i] << std::endl;
        }

        int reponseIndex = 0;
        do {
            std::cout << "Votre choix (1-" << choix.size() << "): ";
            std::cin >> reponseIndex;
        } while (reponseIndex < 1 || static_cast<size_t>(reponseIndex) > choix.size());

        std::cin.ignore(); // gestion retour chariot
        reponses[question] = choix[reponseIndex - 1];
    }

    complet = true;
}

bool QuestionnaireUrgence::validerReponses() const {
    return (reponses.size() == questions.size());
}

void QuestionnaireUrgence::completerInformations(const std::string& question, const std::string& reponse) {
    reponses[question] = reponse;
}

void QuestionnaireUrgence::setComplet(bool etat) {
    complet = etat;
}

bool QuestionnaireUrgence::estComplet() const {
    return complet;
}

void QuestionnaireUrgence::transmettreReponses() const {
    std::cout << "\n[SGU] Réponses transmises au système :" << std::endl;
    for (const auto& [question, reponse] : reponses) {
        std::cout << "- " << question << " → " << reponse << std::endl;
    }
}

const std::vector<std::string>& QuestionnaireUrgence::getQuestions() const {
    return questions;
}

