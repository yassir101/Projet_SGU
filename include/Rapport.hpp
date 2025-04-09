#ifndef RAPPORT_HPP
#define RAPPORT_HPP

/**
 * @file Rapport.hpp
 * @brief Déclaration de la classe Rapport
 */

#include <string>

/**
 * @class Rapport
 * @brief Classe représentant un rapport généré par le système.
 *
 * Cette classe contient le contenu textuel d’un rapport, et fournit
 * des méthodes pour l’exporter dans différents formats.
 */
class Rapport {
private:
    std::string contenu; /*!< Contenu textuel du rapport */

public:
    /// @brief Constructeur par défaut
    Rapport();

    /// @brief Exporte le rapport au format CSV
    void exporterCSV();

    /// @brief Exporte le rapport au format PDF
    void exporterPDF();

    /// @brief Accesseur du contenu du rapport
    std::string getContenu() const;

    /// @brief Modifie le contenu du rapport (si nécessaire)
    void setContenu(const std::string& nouveauContenu);
};

#endif // RAPPORT_HPP

