#include "GestionnaireUtilisateurs.hpp"

// Ajout
void GestionnaireUtilisateurs::ajouterAdministrateur(std::shared_ptr<Administrateur> admin) {
    administrateurs.push_back(admin);
}

void GestionnaireUtilisateurs::ajouterSecouriste(std::shared_ptr<Secouriste> sec) {
    secouristes.push_back(sec);
}

void GestionnaireUtilisateurs::ajouterDemandeur(std::shared_ptr<Demandeur> demandeur) {
    demandeurs.push_back(demandeur);
}

// Recherche d’un admin libre
std::shared_ptr<Administrateur> GestionnaireUtilisateurs::trouverAdministrateurLibre() const {
    for (auto& admin : administrateurs) {
        if (admin->estDisponible()) return admin;
    }
    return nullptr;
}

// Recherche d’un secouriste libre
std::shared_ptr<Secouriste> GestionnaireUtilisateurs::trouverSecouristeLibre() const {
    for (auto& sec : secouristes) {
        if (sec->estDisponible()) return sec;
    }
    return nullptr;
}

// Getters
const std::vector<std::shared_ptr<Administrateur>>& GestionnaireUtilisateurs::getAdministrateurs() const {
    return administrateurs;
}

const std::vector<std::shared_ptr<Secouriste>>& GestionnaireUtilisateurs::getSecouristes() const {
    return secouristes;
}

const std::vector<std::shared_ptr<Demandeur>>& GestionnaireUtilisateurs::getDemandeurs() const {
    return demandeurs;
}

