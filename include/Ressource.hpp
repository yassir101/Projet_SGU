#ifndef RESSOURCE_HPP
#define RESSOURCE_HPP

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Secouriste.hpp"

class Ressource {
protected:
    std::string id;   ///< Identifiant unique
    std::string type; ///< Type (ex: Caserne)
    std::vector<std::shared_ptr<Secouriste>> equipeSecouristes; ///< Équipe associée

public:
    Ressource(const std::string& idRessource, const std::string& type);
    virtual ~Ressource() = default;
	
    std::string getIdRessource() const;
    virtual std::string getType() const;

    /**
     * @brief Indique si la ressource est disponible
     *        (au moins un secouriste disponible dans l’équipe).
     */
    virtual bool estDisponible() const;

    /**
     * @brief Affecte un secouriste libre (change son état à occupé).
     */
    virtual void affecter();

    /**
     * @brief Libère un secouriste (change son état à libre).
     */
    virtual void liberer();
   

    void ajouterSecouriste(std::shared_ptr<Secouriste> sec);
    void retirerSecouriste(const std::string& idSecouriste);
    const std::vector<std::shared_ptr<Secouriste>>& getEquipeSecouristes() const;

    virtual std::string toString() const;
    virtual std::string genererRequeteSQL() const;
};

#endif // RESSOURCE_HPP

