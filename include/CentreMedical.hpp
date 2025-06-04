#ifndef CENTRE_MEDICAL_HPP
#define CENTRE_MEDICAL_HPP

#include "Ressource.hpp"

/**
 * @file CentreMedical.hpp
 * @brief Déclaration de la classe CentreMedical
 */

/**
 * @class CentreMedical
 * @brief Centre médical disposant d’ambulances mobilisables.
 *
 * Cette classe hérite de Ressource et représente un centre médical capable
 * de déployer des ambulances en réponse à une urgence. Chaque ambulance est considérée
 * comme une unité mobilisable pour les opérations d’évacuation et de soins d’urgence.
 */
class CentreMedical : public Ressource {
private:
    int ambulancesDisponibles; ///< Nombre d’ambulances actuellement disponibles

public:
    /**
     * @brief Constructeur du centre médical
     * @param id Identifiant unique de la ressource (hérité)
     * @param nbAmbulances Nombre initial d’ambulances disponibles
     */
    CentreMedical(const std::string& id, int nbAmbulances);

    /**
     * @brief Affecte une ambulance à une intervention
     * 
     * Décrémente le nombre d’ambulances disponibles.
     * Lance une exception si aucune ambulance n’est disponible.
     */
    void affecter() override;

    /**
     * @brief Libère une ambulance
     *
     * Incrémente le nombre d’ambulances disponibles.
     */
    void liberer() override;
    
    std::string getType() const override;

    /**
     * @brief Envoie une ambulance sur le terrain.
     * 
     * Méthode d’alias pour `affecter()`.
     */
    void envoyerAmbulance();

    /**
     * @brief Rappelle une ambulance au centre.
     *
     * Méthode d’alias pour `liberer()`.
     */
    void rappelerAmbulance();

    /**
     * @brief Accesseur du nombre d’ambulances disponibles
     * @return Entier représentant le stock actuel
     */
    int getAmbulancesDisponibles() const;

    /**
     * @brief Génère une requête SQL d’insertion correspondant à l’état du centre
     * @return Chaîne de requête SQL
     */
    std::string genererRequeteSQL() const;
};

#endif // CENTRE_MEDICAL_HPP

