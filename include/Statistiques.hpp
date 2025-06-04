#ifndef STATISTIQUES_HPP
#define STATISTIQUES_HPP

/*!
 * \file Statistiques.hpp
 * \brief Déclaration de la classe Statistiques
 */

#include <string>
#include <map>
#include <vector>
#include "Intervention.hpp"

/*!
 * \class Statistiques
 * \brief Gère les statistiques globales du système SGU
 *
 * Cette classe calcule et stocke des indicateurs à partir des interventions archivées.
 */
class Statistiques {
private:
    int total; ///< Nombre total d’interventions
    std::map<std::string, int> parType; ///< Nombre par type d’urgence
    std::map<std::string, int> parStatut; ///< Répartition des statuts
    double graviteMoyenne; ///< Gravité moyenne pondérée

public:
    /*!
     * \brief Constructeur par défaut
     */
    Statistiques();

    /*!
     * \brief Calcule les statistiques à partir des données archivées
     * \param historique Liste des interventions archivées
     */
    void calculer(const std::vector<Intervention>& historique);

    /*!
     * \brief Représente les statistiques sous forme de chaîne
     * \return Résumé textuel des statistiques
     */
    std::string toString() const;

    /// @name Accesseurs
    /// @{
    int getTotal() const;
    double getGraviteMoyenne() const;
    std::map<std::string, int> getParType() const;
    std::map<std::string, int> getParStatut() const;
    /// @}
};

#endif // STATISTIQUES_HPP

