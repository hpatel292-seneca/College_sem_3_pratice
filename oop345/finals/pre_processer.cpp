// object-like macros
//->An object-like macro defines an unmodifiable replacement text. is a normal macros where a symbolic text is replaced with replacement text.
// function-like macros
//-> it is a function like micros which take arguments and use that arguments in the replacement text
// pre-defined macros
// -> is a system built micros. For Example, __date__, __file__
// Function-like macros provide efficient and flexible solutions. They avoid the overhead of function calls and do not impose type constraints on placeholder names.
// To avoid such precedence errors, we wrap each placeholder in the definition's replacement text within parentheses
// __FILE__ name of the current source file expressed as a string literal,
// __DATE__ calendar date of the pre-processing expressed as a string literal (Mmm dd yyyy),
// __TIME__ time of the pre-processing expressed as a string literal (hh:mm:ss),
// #include <iostream>
// #define PI 3.14
// #define AREA(R) PI * R * R // function-like macro

// int main()
// {
//   double area = AREA(2.35);
//   std::cout << "Area is " << area << std::endl;
//   return 0;
// }


//Logical directives insert source code based on satisfaction of a pre-processor condition. They take the form

// #if CONDITION
//   group of statements
// #elif CONDITION
//   group of statements
// #else
//   group of statements
// #endif

// A definitional directive checks for the existence of a symbolic name and takes either of two forms:
//definitional construct
//functional directive

// #ifdef SYMBOLIC_NAME
//   group of statements
// #endif

// #ifndef SYMBOLIC_NAME
//   group of statements
// #endif

#include <iostream>

int main()
{
  std::cout << "The name of the source file    is " << __FILE__ << std::endl;
  std::cout << "The date of its pre-processing is " << __DATE__ << std::endl;
  std::cout << "The time of its pre-processing is " << __TIME__ << std::endl;
  return 0;
}