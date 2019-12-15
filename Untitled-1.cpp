#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    for (int i = 0; i < 5; i++)
    {
        cout<<"Hello World!"<<endl;
    }

    fprintf(stdout, "Fuck you");
    getchar();
    return 0;
}