#ifndef CASERNE_HPP
#define CASERNE_HPP

#include "Ressource.hpp"
#include <string>

/**
 * @class Caserne
 * @brief Caserne de pompiers pouvant fournir des équipes d'intervention.
 *
 * Spécialisation concrète de Ressource pour représenter une caserne,
 * avec gestion du nombre d’équipes disponibles.
 */
class Caserne : public Ressource {
private:
    int nbEquipesDisponibles;   ///< Nombre d'équipes actuellement disponibles

public:
    /**
     * @brief Constructeur
     * @param id Identifiant de la caserne
     * @param nbEquipes Nombre initial d'équipes disponibles
     */
    Caserne(const std::string& id, int nbEquipes);

    /**
     * @brief Affecte une équipe à une intervention
     */
    void affecter() override;

    /**
     * @brief Libère une équipe après intervention
     */
    void liberer() override;

    /**
     * @brief Envoie une équipe manuellement
     */
    void envoyerEquipe();

    /**
     * @brief Rappelle une équipe manuellement
     */
    void rappelerEquipe();
	
	
    std::string getType() const override;

    /**
     * @brief Nombre d'équipes disponibles
     * @return Entier représentant le nombre d'équipes
     */
    int getNbEquipesDisponibles() const;

    /**
     * @brief Génère une requête SQL pour enregistrer l’état de la caserne.
     * @return Chaîne SQL INSERT.
     */
    std::string genererRequeteSQL() const;
};

#endif // CASERNE_HPP

