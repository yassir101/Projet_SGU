#ifndef ACCIDENT_HPP
#define ACCIDENT_HPP

#include "Urgence.hpp"

/**
 * @brief Représente une urgence de type accident dans le SGU.
 */
class Accident : public Urgence {
private:
    int nombreVehicules; /**< Nombre de véhicules impliqués */
    int nombreBlesses;   /**< Nombre de blessés */

public:
    /**
     * @brief Constructeur.
     * @param loc Localisation.
     * @param grav Gravité.
     * @param nbVeh Nombre de véhicules.
     * @param nbBless Nombre de blessés.
     */
    Accident(const std::string& loc, int grav, int nbVeh, int nbBless);

    /**
     * @brief Retourne une description de l’accident.
     * @return Description textuelle.
     */
    std::string description() const override;
};

#endif // ACCIDENT_HPP
