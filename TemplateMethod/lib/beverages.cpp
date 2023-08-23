#include <algorithm>
#include <iostream>
#include "beverages.hpp"
using namespace Starbuzz;

void CoffeineBeverage::make() const {
    boil_water();
    brew();
    pour_in_cup();
    if (use_condiments())
        add_condiments();
}

void CoffeineBeverage::boil_water() const {
    std::cout << "Boiling water...\n";
}

void CoffeineBeverage::pour_in_cup() const {
    std::cout << "Pouring into cup\n";
}

bool CoffeineBeverage::use_condiments() const {
    return true;
}

void Coffee::brew() const {
    std::cout << "Dripping Coffee through filter\n";
}

void Coffee::add_condiments() const {
    std::cout << "Prepearing sugar and milk...\n";
    std::cout << "Adding sugar and milk for coffee\n";
}

bool Coffee::use_condiments() const {
    std::cout << "Would you like milk and sugar with your coffee?[Y/n]: ";
    char answer;
    std::cin >> answer;
    answer = std::tolower(answer);
    return answer == ' ' || answer == 'y';
}

void Tea::brew() const {
    std::cout << "Wait for tea to brew...\n";
}

void Tea::add_condiments() const {
    std::cout << "Prepearing a lemon for tea...\n";
    std::cout << "Adding lemon\n";
}
