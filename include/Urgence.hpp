#ifndef URGENCE_HPP
#define URGENCE_HPP

#include <string>

/**
 * @brief Classe abstraite représentant une urgence dans le SGU.
 *
 * Cette classe sert de base pour toutes les urgences signalées, avec des informations
 * communes comme la localisation, la gravité et le statut.
 */
class Urgence {
protected:
    std::string localisation; /**< Localisation de l’urgence (adresse ou GPS) */
    int niveauGravite;        /**< Niveau de gravité (1: mineur, 2: majeur, 3: critique) */
    std::string statut;       /**< Statut actuel (en attente, en cours, terminée) */

public:
    /**
     * @brief Constructeur avec paramètres.
     * @param loc Localisation de l’urgence.
     * @param grav Niveau de gravité (1 à 3).
     */
    Urgence(const std::string& loc, int grav);

    /**
     * @brief Destructeur virtuel.
     */
    virtual ~Urgence() = default;

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
     * @brief Définit le statut de l’urgence.
     * @param st Nouveau statut.
     */
    void setStatut(const std::string& st);

    /**
     * @brief Méthode virtuelle pure pour décrire l’urgence.
     * @return Une description textuelle spécifique au type d’urgence.
     */
    virtual std::string description() const = 0;
};

#endif // URGENCE_HPP
