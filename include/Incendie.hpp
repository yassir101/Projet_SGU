#ifndef INCENDIE_HPP
#define INCENDIE_HPP

#include "Urgence.hpp"

/**
 * @brief Représente une urgence de type incendie dans le SGU.
 */
class Incendie : public Urgence {
private:
    std::string typeFeu; /**< Type de feu (habitation, forêt, véhicule) */

public:
    /**
     * @brief Constructeur.
     * @param id Identifiant.
     * @param type Type d’urgence.
     * @param loc Localisation.
     * @param grav Gravité.
     * @param typeFeu Type de feu.
     */
    Incendie(const std::string& id, const std::string& type, const std::string& loc, int grav,
             const std::string& typeFeu);

    /**
     * @brief Retourne une description de l’incendie.
     * @return Description textuelle.
     */
    std::string description() const override;

    /**
     * @brief Évalue la priorité de l’incendie.
     * @return La priorité ajustée.
     */
    int evaluerPriorite() const override;
};

#endif // INCENDIE_HPP