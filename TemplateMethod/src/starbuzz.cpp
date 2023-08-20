#include <iostream>
#include "beverages.hpp"

int main()
{
    using namespace Starbuzz;

    Coffee coffee;
    Tea tea;

    std::cout << "Make coffee...\n";
    coffee.make();
    std::cout << "Done!\n\n";

    std::cout << "Make tea...\n";
    tea.make();
    std::cout << "Done!\n\n";

    return 0;
}