#ifndef FRACTION_H
#define FRACTION_H

#include <ostream>
using std::ostream;

class Fraction
{
public:
    ///////////CONSTRUCTORS///////////
    //default constructor setting fraction to 0/1
    Fraction();
    //constructor setting fraction to num/1
    Fraction(const int num);
    //constructor setting fraction to num/den or num/1 if den is zero
    Fraction(const int num, const int den);
    //copy constructor where num = source.num, den = source.den
    Fraction(const Fraction& source);

    ///////////FUNCTIONS//////////////
    ///////////MEMBER/////////////////
    //Description: Fraction's numerator and denominator are set to the users' input
    //  (unless they enter a denominator of zero!)
    void readin();

    //Fraction is print to cout in (N/D) format (numerator / denominator)
    void print() const ;

    //Post: A new fraction is returned where
    //     the new numerator is the calling object's denominator
    //     and the new denominator is the calling object's numerator
    Fraction reciprocal() const ;

    //Post: Calling object's numerator and denominator are individually multiplied by m
    void unreduce(const int m);

    //Post: fraction value is returned as a float
    inline float toDecimal() { return (float)m_Numerator/m_Denominator; }; //inline definition

    ///////////////// ACCESSOR FUNCTIONS //////////////////
    inline int getNumer() const { return m_Numerator; }; //inlined definition
    inline int getDenom() const { return m_Denominator; }; //inlined definition
    static double getZeroTol();

    ///////////////// MUTATOR FUNCTIONS ////////////////////
    void setNumer(int n);
    //Description: TRUE is returned if update was successful.
    bool setDenom(int d);
    static void setZeroTol(double d);

    ///////////OPERATORS//////////////
    ///////////MEMBER/////////////////
    Fraction & operator= (const Fraction & rhs);
    Fraction & operator*= (const Fraction & rhs);
  
    ///////////NON MEMBER/////////////////
    friend ostream & operator<< (ostream & out, Fraction & f);
    friend Fraction operator* (const Fraction & lhs, const Fraction & rhs);
    friend bool operator== (const Fraction & lhs, const Fraction & rhs);
    friend bool operator!= (const Fraction & lhs, const Fraction & rhs) {return !(lhs==rhs);}
    friend bool operator> (const Fraction & lhs, const Fraction & rhs);
    friend bool operator<= (const Fraction & lhs, const Fraction & rhs) {return !(lhs > rhs);}
    friend bool operator< (const Fraction & lhs, const Fraction & rhs);
    friend bool operator>= (const Fraction & lhs, const Fraction & rhs) {return !(lhs < rhs);}


    ///////////FRIEND/////////////////
    //Pre:  Numerator cannot be zero
    //Post: The fraction values are swapped - where
    //     the new numerator is the original denominator
    //     and the new denominator is the original numerator
    friend void invert(Fraction & f);
    inline void operator! () { invert(*this); }; //inline; call the invert function on the calling object


private:
    int m_Numerator;    //fraction's numerator
    int m_Denominator;  //fraction's denominator
    static double zero_tolerance; //initial value should be set to 0.0001
};// END of class declaration

//Pre:  lhs and rhs are valid fractions (neither den = 0)
//Post: returned fraction's numerator is the lhs numerator * rhs numerator
//      returned fraction's denominator is the lhs denominator * rhs denominator
Fraction multFracs(const Fraction & lhs, const Fraction & rhs);

#endif 
