#ifndef RESSOURCE_HPP
#define RESSOURCE_HPP

#include "Intervention.hpp"

/**
 * @brief Représente une ressource mobilisable dans le SGU.
 */
class Ressource : public Intervention {
protected:
    std::string id;       /**< Identifiant spécifique de la ressource */
    bool disponible;      /**< État de disponibilité */

public:
    /**
     * @brief Constructeur.
     * @param idIntervention Identifiant de l’intervention (hérité).
     * @param debut Date et heure de début (hérité).
     * @param idRessource Identifiant spécifique de la ressource.
     */
    Ressource(const std::string& idIntervention, const std::string& debut, const std::string& idRessource);

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
    void affecter();

    /**
     * @brief Libère la ressource après usage.
     */
    void liberer();
};

#endif // RESSOURCE_HPP