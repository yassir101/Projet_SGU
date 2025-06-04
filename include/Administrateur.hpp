/**
 * @file Administrateur.hpp
 * @brief Représente un administrateur dans le système SGU.
 */

#ifndef ADMINISTRATEUR_HPP
#define ADMINISTRATEUR_HPP

#include "Utilisateur.hpp"
#include <string>

/**
 * @class Administrateur
 * @brief Utilisateur ayant un rôle de supervision dans le SGU.
 *
 * L'administrateur peut valider les interventions, consulter ou demander des rapports.
 * La disponibilité est gérée via la classe Utilisateur.
 */
class Administrateur : public Utilisateur {
private:
    int niveauAcces; ///< Niveau d'accès de l'administrateur (0 = basique, 1 = avancé, etc.)

public:
    /**
     * @brief Constructeur
     * @param id Identifiant unique de l'administrateur
     * @param nom Nom de l'administrateur
     * @param niveauAcces Niveau d'accès au système
     */
    Administrateur(const std::string& id, const std::string& nom, int niveauAcces);

    /**
     * @brief Valide une intervention proposée par le système.
     */
    void validerIntervention() const;

    /**
     * @brief Consulte un rapport déjà généré.
     */
    void consulterRapport() const;

    /**
     * @brief Demande la génération d’un rapport.
     */
    void demanderRapport() const;

    /**
     * @brief Retourne le type d'utilisateur (ici "Administrateur").
     * @return "Administrateur"
     */
    std::string getTypeUtilisateur() const override;

    /// @name Accesseurs
    /// @{
    /**
     * @brief Récupère le niveau d'accès.
     * @return Niveau d'accès
     */
    int getNiveauAcces() const;

    /**
     * @brief Définit un nouveau niveau d'accès.
     * @param niveau Nouveau niveau
     */
    void setNiveauAcces(int niveau);
    /// @}

    /// @name Disponibilité (héritée de Utilisateur)
    /// @{
    /**
     * @brief Indique si l'administrateur est disponible pour une tâche.
     * @return true si disponible
     */
    bool estDisponible() const ;

    /**
     * @brief Modifie la disponibilité de l'administrateur.
     * @param dispo true = disponible, false = indisponible
     */
    void setDisponible(bool dispo) ;
    /// @}
};

#endif // ADMINISTRATEUR_HPP

