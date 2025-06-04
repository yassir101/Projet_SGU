#ifndef GESTIONNAIRE_URGENCE_HPP
#define GESTIONNAIRE_URGENCE_HPP

/*!
 * \file GestionnaireUrgence.hpp
 * \brief Contrôleur de traitement des urgences dans le SGU
 */

#include <memory>
#include <vector>
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
private:
    std::shared_ptr<JournalSysteme> journal;
    std::shared_ptr<AllocateurRessources> allocateur;
    std::vector<std::shared_ptr<Urgence>> urgences;
    
public:
    /*!
     * \brief Constructeur par défaut
     */
    GestionnaireUrgence();

    /*!
     * \brief Analyse les données d’une urgence signalée
     * \param urgence Objet urgence à analyser
     */
    void analyserUrgence(const std::shared_ptr<Urgence>& urgence);

    /*!
     * \brief Enregistre une nouvelle urgence dans le système
     * \param urgence Objet urgence à stocker
     */
    void enregistrerUrgence(const std::shared_ptr<Urgence>& urgence);

    /*!
     * \brief Calcule la priorité d'une urgence
     * \param urgence L'urgence à évaluer
     * \return Valeur de priorité
     */
    int calculerPriorite(const std::shared_ptr<Urgence>& urgence) const;

    /*!
     * \brief Classe les urgences par ordre de priorité
     */
    void prioriser();

    /*!
     * \brief Notifie les services ou utilisateurs concernés
     * \param urgence L'urgence pour laquelle notifier
     */
    void notifier(const std::shared_ptr<Urgence>& urgence);

    /*!
     * \brief Synchronise les données avec les systèmes externes
     */
    void synchroniserDonneesExternes();
};

#endif // GESTIONNAIRE_URGENCE_HPP

