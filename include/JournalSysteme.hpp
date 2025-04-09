#ifndef JOURNAL_SYSTEME_HPP
#define JOURNAL_SYSTEME_HPP

/*!
 * \file JournalSysteme.hpp
 * \brief Déclaration de la classe JournalSysteme
 */

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
public:
    /*!
     * \brief Constructeur par défaut
     */
    JournalSysteme();

    /*!
     * \brief Enregistre un événement générique dans le journal système
     */
    void enregistrerEvenement();

    /*!
     * \brief Affiche l’ensemble des événements enregistrés
     */
    void afficherJournal();

    /*!
     * \brief Journalise l’annulation d’une intervention
     * \param i Référence vers l’intervention annulée
     */
    void logAnnulation(Intervention& i);
};

#endif // JOURNAL_SYSTEME_HPP

