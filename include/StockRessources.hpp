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
     * @brief Met à jour les statuts de disponibilité des ressources.
     */
    void mettreAJourDisponibilite();

    /**
     * @brief Vérifie la disponibilité d’une ressource par type.
     * @param type Type recherché
     * @return true si une ressource disponible du type est trouvée
     */
    bool verifierDisponibilite(const std::string& type) const;

    /**
     * @brief Retourne les ressources du stock.
     */
    const std::vector<std::shared_ptr<Ressource>>& getRessources() const;

    /**
     * @brief Retourne une description textuelle du stock.
     */
    std::string toString() const;

    /**
     * @brief Génère une requête SQL pour enregistrer le stock (ou ses ressources).
     * @return Requête SQL
     */
    std::string genererRequeteSQL() const;
};

#endif // STOCKRESSOURCES_HPP

