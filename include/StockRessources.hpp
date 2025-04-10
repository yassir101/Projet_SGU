#ifndef STOCKRESSOURCES_HPP
#define STOCKRESSOURCES_HPP

#include <vector>
#include "Ressource.hpp"

/**
 * @brief Gère l’ensemble des ressources disponibles dans le SGU.
 */
class StockRessources {
private:
    std::vector<Ressource*> ressources; /**< Liste des ressources */

public:
    /**
     * @brief Constructeur par défaut.
     */
    StockRessources();

    /**
     * @brief Destructeur pour libérer la mémoire.
     */
    ~StockRessources();

    /**
     * @brief Ajoute une ressource au stock.
     * @param r Pointeur vers la ressource.
     */
    void ajouterRessource(Ressource* r);

    /**
     * @brief Recherche une ressource disponible par type.
     * @param type Type de ressource recherché.
     * @return Pointeur vers la ressource ou nullptr si aucune disponible.
     */
    Ressource* trouverRessourceDisponible(const std::string& type);
};

#endif // STOCKRESSOURCES_HPP