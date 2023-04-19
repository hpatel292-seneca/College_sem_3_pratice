// #include <iostream>

// #define NCOLS 3

// void foo(int a[][NCOLS], int r, int c);

// int main ()
// {
//   int a[2][NCOLS] = {{11, 12, 13}, {21, 22, 23}};
//   foo (a, 2, 3);
// }

// void foo(int a[][NCOLS], int r, int c)
// {
//   for (int i = 0; i < r; i++)
//   {
//     for (int j = 0; j < c; j++)
//       std::cout << a[i][j] << ' ';
//     std::cout << std::endl;
//   }
// }
// // Since the compiler assumes row-major order, the function does not require the row dimension.
// // Note the difference in type between a and &a[0][0]. Although both refer to the same address, a is of type int** and &a[0][0] is of type int*.


// coding 2D array
#include<iostream>
#include<iomanip>
int main(){
    int** a;
    int r, c;

    std::cout << "Number of rows : ";
    std::cin >> r;
    std::cout << "Number of columns : ";
    std::cin >> c;

    a = new int*[r];

    for (size_t i = 0; i < r; i++)
    {
        a[i] = new int[c];
    }

    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            a[i][j] = (i + 1) * (j + 1);
        }
    }
    
    for (int i = 0; i < r; i++)
  {
    // std::cout << std::setw(3) << i + 1;
    for (int j = 0; j < c; j++)
      std::cout << std::setw(4) << a[i][j];
    std::cout << std::endl;
  }

  for (int i = 0; i < r; i++)
    delete [] a[i]; // de-allocate row i
  delete [] a; // de-allocate pointers to rows
}
