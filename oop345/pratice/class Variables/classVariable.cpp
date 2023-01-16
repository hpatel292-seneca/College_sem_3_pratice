#include<iostream>
#include"classVariable.h"

using namespace std;
unsigned Horse::noHorses = 0;  // must define type "unsigned"

// when initilize variables in function prototype, they mush follow the order they declared
Horse::Horse(unsigned horseAge) : age{horseAge}, id{++Horse::noHorses} {} // need colon ":" after prototype and initialization require to be comma seperated

Horse::~Horse() {--Horse::noHorses;}

void Horse::display() const{
    std::cout << "Horse " << id << " is " << age << " years old\n";
}

// Class Variables - Implementation
// classVariable.cpp

// #include <iostream>
// #include "classVariable.h"

// unsigned Horse::noHorses = 0; // this is how class variables are initialized

// // the constructor increments the class variable, but is not initialize it
// Horse::Horse(unsigned a) : age{a}, id{++Horse::noHorses} {}

// // the destructor decrements the class variable
// Horse::~Horse() { --Horse::noHorses; }

// void Horse::display() const
// {
//     std::cout << "Horse " << id << " is " << age << " years old\n";
// }