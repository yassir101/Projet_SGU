#ifndef ACCIDENT_HPP
#define ACCIDENT_HPP

#include "Urgence.hpp"

/**
 * @brief Représente une urgence de type accident dans le SGU.
 */
class Accident : public Urgence {
private:
    int nbVehicules; /**< Nombre de véhicules impliqués */

public:
    /**
     * @brief Constructeur.
     * @param id Identifiant.
     * @param type Type d’urgence.
     * @param loc Localisation.
     * @param grav Gravité.
     * @param nbVeh Nombre de véhicules.
     */
    Accident(const std::string& id, const std::string& type, const std::string& loc, int grav,
             int nbVeh);

    /**
     * @brief Évalue la priorité de l’accident.
     * @return La priorité ajustée.
     */
    int evaluerPriorite() const override;
};

#endif // ACCIDENT_HPP
