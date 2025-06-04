#ifndef RESSOURCE_HPP
#define RESSOURCE_HPP

#include <string>

/**
 * @class Ressource
 * @brief Représente une ressource mobilisable dans le SGU.
 *
 * Classe de base pour toutes les ressources (caserne, secouriste, unité mobile…).
 * Gère l'identification, la disponibilité, et les opérations d'affectation.
 */
class Ressource {
protected:
    std::string id;        ///< Identifiant spécifique de la ressource
    bool disponible;       ///< État de disponibilité
	std::string type;   /**< Type de la ressource */

public:
    /**
     * @brief Constructeur.
     * @param idRessource Identifiant spécifique de la ressource.
     * @param type Type de la ressource
     */
    Ressource(const std::string& idRessource, const std::string& type);

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
    
    /** @brief Retourne le type de la ressource */
    virtual std::string getType() const;

    /**
     * @brief Affecte la ressource à une intervention.
     */
    virtual void affecter();

    /**
     * @brief Libère la ressource après usage.
     */
    virtual void liberer();

    /**
     * @brief Retourne une description textuelle de la ressource.
     * @return Chaîne résumant l’état et l’identifiant.
     */
    virtual std::string toString() const;

    /**
     * @brief Génère une commande SQL d’insertion dans la base.
     * @return Requête SQL formatée.
     */
    virtual std::string genererRequeteSQL() const;
};

#endif // RESSOURCE_HPP

