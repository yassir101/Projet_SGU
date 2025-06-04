#ifndef SECOURISTE_HPP
#define SECOURISTE_HPP

#include "Utilisateur.hpp"
#include <string>
#include <iostream>

/**
 * @class Secouriste
 * @brief Utilisateur intervenant sur le terrain pour gérer les urgences.
 *
 * Le secouriste hérite de la classe Utilisateur et ajoute des attributs
 * spécifiques comme le matricule et la spécialité.
 */
class Secouriste : public Utilisateur {
private:
    std::string matricule;   ///< Matricule unique du secouriste
    std::string specialite;  ///< Spécialité du secouriste (ex: incendie, médical...)

public:
    /**
     * @brief Constructeur
     * @param id Identifiant
     * @param nom Nom
     * @param matricule Matricule interne
     * @param specialite Spécialité du secouriste
     */
    Secouriste(const std::string& id, const std::string& nom,
               const std::string& matricule, const std::string& specialite);

    /**
     * @brief Met à jour le statut de l’intervention en cours.
     */
    void mettreAJourStatut() const;

    /**
     * @brief Confirme que l’intervention est bien prise en charge.
     */
    void confirmerIntervention() const;

    /**
     * @brief Transmet sa position actuelle au système.
     */
    void transmettrePosition() const;

    /**
     * @brief Affiche une description textuelle du secouriste.
     * @return Description au format lisible.
     */
    std::string toString() const;

    /**
     * @brief Génère une commande SQL d’insertion du secouriste.
     * @return Requête SQL formatée.
     */
    std::string genererRequeteSQL() const;
    
    /**
 	* @brief Retourne le type d'utilisateur (ici "Secouriste")
 	* @return "Secouriste"
 	*/
	std::string getTypeUtilisateur() const override;


    /// @name Accesseurs
    /// @{
    std::string getMatricule() const;
    void setMatricule(const std::string& m);

    std::string getSpecialite() const;
    void setSpecialite(const std::string& s);
    /// @}
};

#endif // SECOURISTE_HPP

