#include <iostream>
#include <cassert>
#include "../include/Demandeur.hpp"
#include "../include/QuestionnaireUrgence.hpp"

// Test de get/set Telephone
void testTelephone() {
    Demandeur d("D001", "Alice", "0612345678");
    assert(d.getTelephone() == "0612345678");

    d.setTelephone("0600000000");
    assert(d.getTelephone() == "0600000000");

    std::cout << "[OK] testTelephone" << std::endl;
}

// Test de signalerUrgence (vérifie juste que ça compile et affiche)
void testSignalerUrgence() {
    Demandeur d("D002", "Bob", "0699999999");
    d.signalerUrgence();  // Doit afficher une ligne d’information

    std::cout << "[OK] testSignalerUrgence" << std::endl;
}

// Test du remplissage de questionnaire (simulation manuelle sans cin)
void testQuestionnaireReponses() {
    QuestionnaireUrgence q;
    q.genererQuestions();

    // simulateur manuel
    q.completerInformations("Quel est le type d'urgence ?", "Incendie");
    q.completerInformations("Quelle est la localisation ?", "Nord");
    q.completerInformations("Combien de personnes sont impliquées ?", "2 à 5");
    q.completerInformations("Y a-t-il des blessés ?", "Oui");
    q.completerInformations("Quel est le niveau de gravité ?", "Modérée");

    q.setComplet(true);
    assert(q.validerReponses());
    assert(q.estComplet());

    std::cout << "[OK] testQuestionnaireReponses" << std::endl;
}

int main() {
    testTelephone();
    testSignalerUrgence();
    testQuestionnaireReponses();

    std::cout << "Tous les tests sur Demandeur + QuestionnaireUrgence passent ✔" << std::endl;
    return 0;
}
