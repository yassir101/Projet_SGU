#include "../include/Ressource.hpp"
#include <algorithm>

Ressource::Ressource(const std::string& idRessource, const std::string& type)
    : id(idRessource), type(type) {}

std::string Ressource::getIdRessource() const {
    return id;
}

std::string Ressource::getType() const {
    return type;
}

bool Ressource::estDisponible() const {
    for (const auto& sec : equipeSecouristes) {
        if (sec->estDisponible()) {
            return true;
        }
    }
    return false;
}

void Ressource::affecter() {
    for (auto& sec : equipeSecouristes) {
        if (sec->estDisponible()) {
            sec->setEtat(EtatUtilisateur::Occupe);
            return;
        }
    }
}

void Ressource::liberer() {
    for (auto& sec : equipeSecouristes) {
        if (!sec->estDisponible()) {
            sec->setEtat(EtatUtilisateur::Libre);
            return;
        }
    }
}

void Ressource::ajouterSecouriste(std::shared_ptr<Secouriste> sec) {
    equipeSecouristes.push_back(sec);
}

void Ressource::retirerSecouriste(const std::string& idSecouriste) {
    equipeSecouristes.erase(std::remove_if(equipeSecouristes.begin(), equipeSecouristes.end(),
        [&idSecouriste](const std::shared_ptr<Secouriste>& s) {
            return s->getId() == idSecouriste;
        }), equipeSecouristes.end());
}

const std::vector<std::shared_ptr<Secouriste>>& Ressource::getEquipeSecouristes() const {
    return equipeSecouristes;
}

std::string Ressource::toString() const {
    return "Ressource [" + type + "] ID=" + id + ", Disponible=" + (estDisponible() ? "Oui" : "Non");
}

std::string Ressource::genererRequeteSQL() const {
    return "INSERT INTO ressources (id, disponible) VALUES ('" + id + "', " + (estDisponible() ? "1" : "0") + ");";
}

