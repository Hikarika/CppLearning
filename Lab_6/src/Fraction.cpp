#include <iostream>
#include "Fraction.h"

using std::cin;
using std::cout;
using std::endl;

///////////Zero_Tolerance/////////
double Fraction::zero_tolerance = 0.0001;

///////////CONSTRUCTORS///////////
Fraction::Fraction(): m_Numerator(0), m_Denominator(1) {}

Fraction::Fraction(const int num): m_Numerator(num), m_Denominator(1) {}

Fraction::Fraction(const int num, const int den): m_Numerator(num), m_Denominator(den) 
{
    if(m_Denominator == 0) 
        m_Denominator = 1;
}

Fraction::Fraction(const Fraction & source): m_Numerator(source.m_Numerator), m_Denominator(source.m_Denominator) {}


///////////FUNCTIONS//////////////
///////////MEMBER/////////////////
//Description: Fraction's numerator and denominator are set to the users' input
//  (unless they enter a denominator of zero!)
void Fraction::readin() 
{
    cout<<"Enter numerator:"<<endl;
    cin>>m_Numerator;
    cout<<"Enter denominator:"<<endl;
    cin>>m_Denominator;
    return;
}

//Fraction is print to cout in (N/D) format (numerator / denominator)
void Fraction::print() const
{
    cout << "(" << m_Numerator << "/" << m_Denominator << ")" << endl;
    return;
}

//Post: A new fraction is returned where
//     the new numerator is the calling object's denominator
//     and the new denominator is the calling object's numerator
Fraction Fraction::reciprocal() const
{
    return Fraction(m_Denominator,m_Numerator);
}

//Post: Calling object's numerator and denominator are individually multiplied by m
void Fraction::unreduce(const int m)
{
    if(m != 0)
    {
        m_Denominator *= m;
        m_Numerator *= m;
    }
    return;
}

///////////////// ACCESSOR FUNCTIONS //////////////////
double Fraction::getZeroTol() 
{
    return zero_tolerance;
}

///////////////// MUTATOR FUNCTIONS ////////////////////
void Fraction::setNumer(int n)
{
    m_Numerator = n;
}

bool Fraction::setDenom(int d)
{
    if(d != 0)
    {
        m_Denominator = d;
        return true;
    }
    else
    {
        return false;
    }
}

void Fraction::setZeroTol(double d)
{
    zero_tolerance = d;
    return;
}

Fraction & Fraction::operator= (const Fraction & rhs)
{
    m_Numerator = rhs.m_Numerator;
    m_Denominator = rhs.m_Denominator;
    return (*this);
}

Fraction & Fraction::operator*= (const Fraction & rhs)
{
    m_Numerator *= rhs.m_Numerator;
    m_Denominator *= rhs.m_Denominator;
    return (*this);
}

ostream & operator<< (ostream & out, Fraction & f)
{
    if(f.m_Denominator == 0)
    {
        out << "Error: denominator is 0" << endl;
        exit(0);
    }
    else if (f.m_Numerator % f.m_Denominator == 0)
        out << f.m_Numerator / f.m_Denominator;
    else
        out << f.m_Numerator << "/" << f.m_Denominator;
    return out;
}

Fraction operator* (const Fraction & lhs, const Fraction & rhs)
{
    Fraction temp;
    temp.m_Numerator = lhs.m_Numerator * rhs.m_Numerator;
    temp.m_Denominator = lhs.m_Denominator * rhs.m_Denominator;
    return temp;
}

bool operator== (const Fraction & lhs, const Fraction & rhs)
{
    return (lhs.m_Numerator * rhs.m_Denominator) == (lhs.m_Denominator * rhs.m_Numerator);
}

bool operator> (const Fraction & lhs, const Fraction & rhs)
{
    return (lhs.m_Numerator * rhs.m_Denominator) > (rhs.m_Numerator * lhs.m_Denominator);
}

bool operator< (const Fraction & lhs, const Fraction & rhs)
{
    return (lhs.m_Numerator * rhs.m_Denominator) < (rhs.m_Numerator * lhs.m_Denominator);
}

void invert(Fraction & f)
{
    int temp;
    if(f.m_Numerator != 0)
    {
        temp = f.getDenom();
        f.setDenom(f.m_Numerator);
        f.setNumer(temp);
    }
}

Fraction multFracs(const Fraction & lhs, const Fraction & rhs)
{
    Fraction ret;
    ret.setNumer(lhs.getNumer() * rhs.getNumer());
    ret.setDenom(lhs.getDenom() * rhs.getDenom());
    return ret;
}
