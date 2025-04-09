#ifndef URGENCEMEDICALE_HPP
#define URGENCEMEDICALE_HPP

#include "Urgence.hpp"

/**
 * @brief Représente une urgence médicale dans le SGU.
 */
class UrgenceMedicale : public Urgence {
private:
    std::string pathologie; /**< Type de pathologie (ex. arrêt cardiaque) */
    int nombreVictimes;     /**< Nombre de victimes */

public:
    /**
     * @brief Constructeur.
     * @param loc Localisation.
     * @param grav Gravité.
     * @param patho Type de pathologie.
     * @param nbVict Nombre de victimes.
     */
    UrgenceMedicale(const std::string& loc, int grav, const std::string& patho, int nbVict);

    /**
     * @brief Retourne une description de l’urgence médicale.
     * @return Description textuelle.
     */
    std::string description() const override;
};

#endif // URGENCEMEDICALE_HPP
