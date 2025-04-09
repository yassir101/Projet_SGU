#ifndef STATISTIQUES_HPP
#define STATISTIQUES_HPP

/*!
 * \file Statistiques.hpp
 * \brief Déclaration de la classe Statistiques
 */

/*!
 * \class Statistiques
 * \brief Gère les statistiques globales du système SGU
 *
 * Cette classe permet de calculer et stocker les statistiques
 * liées aux interventions archivées.
 */
class Statistiques {
private:
    int total; /*!< Nombre total d’interventions ou valeur statistique globale */
    
public:
    /*!
     * \brief Constructeur par défaut
     */
    Statistiques();

    /*!
     * \brief Calcule les statistiques à partir des données archivées
     */
    void calculer();
    
    /// @brief Accesseur du total
    int getTotal() const;

    /// @brief Modificateur du total
    void setTotal(int nouveauTotal);
};

};

#endif // STATISTIQUES_HPP



