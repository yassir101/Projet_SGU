#include "InterfaceUtilisateur.hpp"
#include "Accident.hpp"
#include "Incendie.hpp"
#include "UrgenceMedicale.hpp"
#include <cstdlib> // pour rand
#include <ctime>   // pour time

void InterfaceUtilisateur::afficherMenu() const {
    std::cout << "====== MENU SGU ======" << std::endl;
    std::cout << "1. Signaler une urgence" << std::endl;
    std::cout << "2. Quitter" << std::endl;
}

std::unique_ptr<Urgence> InterfaceUtilisateur::collecterUrgence() const {
    std::string type, localisation, graviteTxt;
    int gravite;

    std::cout << "=== Signalement d'une urgence ===" << std::endl;
    std::cout << "Type d'urgence (incendie / accident / médicale) : ";
    std::getline(std::cin, type);

    std::cout << "Localisation exacte : ";
    std::getline(std::cin, localisation);

    std::cout << "Gravité (faible / modérée / critique) : ";
    std::getline(std::cin, graviteTxt);

    if (graviteTxt == "faible") gravite = 1;
    else if (graviteTxt == "modérée") gravite = 2;
    else gravite = 3;

    std::string id = "U" + std::to_string(rand() % 10000);

    if (type == "incendie") {
        std::string typeFeu;
        std::cout << "Type de feu (habitation, forêt, véhicule...) : ";
        std::getline(std::cin, typeFeu);
        return std::make_unique<Incendie>(id, "Incendie", localisation, gravite, typeFeu);
    } 
    else if (type == "accident") {
        int nbVeh;
        std::cout << "Nombre de véhicules impliqués : ";
        std::cin >> nbVeh;
        std::cin.ignore();
        return std::make_unique<Accident>(id, "Accident", localisation, gravite, nbVeh);
    } 
    else {
        int nbVict;
        std::cout << "Nombre de victimes : ";
        std::cin >> nbVict;
        std::cin.ignore();
        return std::make_unique<UrgenceMedicale>(id, "Médicale", localisation, gravite, nbVict);
    }
}


