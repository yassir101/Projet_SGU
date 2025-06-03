#ifndef STOCKRESSOURCES_HPP
#define STOCKRESSOURCES_HPP

#include <vector>
#include <memory>
#include <string>
#include "Ressource.hpp"

/**
 * @brief Représente un stock de ressources dans le SGU, qui est lui-même une ressource.
 */
class StockRessources : public Ressource {
private:
    std::vector<std::shared_ptr<Ressource>> ressourcesDisponibles;

public:
    /**
     * @brief Constructeur.
     * @param id Identifiant de la ressource stock
     */
    StockRessources(const std::string& id);

    /**
     * @brief Destructeur.
     */
    ~StockRessources();

    /**
     * @brief Ajoute une ressource au stock.
     */
    void ajouterRessource(std::shared_ptr<Ressource> ressource);

    /**
     * @brief Met à jour la disponibilité des ressources.
     */
    void mettreAJourDisponibilite();

    /**
     * @brief Vérifie la disponibilité d’une ressource par type.
     */
    bool verifierDisponibilite(const std::string& type) const;

    const std::vector<std::shared_ptr<Ressource>>& getRessources() const;
};

#endif // STOCKRESSOURCES_HPP
