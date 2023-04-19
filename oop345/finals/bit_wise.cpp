// The bit-wise negation operator (~) converts its operand to its one's complement. The operand may be of integral or unscoped enumerated type. The result of the operation is a prvalue.

// left shift
// let a = 5; in binary a = 101
// if (a << 2) left shift for 2 fields ==> 10100 in binary ==> 20 ==> 5*(2^2) = 20

// right shift
// let a = 5; in binary a = 101
// if (a >> 2) right shift for 2 fields ==> 1 in binary ==> 1 in decimal.

// bit-wise and
// The rules for an 'and' comparison are:
// if both bit values are 1, the resultant bit value is 1
// otherwise, the resultant bit value is 0

// Bit-wise and
// and.cpp

// #include <iostream>

// int main ()
// {   //                           8  4  2  1
//   unsigned char u = 10u; 
//   unsigned char a = 11u;
//   unsigned char v = 240u;                      
                        

//   std::cout << (unsigned)a << " & " << (unsigned)v << " = " << (a & v) << '\n';
// }

#include <iostream>
using namespace std;

int main() {
    int num = 11; // Change this value to test different numbers
    cout << "Value " << (num | (245)) << endl;
    if (num & (245)) {
        cout << num << " is greater than 10." << endl;
    } else {
        cout << num << " is not greater than 10." << endl;
    }
    return 0;
}
