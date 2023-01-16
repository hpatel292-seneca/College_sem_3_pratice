#include <iostream>
#include "classVariable.h"

int main()
{
    // no need for an instance to access the class variable
    std::cout << Horse::noHorses << " horses\n";

    {
        // create a local scope
        Horse silver(3), northernDancer(4);

        silver.display();
        northernDancer.display();

        std::cout << Horse::noHorses << " horses" << std::endl;
        std::cout << silver.noHorses << " horses" << std::endl;
        std::cout << northernDancer.noHorses << " horses" << std::endl;

        // local scope ends: variables created in this scope will be destroyed
    }

    std::cout << Horse::noHorses << " horses" << std::endl;
    return 0;
}