#include "Administrateur.hpp"

Administrateur::Administrateur(const std::string& id, const std::string& nom, int niveauAcces)
    : Utilisateur(id, nom), niveauAcces(niveauAcces) {}

void Administrateur::validerIntervention() const {
    std::cout << "[Administrateur] " << nom << " valide une intervention en attente." << std::endl;
}

void Administrateur::consulterRapport() const {
    std::cout << "[Administrateur] " << nom << " consulte un rapport généré." << std::endl;
}

void Administrateur::demanderRapport() const {
    std::cout << "[Administrateur] " << nom << " demande la génération d’un nouveau rapport." << std::endl;
}

int Administrateur::getNiveauAcces() const {
    return niveauAcces;
}

void Administrateur::setNiveauAcces(int niveau) {
    niveauAcces = niveau;
}
