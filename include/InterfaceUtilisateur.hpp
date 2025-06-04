/**
 * @file InterfaceUtilisateur.hpp
 * @brief Classe représentant l'interface utilisateur du SGU.
 */

#ifndef INTERFACEUTILISATEUR_HPP
#define INTERFACEUTILISATEUR_HPP

#include <iostream>
#include <string>
#include <memory>
#include "Urgence.hpp"

/**
 * @class InterfaceUtilisateur
 * @brief Gère l’affichage des menus et la saisie des données utilisateur.
 */
class InterfaceUtilisateur {
public:
    /**
     * @brief Affiche le menu principal du système.
     */
    void afficherMenu() const;

    /**
     * @brief Affiche un message de statut générique.
     * @param statut Texte à afficher à l'utilisateur.
     */
    void afficherStatut(const std::string& statut) const;

    /**
     * @brief Collecte les informations d'une urgence auprès de l'utilisateur.
     * @return Un pointeur vers une instance de sous-classe de Urgence.
     */
    std::unique_ptr<Urgence> collecterUrgence() const;
};

#endif // INTERFACEUTILISATEUR_HPP

