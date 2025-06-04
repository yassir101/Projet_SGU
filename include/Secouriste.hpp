/**
 * @file Secouriste.hpp
 * @brief Définition de la classe Secouriste pour le SGU.
 */

#ifndef SECOURISTE_HPP
#define SECOURISTE_HPP

#include "Utilisateur.hpp"
#include <string>

/**
 * @class Secouriste
 * @brief Utilisateur spécialisé qui intervient sur le terrain lors des urgences.
 *
 * Un secouriste hérite des attributs et méthodes de la classe Utilisateur.
 * Il possède en plus un matricule et une spécialité (incendie, médical, etc.).
 * La disponibilité d’un secouriste est gérée via l’état hérité d’Utilisateur.
 */
class Secouriste : public Utilisateur {
private:
    std::string matricule;   ///< Matricule unique du secouriste
    std::string specialite;  ///< Spécialité du secouriste (ex : incendie, médical...)

public:
    /**
     * @brief Constructeur
     * @param id Identifiant unique du secouriste
     * @param nom Nom du secouriste
     * @param matricule Matricule administratif
     * @param specialite Domaine d’intervention principal
     */
    Secouriste(const std::string& id, const std::string& nom,
               const std::string& matricule, const std::string& specialite);

    /**
     * @brief Met à jour le statut de l’intervention en cours.
     */
    void mettreAJourStatut() const;

    /**
     * @brief Confirme que l’intervention est bien prise en charge.
     */
    void confirmerIntervention() const;

    /**
     * @brief Transmet sa position actuelle au système.
     */
    void transmettrePosition() const;

    /**
     * @brief Renvoie une description textuelle du secouriste.
     * @return Description lisible.
     */
    std::string toString() const;

    /**
     * @brief Génère une requête SQL d’insertion du secouriste.
     * @return Chaîne de requête SQL.
     */
    std::string genererRequeteSQL() const;

    /**
     * @brief Retourne le type d'utilisateur (ici "Secouriste").
     * @return "Secouriste"
     */
    std::string getTypeUtilisateur() const override;

    /// @name Accesseurs
    /// @{
    /**
     * @brief Renvoie le matricule du secouriste.
     * @return Matricule
     */
    std::string getMatricule() const;

    /**
     * @brief Définit un nouveau matricule.
     * @param m Nouveau matricule
     */
    void setMatricule(const std::string& m);

    /**
     * @brief Renvoie la spécialité du secouriste.
     * @return Spécialité
     */
    std::string getSpecialite() const;

    /**
     * @brief Définit une nouvelle spécialité.
     * @param s Nouvelle spécialité
     */
    void setSpecialite(const std::string& s);
    /// @}

    /// @name Disponibilité
    /// @{
    /**
     * @brief Indique si le secouriste est disponible pour une intervention.
     * @return true si disponible (hérité d’Utilisateur)
     */
    bool estDisponible() const ;

    /**
     * @brief Modifie la disponibilité du secouriste.
     * @param dispo true = disponible, false = indisponible
     */
    void setDisponible(bool dispo);
    /// @}
};

#endif // SECOURISTE_HPP

