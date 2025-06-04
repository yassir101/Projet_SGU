#ifndef RAPPORT_HPP
#define RAPPORT_HPP

/**
 * @file Rapport.hpp
 * @brief Déclaration de la classe Rapport
 */

#include <string>

/**
 * @class Rapport
 * @brief Classe représentant un rapport généré par le système SGU.
 */
class Rapport {
private:
    std::string titre;     ///< Titre du rapport
    std::string contenu;   ///< Contenu textuel du rapport

public:
    /**
     * @brief Constructeur par défaut
     */
    Rapport();

    /**
     * @brief Constructeur avec titre et contenu
     * @param titre Titre du rapport
     * @param contenu Contenu du rapport
     */
    Rapport(const std::string& titre, const std::string& contenu);

    /**
     * @brief Exporte le rapport au format CSV (affichage console pour l’instant)
     */
    void exporterCSV() const;

    /**
     * @brief Exporte le rapport au format PDF (simulation)
     */
    void exporterPDF() const;

    /**
     * @brief Retourne le contenu textuel du rapport
     */
    std::string getContenu() const;

    /**
     * @brief Retourne le titre du rapport
     */
    std::string getTitre() const;

    /**
     * @brief Met à jour le contenu
     * @param nouveauContenu Nouveau texte à insérer
     */
    void setContenu(const std::string& nouveauContenu);

    /**
     * @brief Met à jour le titre
     * @param nouveauTitre Nouveau titre du rapport
     */
    void setTitre(const std::string& nouveauTitre);

    /**
     * @brief Retourne une chaîne complète représentant le rapport
     * @return Texte complet formaté
     */
    std::string toString() const;
};

#endif // RAPPORT_HPP

