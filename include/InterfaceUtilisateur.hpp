/**
 * @file InterfaceUtilisateur.hpp
 * @brief Classe représentant l'interface utilisateur du SGU.
 */

#ifndef INTERFACEUTILISATEUR_HPP
#define INTERFACEUTILISATEUR_HPP

#include <iostream>

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
     */
    void afficherStatut() const;
};

#endif // INTERFACEUTILISATEUR_HPP
