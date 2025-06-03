#ifndef JOURNAL_SYSTEME_HPP
#define JOURNAL_SYSTEME_HPP

#include <string>
#include <vector>
#include <memory>
#include "Intervention.hpp"

/*!
 * \class JournalSysteme
 * \brief Classe responsable de la journalisation des événements du SGU
 *
 * Le JournalSysteme permet de consigner les actions et événements importants
 * tels que les interventions, les erreurs ou les annulations.
 */
class JournalSysteme {
private:
    std::vector<std::string> journal;  ///< Liste des événements enregistrés

public:
    /*!
     * \brief Constructeur par défaut
     */
    JournalSysteme();

    /*!
     * \brief Enregistre un événement générique dans le journal système
     * \param evenement Chaîne représentant l’événement
     */
    void enregistrerEvenement(const std::string& evenement);

    /*!
     * \brief Affiche l’ensemble des événements enregistrés
     */
    void afficherJournal() const;

    /*!
     * \brief Journalise l’annulation d’une intervention
     * \param i Référence vers l’intervention annulée
     */
    void logAnnulation(const Intervention& i);
};

#endif // JOURNAL_SYSTEME_HPP