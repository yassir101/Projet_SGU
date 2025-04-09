#ifndef RESSOURCE_HPP
#define RESSOURCE_HPP

#include <string>

/**
 * @brief Classe abstraite représentant une ressource mobilisable dans le SGU.
 */
class Ressource {
protected:
    std::string nom;       /**< Nom ou identifiant de la ressource */
    bool disponible;       /**< État de disponibilité */

public:
    /**
     * @brief Constructeur.
     * @param n Nom de la ressource.
     */
    Ressource(const std::string& n);

    /**
     * @brief Destructeur virtuel.
     */
    virtual ~Ressource() = default;

    /**
     * @brief Vérifie la disponibilité.
     * @return True si disponible, false sinon.
     */
    bool estDisponible() const;

    /**
     * @brief Définit la disponibilité.
     * @param disp Nouvel état.
     */
    void setDisponible(bool disp);

    /**
     * @brief Méthode virtuelle pure pour décrire la ressource.
     * @return Description textuelle spécifique.
     */
    virtual std::string typeRessource() const = 0;
};

#endif // RESSOURCE_HPP