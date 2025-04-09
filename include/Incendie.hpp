#ifndef INCENDIE_HPP
#define INCENDIE_HPP

#include "Urgence.hpp"

/**
 * @brief Représente une urgence de type incendie dans le SGU.
 */
class Incendie : public Urgence {
private:
    std::string typeFeu; /**< Type de feu (habitation, forêt, véhicule) */
    double superficie;   /**< Superficie en m² */

public:
    /**
     * @brief Constructeur.
     * @param loc Localisation.
     * @param grav Gravité.
     * @param type Type de feu.
     * @param surf Superficie.
     */
    Incendie(const std::string& loc, int grav, const std::string& type, double surf);

    /**
     * @brief Retourne une description de l’incendie.
     * @return Description textuelle.
     */
    std::string description() const override;
};

#endif // INCENDIE_HPP