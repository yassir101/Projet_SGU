#include <iostream>
#include <cassert>
#include "../include/Statistiques.hpp"

int main() {
    Statistiques stats;

    assert(stats.getTotal() == 0);
    std::cout << "Total initial : " << stats.getTotal() << std::endl;

    stats.calculer(); // Devrait incrémenter de 5

    assert(stats.getTotal() == 5);
    std::cout << "Total après calcul : " << stats.getTotal() << std::endl;

    stats.setTotal(42);
    assert(stats.getTotal() == 42);

    std::cout << "[OK] test_statistiques" << std::endl;
    return 0;
}
