/**
 * @file Accident.h
 * @brief Classe représentant une urgence de type accident.
 */

#ifndef ACCIDENT_H
#define ACCIDENT_H

#include "Urgence.h"

/**
 * @class Accident
 * @brief Spécialisation de la classe Urgence pour un accident (routier ou autre).
 */
class Accident : public Urgence {
private:
    int nbVehiculesImpliques;     ///< Nombre de véhicules impliqués dans l'accident
    std::string typeAccident;     ///< Type d'accident (collision, carambolage, etc.)
    bool presenceBlesses;         ///< Indique s'il y a des blessés

public:
    /**
     * @brief Constructeur de la classe Accident
     * @param id Identifiant unique
     * @param localisation Lieu de l'accident
     * @param gravite Niveau de gravité
     * @param nbVehicules Nombre de véhicules impliqués
     * @param typeAccident Description du type d'accident
     * @param blesses Présence de blessés (true/false)
     */
    Accident(const std::string& id, const std::string& localisation, int gravite,
             int nbVehicules, const std::string& typeAccident, bool blesses);

    /**
     * @brief Évalue la priorité de traitement de l'accident
     * @return Un entier représentant la priorité
     */
    int evaluerPriorite() const override;

    // Getters
    int getNbVehiculesImpliques() const;
    std::string getTypeAccident() const;
    bool getPresenceBlesses() const;
};

#endif // ACCIDENT_H
