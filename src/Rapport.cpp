#include "../include/Rapport.hpp"

// Constructeur par défaut
Rapport::Rapport() : contenu("") {}

// Exporte le rapport au format CSV
void Rapport::exporterCSV() {
    // Exportation CSV non implémentée pour le moment
}

// Exporte le rapport au format PDF
void Rapport::exporterPDF() {
    // Exportation PDF non implémentée pour le moment
}

// Getter du contenu
std::string Rapport::getContenu() const {
    return contenu;
}

// Setter du contenu
void Rapport::setContenu(const std::string& nouveauContenu) {
    contenu = nouveauContenu;
}

