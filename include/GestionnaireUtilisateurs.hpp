#ifndef GESTIONNAIREUTILISATEURS_HPP
#define GESTIONNAIREUTILISATEURS_HPP

#include <vector>
#include <memory>
#include <string>
#include "Utilisateur.hpp"
#include "Administrateur.hpp"
#include "Secouriste.hpp"
#include "Demandeur.hpp"

/**
 * @class GestionnaireUtilisateurs
 * @brief Gestion centralisée des utilisateurs (administrateurs, secouristes, demandeurs)
 */
class GestionnaireUtilisateurs {
private:
    std::vector<std::shared_ptr<Administrateur>> administrateurs;
    std::vector<std::shared_ptr<Secouriste>> secouristes;
    std::vector<std::shared_ptr<Demandeur>> demandeurs;

public:
    GestionnaireUtilisateurs() = default;

    // Ajout d’utilisateurs
    void ajouterAdministrateur(std::shared_ptr<Administrateur> admin);
    void ajouterSecouriste(std::shared_ptr<Secouriste> sec);
    void ajouterDemandeur(std::shared_ptr<Demandeur> demandeur);

    // Recherche utilisateur libre par rôle
    std::shared_ptr<Administrateur> trouverAdministrateurLibre() const;
    std::shared_ptr<Secouriste> trouverSecouristeLibre() const;

    // Obtenir listes (pour affichage, gestion, etc.)
    const std::vector<std::shared_ptr<Administrateur>>& getAdministrateurs() const;
    const std::vector<std::shared_ptr<Secouriste>>& getSecouristes() const;
    const std::vector<std::shared_ptr<Demandeur>>& getDemandeurs() const;
};

#endif // GESTIONNAIREUTILISATEURS_HPP

