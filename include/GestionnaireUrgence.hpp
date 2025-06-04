#ifndef GESTIONNAIRE_URGENCE_HPP
#define GESTIONNAIRE_URGENCE_HPP

/*!
 * \file GestionnaireUrgence.hpp
 * \brief Déclaration de la classe GestionnaireUrgence
 */

#include <memory>
#include "Urgence.hpp"
#include "Intervention.hpp"
#include "QuestionnaireUrgence.hpp"
#include "Demandeur.hpp"
#include "JournalSysteme.hpp"
#include "Notification.hpp"
#include "AllocateurRessources.hpp"

/*!
 * \class GestionnaireUrgence
 * \brief Classe contrôleur principale du système SGU
 *
 * Cette classe représente le cœur de la gestion d’urgences.
 * Elle permet d’analyser, d’enregistrer et de prioriser les urgences,
 * de notifier les parties concernées, et de synchroniser les données
 * avec des systèmes externes.
 */
class GestionnaireUrgence {
public:
    /*!
     * \brief Constructeur par défaut
     */
    GestionnaireUrgence();

    /*!
     * \brief Analyse les données d’une urgence signalée
     *
     * Cette méthode traite les informations d'une urgence reçue
     * et prépare sa gestion.
     */
    void analyserUrgence();

    /*!
     * \brief Enregistre une nouvelle urgence dans le système
     *
     * Permet de stocker l’urgence et de déclencher le traitement.
     */
    void enregistrerUrgence();

    /*!
     * \brief Classe les urgences par ordre de priorité
     *
     * L’ordre de traitement est déterminé selon le niveau de gravité,
     * la localisation, ou d'autres critères pertinents.
     */
    void prioriser();

    /*!
     * \brief Notifie les services ou utilisateurs concernés
     *
     * Utilise le système de Notification pour alerter les acteurs impliqués.
     */
    void notifier();

    /*!
     * \brief Synchronise les données avec les systèmes externes
     *
     * Peut être utilisé pour des mises à jour intermodules ou externes.
     */
    void synchroniserDonneesExternes();

};

#endif // GESTIONNAIRE_URGENCE_HPP

