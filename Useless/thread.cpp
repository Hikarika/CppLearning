#include <cstdio>
#include <iostream>
#include <thread>

using namespace std;

void func()
{
    cout << "Thread here." << endl;
}

int main(int argc, char * args[])
{
    thread t1(func);
    cout << "Create Thread" << endl;
    t1.detach();
    system("pause");
    return 0;
}