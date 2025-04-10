#ifndef STOCKRESSOURCES_HPP
#define STOCKRESSOURCES_HPP

#include <vector>
#include "Ressource.hpp"

/**
 * @brief Représente un stock de ressources dans le SGU, qui est lui-même une ressource.
 */
class StockRessources : public Ressource {
private:
    std::vector<Ressource*> ressourcesDisponibles; /**< Liste des ressources gérées par le stock */

public:
    /**
     * @brief Constructeur.
     * @param idIntervention Identifiant de l’intervention (hérité de Intervention).
     * @param debut Date et heure de début (hérité de Intervention).
     * @param idRessource Identifiant spécifique de la ressource (hérité de Ressource).
     */
    StockRessources(const std::string& idIntervention, const std::string& debut, const std::string& idRessource);

    /**
     * @brief Destructeur pour libérer la mémoire.
     */
    ~StockRessources();

    /**
     * @brief Met à jour la disponibilité des ressources.
     */
    void mettreAJourDisponibilite();

    /**
     * @brief Vérifie si une ressource est disponible pour un utilisateur.
     * @param dest Utilisateur demandant la ressource.
     * @return True si une ressource est disponible, false sinon.
     */
    bool verifierDisponibilite(const std::string& dest);
};

#endif // STOCKRESSOURCES_HPP