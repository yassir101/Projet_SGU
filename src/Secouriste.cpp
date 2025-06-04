#include "../include/Secouriste.hpp"

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

std::string Secouriste::getTypeUtilisateur() const {
    return "Secouriste";
}

std::string Secouriste::toString() const {
    return "[Secouriste] Nom=" + nom + ", Matricule=" + matricule + ", Spécialité=" + specialite;
}

std::string Secouriste::genererRequeteSQL() const {
    return "INSERT INTO secouristes (id, nom, matricule, specialite) VALUES ('"
        + id + "', '" + nom + "', '" + matricule + "', '" + specialite + "');";
}

