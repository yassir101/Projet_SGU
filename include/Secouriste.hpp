/**
 * @file Secouriste.hpp
 * @brief Représente un secouriste dans le système SGU.
 */

#ifndef SECOURISTE_HPP
#define SECOURISTE_HPP

#include "Utilisateur.hpp"
#include <string>
#include <iostream>

/**
 * @class Secouriste
 * @brief Utilisateur intervenant sur le terrain pour gérer les urgences.
 */
class Secouriste : public Utilisateur {
private:
    std::string matricule;   ///< Matricule unique du secouriste
    std::string specialite;  ///< Spécialité du secouriste (ex: incendie, médical...)

public:
    /**
     * @brief Constructeur
     * @param id Identifiant
     * @param nom Nom
     * @param matricule Matricule interne
     * @param specialite Spécialité du secouriste
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

    // Getters / Setters
    std::string getMatricule() const;
    void setMatricule(const std::string& m);

    std::string getSpecialite() const;
    void setSpecialite(const std::string& s);
};

#endif // SECOURISTE_HPP
