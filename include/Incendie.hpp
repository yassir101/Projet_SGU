/**
 * @file Incendie.h
 * @brief Classe représentant une urgence de type incendie.
 */

#ifndef INCENDIE_H
#define INCENDIE_H

#include "Urgence.h"

/**
 * @class Incendie
 * @brief Spécialisation de la classe Urgence pour un incendie.
 */
class Incendie : public Urgence {
private:
    std::string typeFeu; ///< Type de feu (ex: domestique, industriel, forêt, etc.)

public:
    /**
     * @brief Constructeur de l'objet Incendie
     * @param id Identifiant de l'urgence
     * @param localisation Localisation du feu
     * @param gravite Niveau de gravité
     * @param typeFeu Type de feu
     */
    Incendie(const std::string& id, const std::string& localisation, int gravite, const std::string& typeFeu);

    /**
     * @brief Évalue la priorité de l'incendie
     * @return Un entier représentant la priorité
     */
    int evaluerPriorite() const override;

    // Getter
    std::string getTypeFeu() const;
};

#endif // INCENDIE_H
