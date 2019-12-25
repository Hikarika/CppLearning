#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#define CONFIG_FILE "Lab_3\\CONFIG.txt"

using namespace std;

//struct for config file, makes transportation easier
struct config {
    string m_input_file;
    string m_input_type;
    int m_max_file_entries;
    string m_output_file;
};

//use a template to get number from string
template<typename T>
T t_getnum(string& str)
{
    stringstream sstream;
    T ret;
    sstream << str;
    sstream >> ret;
    return ret;
}

//custom swap function, swap index i and index j in specified array
template<typename T>
void mySwap(T* arr, int i, int j)
{
    T temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//simple bubble sort to sort the input array
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

//check file if open or not, if not, exit with code 1
void check_open_condition(ifstream & f_ifstream)
{
    if(! f_ifstream.is_open())
    {
        cout << "error opening" << endl;
        f_ifstream.close();

        getchar();
        exit(1);
    }
    cout << "File Opened." << endl;
}

//read config from CONFIG_FILE
//and identify which type will be input
config read_config()
{
    ifstream f_config(CONFIG_FILE);
    config config;
    int index = 0;
    char buffer[128];

    check_open_condition(f_config);

    while(!f_config.eof() || index < 4)
    {
        f_config.getline(buffer, 128);
        switch (index)
        {
        case 0:
            config.m_input_file = buffer;
            break;
        case 1:
            config.m_input_type = buffer;
            break;
        case 2:
            config.m_max_file_entries = atoi(buffer);
            break;
        case 3:
            config.m_output_file = buffer;
            break;
        default:
            cout << "config error." << endl;
            break;
        }
        index++;
    }

    return config;
}

//read then sort then output to file
template<typename T>
void read_file_sort_output(ifstream& f_num, const int i_max_input, string fout)
{
    T num[i_max_input];
    char buffer[128];
    int real_size = 0;
    string s_buf;
    while(!f_num.eof())
    {
        f_num.getline(buffer,128);
        s_buf = buffer;
        num[real_size] = t_getnum<T>(s_buf);
        real_size++;
    }

    mySort<T>(num, real_size);

    ofstream f_output(fout,ios::out);
    for(int i = 0; i < real_size; i++)
    {
        f_output << num[i] << endl;
        cout << num[i] << endl;
    }

    f_output.close(); // close file stream
}

int main(int argc, char * args[])
{
//get necessary information to begin adn declaration
    const config & config = read_config();
    ifstream f_num(config.m_input_file);
    int i_max_input = config.m_max_file_entries;
    string fout = config.m_output_file;

    check_open_condition(f_num);

//identify differetn primitive data type.
    cout << "after sort" << endl;
    if(config.m_input_type == "int") { // for int
        cout << "int" << endl;
        read_file_sort_output<int>(f_num, i_max_input, fout);
    } else if (config.m_input_type == "float") { // for float
        cout << "float" << endl;
        read_file_sort_output<float>(f_num, i_max_input, fout);
    } else if (config.m_input_type == "double") { // for double 
        cout << "double" << endl;
        read_file_sort_output<double>(f_num, i_max_input, fout);
    } else if (config.m_input_type == "long") { // for long
        cout << "long" << endl;
        read_file_sort_output<long>(f_num, i_max_input, fout);
    } else {
        cout << "config error" << endl; // for error
        getchar();
        exit(1);
    }
    f_num.close(); // close file stream

    getchar();
    return 0;
}