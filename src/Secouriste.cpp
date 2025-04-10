#include "Secouriste.hpp"

Secouriste::Secouriste(const std::string& id, const std::string& nom,
                       const std::string& matricule, const std::string& specialite)
    : Utilisateur(id, nom), matricule(matricule), specialite(specialite) {}

void Secouriste::mettreAJourStatut() const {
    std::cout << "[Secouriste] " << nom << " met à jour le statut de l’intervention." << std::endl;
}

void Secouriste::confirmerIntervention() const {
    std::cout << "[Secouriste] " << nom << " confirme la prise en charge de l’intervention." << std::endl;
}

void Secouriste::transmettrePosition() const {
    std::cout << "[Secouriste] " << nom << " transmet sa position actuelle." << std::endl;
}

std::string Secouriste::getMatricule() const {
    return matricule;
}

void Secouriste::setMatricule(const std::string& m) {
    matricule = m;
}

std::string Secouriste::getSpecialite() const {
    return specialite;
}

void Secouriste::setSpecialite(const std::string& s) {
    specialite = s;
}
