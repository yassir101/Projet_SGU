#include <iostream>
#include <memory>
#include "../include/Demandeur.hpp"
#include "../include/Secouriste.hpp"
#include "../include/Administrateur.hpp"
#include "../include/Urgence.hpp"
#include "../include/Accident.hpp"
#include "../include/Intervention.hpp"
#include "../include/JournalSysteme.hpp"
#include "../include/Notification.hpp"
#include "../include/QuestionnaireUrgence.hpp"
#include "../include/AllocateurRessources.hpp"
#include "../include/GestionnaireBDD.hpp"
#include "../include/GestionnaireUrgence.hpp"
#include "../include/Rapport.hpp"

int main() {
    std::cout << "=== Simulation du Système de Gestion des Urgences (SGU) ===\n";

    // Initialisation de la base de données
    GestionnaireBDD gestionnaireBDD("sgu.db");
    gestionnaireBDD.initialiserTables();

    // Création d’utilisateurs
    auto demandeur = std::make_shared<Demandeur>("U001", "Alice", "123456789");
    auto secouriste = std::make_shared<Secouriste>("S001", "Bob", "M123", "Médical");
    auto admin = std::make_shared<Administrateur>("A001", "Clara", 1);

    gestionnaireBDD.insererUtilisateur(*demandeur);
    gestionnaireBDD.insererUtilisateur(*secouriste);
    gestionnaireBDD.insererUtilisateur(*admin);

    // Création et remplissage du questionnaire
    auto questionnaire = std::make_shared<QuestionnaireUrgence>();
    questionnaire->remplir();

    // Création d'une urgence
    auto urgence = std::make_shared<Accident>("UR001", "Accident", "Centre-ville", 2, 4);
    gestionnaireBDD.insererUrgence(*urgence);

    // Allocation de ressources
    AllocateurRessources allocateur;
    auto intervention = allocateur.affecter(urgence);

    // Gestion d’intervention
    if (intervention) {
        intervention->demarrer();
        CentreMedical centre("R001", 2); 
        gestionnaireBDD.insererRessource(centre);
        intervention->notifierSecouristes();
        intervention->cloturer();
        gestionnaireBDD.insererIntervention(*intervention);
    }

    // Journalisation
    JournalSysteme journal;
    journal.enregistrerEvenement("Simulation terminée");
    journal.afficherJournal();

    // Génération de rapport
    Rapport rapport;
    rapport.setContenu("Résumé de l'intervention " + intervention->getId());
    gestionnaireBDD.exporterRapport(rapport);

    std::cout << "=== Fin de la simulation SGU ===\n";
    return 0;
}

