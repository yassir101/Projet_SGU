#include <iostream>
#include <cassert>
#include "../include/Notification.hpp"
#include "../include/Demandeur.hpp"

void testConstructeursEtAccesseurs() {
    Notification n1;
    assert(n1.getMessage() == "");

    Notification n2("Urgence en cours");
    assert(n2.getMessage() == "Urgence en cours");

    n2.setMessage("Mise à jour : gravité critique");
    assert(n2.getMessage() == "Mise à jour : gravité critique");

    std::cout << "[OK] testConstructeursEtAccesseurs" << std::endl;
}

void testEnvoi() {
    Demandeur d("D001", "Alice", "0612345678");
    Notification notif("Intervention déclenchée");
    notif.envoyer(d);  // Affiche message

    std::cout << "[OK] testEnvoi" << std::endl;
}

int main() {
    testConstructeursEtAccesseurs();
    testEnvoi();

    std::cout << "Tous les tests Notification passent" << std::endl;
    return 0;
}
