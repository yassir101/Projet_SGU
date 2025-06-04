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
     
    /** @brief Accès au nombre de véhicules */
    int getNbVehicules() const;

    /** @brief Mise à jour du nombre de véhicules */
    void setNbVehicules(int nbVeh);

    /**
     * @brief Fournit une description textuelle de l’accident.
     * @return Une chaîne descriptive.
     */
    std::string description() const;


    /**
     * @brief Évalue la priorité de l’accident.
     * @return La priorité ajustée.
     */
    int evaluerPriorite() const override;
    
    /**
     * @brief Convertit l'objet en commande SQL INSERT.
     * @return Chaîne SQL à exécuter.
     */
    std::string genererRequeteSQL() const override;
};

#endif // ACCIDENT_HPP
