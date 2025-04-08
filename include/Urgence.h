/**
 * @file Urgence.h
 * @brief Classe abstraite représentant une urgence générique.
 */

#ifndef URGENCE_H
#define URGENCE_H

#include <string>

/**
 * @class Urgence
 * @brief Classe de base pour tous les types d’urgences (accident, incendie, médicale...).
 */
class Urgence {
protected:
    std::string id;                ///< Identifiant unique de l'urgence
    std::string type;              ///< Type d'urgence (ex: Incendie, Médicale, Accident)
    std::string localisation;      ///< Localisation géographique
    int niveauGravite;             ///< Gravité de l'urgence (1 à 5)
    std::string statut;            ///< Statut actuel de l'urgence

public:
    Urgence(const std::string& id, const std::string& type, const std::string& localisation, int niveauGravite);

    virtual ~Urgence() = default;

    /**
     * @brief Évalue la priorité de traitement de l'urgence.
     * @return Un entier représentant la priorité.
     */
    virtual int evaluerPriorite() const = 0;

    /**
     * @brief Met à jour le statut de l'urgence.
     * @param nouveauStatut Le nouveau statut à appliquer.
     */
    void mettreAJourStatut(const std::string& nouveauStatut);

    // Getters
    std::string getId() const;
    std::string getType() const;
    std::string getLocalisation() const;
    int getNiveauGravite() const;
    std::string getStatut() const;
};

#endif // URGENCE_H
