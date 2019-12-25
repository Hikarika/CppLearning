#include <cstdio>
#include <iostream>
#include "header_test.h"

using namespace std;

int main(int argc, char *args[])
{
    int i = 2345;
    int j = 12;
    char a[25] = "Want to go home";
    // cin >> i;
    i_swap(i,j);
    cout << showpoint << static_cast<double> (i) << " <- i, j -> " << j << endl;
    cout << a;
    system("pause");
    return 0;
}