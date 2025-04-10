#ifndef URGENCE_HPP
#define URGENCE_HPP

#include <string>

/**
 * @brief Classe abstraite représentant une urgence dans le SGU.
 *
 * Cette classe sert de base pour toutes les urgences signalées, avec des informations
 * comme l’identifiant, le type, la localisation, la gravité et le statut.
 */
class Urgence {
protected:
    std::string id;           /**< Identifiant unique de l’urgence */
    std::string type;         /**< Type d’urgence (ex. : "Incendie", "Accident") */
    std::string localisation; /**< Localisation de l’urgence (adresse ou GPS) */
    int niveauGravite;        /**< Niveau de gravité (1: mineur, 2: majeur, 3: critique) */
    std::string statut;       /**< Statut actuel (en attente, en cours, terminée) */

public:
    /**
     * @brief Constructeur avec paramètres.
     * @param id Identifiant unique.
     * @param type Type d’urgence.
     * @param loc Localisation.
     * @param grav Niveau de gravité (1 à 3).
     */
    Urgence(const std::string& id, const std::string& type, const std::string& loc, int grav);

    /**
     * @brief Destructeur virtuel.
     */
    virtual ~Urgence() = default;

    /**
     * @brief Récupère l’identifiant.
     * @return L’identifiant sous forme de chaîne.
     */
    std::string getId() const;

    /**
     * @brief Récupère le type.
     * @return Le type sous forme de chaîne.
     */
    std::string getType() const;

    /**
     * @brief Récupère la localisation.
     * @return La localisation sous forme de chaîne.
     */
    std::string getLocalisation() const;

    /**
     * @brief Définit la localisation.
     * @param loc Nouvelle localisation.
     */
    void setLocalisation(const std::string& loc);

    /**
     * @brief Récupère le niveau de gravité.
     * @return Le niveau de gravité.
     */
    int getNiveauGravite() const;

    /**
     * @brief Récupère le statut.
     * @return Le statut sous forme de chaîne.
     */
    std::string getStatut() const;

    /**
     * @brief Définit le statut.
     * @param st Nouveau statut.
     */
    void setStatut(const std::string& st);

    /**
     * @brief Évalue la priorité de l’urgence.
     * @return La priorité (basée sur le niveau de gravité).
     */
    virtual int evaluerPriorite() const;
    
    /**
     * @brief Met à jour le statut de l’urgence.
     */
    void mettreAJourStatut();
};

#endif // URGENCE_HPP