#include "../include/Rapport.hpp"
#include <iostream>

Rapport::Rapport() : contenu("") {}

void Rapport::exporterCSV() {
    std::cout << "[Export CSV] Contenu : " << contenu << std::endl;
}

void Rapport::exporterPDF() {
    std::cout << "[Export PDF] Contenu : " << contenu << std::endl;
}

std::string Rapport::getContenu() const {
    return contenu;
}

void Rapport::setContenu(const std::string& nouveauContenu) {
    contenu = nouveauContenu;
}
