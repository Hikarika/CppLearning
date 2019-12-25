#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

template <class T>
T string_to_num(const string & str)
{
    istringstream iss(str);
    T num;
    iss >> num;
    return num;
}

char menu();
void manipulate(char cha);
float fetch_float();
class T string_to_num(const string & str);

int main(int argc, char *argv[])
{
    manipulate(menu());
    system("pause");
    return 0;
}

char menu()
{
    char a;
    cout << "Enter your demand" << endl;
    cout << "F : F -> C" << endl;
    cout << "C : C -> F" << endl;
    cin >> a;
    return a;
}

void manipulate(char cha)
{
    float c, f, ans;
    switch (toupper(cha))
    {
    case 'F':
        cout << "Enter c to transform" << endl;
        c = fetch_float();
        ans = c * 1.8 + 32;
        break;
    case 'C':
        cout << "Enter F to transform" << endl;
        f = fetch_float();
        ans = (f-32) / 1.8;
        break;
    default:
        cout << "Answer is " << to_string(ans) << endl;
        break;
    }
}

float fetch_float()
{
    string ret;
    cin >> ret;
    float ret_f = string_to_num<float>(ret);
    return ret_f;
}