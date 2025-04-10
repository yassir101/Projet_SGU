#ifndef URGENCEMEDICALE_HPP
#define URGENCEMEDICALE_HPP

#include "Urgence.hpp"

/**
 * @brief Représente une urgence médicale dans le SGU.
 */
class UrgenceMedicale : public Urgence {
private:
    int nbVictimes; /**< Nombre de victimes */

public:
    /**
     * @brief Constructeur.
     * @param id Identifiant.
     * @param type Type d’urgence.
     * @param loc Localisation.
     * @param grav Gravité.
     * @param nbVict Nombre de victimes.
     */
    UrgenceMedicale(const std::string& id, const std::string& type, const std::string& loc, int grav,
                    int nbVict);

    /**
     * @brief Évalue la priorité de l’urgence médicale.
     * @return La priorité ajustée.
     */
    int evaluerPriorite() const override;
};

#endif // URGENCEMEDICALE_HPP
