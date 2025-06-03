#ifndef RESSOURCE_HPP
#define RESSOURCE_HPP

#include <string>

/**
 * @brief Représente une ressource mobilisable dans le SGU.
 */
class Ressource {
protected:
    std::string id;       /**< Identifiant spécifique de la ressource */
    bool disponible;      /**< État de disponibilité */

public:
    /**
     * @brief Constructeur.
     * @param idRessource Identifiant spécifique de la ressource.
     */
    Ressource(const std::string& idRessource);

    /**
     * @brief Destructeur virtuel.
     */
    virtual ~Ressource() = default;

    /**
     * @brief Récupère l’identifiant spécifique de la ressource.
     * @return L’identifiant de la ressource.
     */
    std::string getIdRessource() const;

    /**
     * @brief Vérifie la disponibilité.
     * @return True si disponible, false sinon.
     */
    bool estDisponible() const;

    /**
     * @brief Affecte la ressource à une intervention.
     */
    virtual void affecter();

    /**
     * @brief Libère la ressource après usage.
     */
    virtual void liberer();
};

#endif // RESSOURCE_HPP