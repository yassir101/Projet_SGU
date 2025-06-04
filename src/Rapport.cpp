#include "../include/Rapport.hpp"
#include <iostream>

Rapport::Rapport() : titre("Rapport SGU"), contenu("") {}

Rapport::Rapport(const std::string& titre, const std::string& contenu)
    : titre(titre), contenu(contenu) {}

void Rapport::exporterCSV() const {
    std::cout << "[EXPORT CSV]" << std::endl;
    std::cout << "Titre;Contenu\n" << titre << ";" << contenu << std::endl;
}

void Rapport::exporterPDF() const {
    std::cout << "[EXPORT PDF] - " << titre << std::endl;
    std::cout << contenu << std::endl;
}

std::string Rapport::getContenu() const {
    return contenu;
}

std::string Rapport::getTitre() const {
    return titre;
}

void Rapport::setContenu(const std::string& nouveauContenu) {
    contenu = nouveauContenu;
}

void Rapport::setTitre(const std::string& nouveauTitre) {
    titre = nouveauTitre;
}

std::string Rapport::toString() const {
    return "=== " + titre + " ===\n" + contenu + "\n";
}

