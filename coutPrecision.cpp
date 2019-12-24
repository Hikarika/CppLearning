#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char * args[])
{
    float a = 12.12f;
    float b = 32.12f;
    double mole = 602200000000000000.0;
    float grade = 97.153f;

    cout.setf(ios::scientific);
    cout << mole << endl;
    cout.setf(ios::fixed);
    cout.width(15);
    cout << setfill('?') << setw(99) << grade << endl;
    

    cout << "round 2" << endl;
    system("pause");
    return 0;
}