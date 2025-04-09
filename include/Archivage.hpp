#ifndef ARCHIVAGE_HPP
#define ARCHIVAGE_HPP

/*!
 * \file Archivage.hpp
 * \brief Déclaration de la classe Archivage
 */

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "Intervention.hpp"
#include "Rapport.hpp"
#include "Statistiques.hpp"

/*!
 * \class Archivage
 * \brief Gère l’archivage et l’analyse des interventions
 *
 * Cette classe permet d’archiver les interventions terminées,
 * de les retrouver via des filtres et de générer des rapports
 * ou statistiques à partir de l’historique.
 */
class Archivage {
private:
    std::vector<Intervention> historiques; /*!< Liste des interventions archivées */
    
public:
    /*!
     * \brief Archive une intervention
     * \param interv L’intervention à archiver
     */
    void archiver(const Intervention& interv);

    /*!
     * \brief Recherche des interventions selon des filtres
     * \param filtres Critères de recherche
     * \return Liste d’interventions correspondant aux filtres
     */
    std::vector<Intervention> rechercher(const std::map<std::string, std::string>& filtres);

    /*!
     * \brief Génère les statistiques à partir des interventions archivées
     * \return Objet Statistiques contenant les résultats calculés
     */
    Statistiques genererStatistiques();

    /*!
     * \brief Génère un rapport basé sur l’historique des interventions
     * \return Rapport synthétique
     */
    Rapport genererRapport();
    
    /// @brief Accède à la liste des interventions archivées (lecture seule)
    const std::vector<Intervention>& getHistoriques() const;

};

#endif // ARCHIVAGE_HPP

