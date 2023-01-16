
#include <iostream>
#include "classVariable.h"

unsigned Horse::noHorses = 0;  // initialize the class variable

Horse::Horse(unsigned a) : age{a}, id{++noHorses} {}

Horse::~Horse() { --noHorses; }

void Horse::display() const
{
    std::cout << "Horse " << id << " is " << age << " years old\n";
}

unsigned Horse::howMany() { return noHorses; }