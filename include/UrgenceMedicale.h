/**
 * @file UrgenceMedicale.h
 * @brief Classe représentant une urgence de type médicale.
 */

#ifndef URGENCEMEDICALE_H
#define URGENCEMEDICALE_H

#include "Urgence.h"

/**
 * @class UrgenceMedicale
 * @brief Spécialisation de la classe Urgence pour un cas médical.
 */
class UrgenceMedicale : public Urgence {
private:
    bool urgenceVitale;             ///< Indique si la vie du patient est en danger immédiat
    int nbVictimes;                 ///< Nombre de victimes concernées
    std::string pathologiePresumee; ///< Type de pathologie suspectée

public:
    /**
     * @brief Constructeur de la classe UrgenceMedicale
     * @param id Identifiant de l'urgence
     * @param localisation Localisation géographique
     * @param gravite Niveau de gravité
     * @param vitale Urgence vitale (oui/non)
     * @param nbVictimes Nombre de personnes concernées
     * @param pathologie Type de pathologie suspectée
     */
    UrgenceMedicale(const std::string& id, const std::string& localisation, int gravite,
                    bool vitale, int nbVictimes, const std::string& pathologie);

    /**
     * @brief Évalue la priorité de l'urgence médicale
     * @return Un entier représentant la priorité
     */
    int evaluerPriorite() const override;

    // Getters
    bool estUrgenceVitale() const;
    int getNbVictimes() const;
    std::string getPathologiePresumee() const;
};

#endif // URGENCEMEDICALE_H
