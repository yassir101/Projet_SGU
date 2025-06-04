#ifndef URGENCE_HPP
#define URGENCE_HPP

#include <string>
#include <vector>
#include "Ressource.hpp"

/**
 * @brief Classe abstraite représentant une urgence dans le SGU.
 *
 * Sert de base aux types d’urgence spécifiques (incendie, accident, médicale...).
 * Contient les informations communes et les méthodes génériques.
 */
class Urgence {
protected:
    std::string id;                  /**< Identifiant unique de l’urgence */
    std::string type;                /**< Type d’urgence (incendie, accident...) */
    std::string localisation;        /**< Adresse ou point GPS de l’incident */
    int niveauGravite;               /**< Gravité : 1 (mineur), 2 (majeur), 3 (critique) */
    std::string statut;              /**< Statut de l’intervention */
    int priorite;                    /**< Priorité calculée */
    std::vector<Ressource> ressources; /**< Liste des ressources affectées */

public:
    /**
     * @brief Constructeur principal
     * @param id Identifiant unique
     * @param type Type d’urgence
     * @param loc Localisation
     * @param grav Niveau de gravité
     */
    Urgence(const std::string& id, const std::string& type, const std::string& loc, int grav);

    /**
     * @brief Destructeur virtuel.
     */
    virtual ~Urgence() = default;

    /** @return L’identifiant de l’urgence */
    std::string getIdUrgence() const;

    /** @return Le type d’urgence */
    std::string getTypeUrgence() const;

    /** @return La localisation de l’incident */
    std::string getLocalisation() const;

    /** @brief Modifie la localisation */
    void setLocalisation(const std::string& loc);

    /** @return Le niveau de gravité */
    int getNiveauGravite() const;

    /** @return Le statut actuel */
    std::string getStatut() const;

    /** @brief Modifie le statut */
    void setStatut(const std::string& st);

    /** @brief Calcule la priorité de l’urgence */
    virtual int evaluerPriorite() const = 0;

    /** @brief Met à jour automatiquement le statut */
    void mettreAJourStatut();

    /**
     * @brief Retourne une représentation texte de l’urgence.
     * @return Une chaîne de résumé
     */
    virtual std::string toString() const;

    /**
     * @brief Retourne une description plus détaillée (surchargeable)
     * @return Chaîne descriptive
     */
    virtual std::string description() const;

    /**
     * @brief Définit la priorité
     * @param p Niveau de priorité calculé
     */
    void setPriorite(int p);

    /**
     * @brief Affecte les ressources à l’urgence
     * @param r Vecteur de ressources
     */
    void setRessources(const std::vector<Ressource>& r);
    
        /** @return La priorité */
    int getPriorite() const;

    /** @return Les ressources affectées */
    std::vector<Ressource> getRessources() const;

    /**
     * @brief Méthode virtuelle pour générer une requête SQL d'insertion.
     * @return Requête SQL au format chaîne.
     */
    virtual std::string genererRequeteSQL() const = 0;

};

#endif // URGENCE_HPP

