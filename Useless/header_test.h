#ifndef _HEADER_TEST
#define _HEADER_TEST

template <typename T>
void i_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

#endif