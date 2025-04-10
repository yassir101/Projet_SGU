/**
 * @file Administrateur.hpp
 * @brief Représente un administrateur dans le système SGU.
 */

#ifndef ADMINISTRATEUR_HPP
#define ADMINISTRATEUR_HPP

#include "Utilisateur.hpp"
#include <string>
#include <iostream>

/**
 * @class Administrateur
 * @brief Utilisateur ayant un rôle de supervision dans le SGU.
 *
 * L'administrateur peut valider les interventions, consulter ou demander des rapports.
 */
class Administrateur : public Utilisateur {
private:
    int niveauAcces; ///< Niveau d'accès de l'administrateur (0 = basique, 1 = avancé, etc.)

public:
    /**
     * @brief Constructeur
     * @param id Identifiant
     * @param nom Nom
     * @param niveauAcces Niveau d'accès
     */
    Administrateur(const std::string& id, const std::string& nom, int niveauAcces);

    /**
     * @brief Valide une intervention proposée par le système
     */
    void validerIntervention() const;

    /**
     * @brief Consulte un rapport déjà généré
     */
    void consulterRapport() const;

    /**
     * @brief Demande la génération d’un rapport
     */
    void demanderRapport() const;

    // Getter / Setter
    int getNiveauAcces() const;
    void setNiveauAcces(int niveau);
};

#endif // ADMINISTRATEUR_HPP
