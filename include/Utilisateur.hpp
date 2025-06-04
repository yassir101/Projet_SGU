/**
 * @file Utilisateur.hpp
 * @brief Classe abstraite représentant un utilisateur du système SGU.
 */

#ifndef UTILISATEUR_HPP
#define UTILISATEUR_HPP

#include <string>

/**
 * @class Utilisateur
 * @brief Classe de base abstraite pour tous les utilisateurs du SGU.
 *
 * Cette classe fournit les attributs communs aux utilisateurs (id, nom).
 * Elle sert de superclasse pour les rôles spécifiques : Demandeur, Administrateur, Secouriste.
 */
class Utilisateur {
protected:
    std::string id;   ///< Identifiant unique de l'utilisateur
    std::string nom;  ///< Nom de l'utilisateur

public:
    /**
     * @brief Constructeur de base
     * @param id Identifiant de l'utilisateur
     * @param nom Nom de l'utilisateur
     */
    Utilisateur(const std::string& id, const std::string& nom);

    /**
     * @brief Destructeur virtuel
     */
    virtual ~Utilisateur() = default;

    /**
     * @brief Récupère l'identifiant de l'utilisateur
     * @return Identifiant
     */
    std::string getId() const;

    /**
     * @brief Récupère le nom de l'utilisateur
     * @return Nom
     */
    std::string getNom() const;

    /**
     * @brief Définit un nouvel identifiant
     * @param nouvelId Identifiant à affecter
     */
    void setId(const std::string& nouvelId);

    /**
     * @brief Définit un nouveau nom
     * @param nouveauNom Nom à affecter
     */
    void setNom(const std::string& nouveauNom);
    
    /**
 	* @brief Renvoie le type de l'utilisateur (Demandeur, Secouriste, etc.)
 	* @return Type textuel de l'utilisateur
 	*/
virtual std::string getTypeUtilisateur() const = 0;

};

#endif // UTILISATEUR_HPP
