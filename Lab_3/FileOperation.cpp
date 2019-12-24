#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
using namespace std;

int i_getnum(string str)
{
    stringstream sstream;
    int ret;
    sstream << str;
    sstream >> ret;
    return ret;
}

template <class T>
int size(T& arr)
{
    return sizeof(arr) / sizeof(arr[0]);
}

template<typename T>
void mySwap(T* arr, int i, int j)
{
    T temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename T>
void mySort(T* arr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
                mySwap(arr, j + 1, j);
        }
    }
}

void check_open_condition(ifstream & fin)
{
    if(! fin.is_open())
    {
        cout << "Error opening" << endl;
        fin.close();

        getchar();
        exit(1);
    }
}

int main(int argc, char * args[])
{
    char buffer[256];
    int num[128];
    int real_size = 0;
    string s_buf;
    ifstream f_num("Lab_3\\number.txt");

    check_open_condition(f_num);

    cout << size(num) << endl;
    cout << "File opened" << endl;
    
    while(!f_num.eof())
    {
        f_num.getline(buffer,256);
        // cout << buffer[0] << buffer[1] << endl;
        s_buf = buffer;
        num[real_size] = i_getnum(s_buf);
        real_size++;
    }

    mySort<int>(num, real_size);

    ofstream fout("Lab_3\\output.txt",ios::out);

    cout << "after sort" << endl;
    for(int i = 0; i < real_size; i++)
    {
        fout << num[i] << endl;
        cout << num[i] << endl;
    }
    getchar();
    return 0;
}