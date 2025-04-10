#include "InterfaceUtilisateur.hpp"

void InterfaceUtilisateur::afficherMenu() const {
    std::cout << "====== MENU SGU ======" << std::endl;
    std::cout << "1. Signaler une urgence" << std::endl;
    std::cout << "2. Quitter" << std::endl;
}

void InterfaceUtilisateur::afficherStatut(const std::string& statut) const {
    std::cout << "[STATUT] " << statut << std::endl;
}
