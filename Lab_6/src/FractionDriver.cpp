//============================================================================
// Name        : driver.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : This is the driver for using the fraction class
//============================================================================

#include <iostream>
#include "Fraction.h"

using std::cin;
using std::cout;
using std::endl;

//const bool VERBOSE = false;
const bool VERBOSE = true;

int main() {
	int passed = 0, failed = 0;

	//Creating some fractions
	Fraction f1, f2, f3;

	//testing readin() and print() functions
//	f1.readin();
//	f1.print();
//
//	f2.readin();
//	f2.print();

	// resetting to known values for testing purposes
	f1.setNumer(1);
	f1.setDenom(2);

	f2.setNumer(3);
	f2.setDenom(3);

	//testing mutator invalid input (denom of 0)
	if (f2.setDenom(0) || f2.getDenom() == 0)
	{
	    if (VERBOSE)
		cout << "ERROR - allowed setting denominator to 0!" << endl;
		failed++;
		f2.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - Did not allow setting denominator to 0" << endl;
		passed++;
//		f2.print();
	}

	//testing accessor ("GET") functions
	if (f1.getNumer() != 1 || f1.getDenom() != 2)
	{
	    if (VERBOSE)
		cout << "ERROR - fraction F1 values seem to have changed!" << endl;
		failed++;
		f1.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - Fraction F1 is set as expected!" << endl;
		passed++;
//		f1.print();
	}

	//testing accessor ("GET") functions
	if (f2.getNumer() != 3 || f2.getDenom() != 3)
	{
	    if (VERBOSE)
		cout << "ERROR - fraction F2 values seem to have changed!" << endl;
		failed++;
		f2.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - Fraction F2 is set as expected!" << endl;
		passed++;
//		f2.print();
	}

	//testing unreduce (multiples num and den by multiplier 2)
	f1.unreduce(2);
	if (f1.getNumer() != 2 || f1.getDenom() != 4)
	{
	    if (VERBOSE)
		cout << "ERROR - unreduced fraction F1 values seem to have changed!" << endl;
		failed++;
		f1.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - unreduced fraction F1 is set as expected!" << endl;
		passed++;
//		f1.print();
	}

    //testing unreduce (by multiplier 0 is illegal)
	f1.unreduce(0);
	if (f1.getDenom() == 0)
	{
	    if (VERBOSE)
		cout << "ERROR - unreduced fraction set denominator to 0!" << endl;
		failed++;
		f1.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - unreduced fraction F1 is set as expected!" << endl;
		passed++;
//		f1.print();
	}
	//reset f1
	f1.setNumer(2);
    f1.setDenom(4);

	//testing assignment operation and reciprocal function
	f3 = f1.reciprocal();
	//Fraction F1 should remain unchanged!
	if (f1.getNumer() != 2 || f1.getDenom() != 4)
	{
	    if (VERBOSE)
		cout << "ERROR - after reciprocal() call, fraction F1 values seem to have changed!" << endl;
		failed++;
		f1.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - after reciprocal() call, fraction F1 is set as expected!" << endl;
		passed++;
//		f1.print();
	}

	//Fraction F3 should be the reciprocal.
	if (f3.getNumer() != 4 || f3.getDenom() != 2)
	{
	    if (VERBOSE)
		cout << "ERROR - reciprocal fraction F3 values seem to have changed!" << endl;
		failed++;
		f3.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - reciprocal fraction F3 is set as expected!" << endl;
		passed++;
//		f3.print();
	}

	//Testing NON-MEMBER multFracs function
	f3 = multFracs(f1, f2);
	//F1 and F2 should remain unchanged
	//Fraction F1 should remain unchanged!
	if (f1.getNumer() != 2 || f1.getDenom() != 4)
	{
	    if (VERBOSE)
		cout << "ERROR - after multFracs() call, fraction F1 values seem to have changed!" << endl;
		failed++;
		f1.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - after multFracs() call, fraction F1 is set as expected!" << endl;
		passed++;
//		f1.print();
	}
	//Fraction F2 should remain unchanged!
	if (f2.getNumer() != 3 || f2.getDenom() != 3)
	{
	    if (VERBOSE)
		cout << "ERROR - after multFracs() call, fraction F2 values seem to have changed!" << endl;
		failed++;
		f2.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - after multFracs() call, fraction F2 is set as expected!" << endl;
		passed++;
//		f2.print();
	}
	//Fraction F3 should be the multFracs() result
	if (f3.getNumer() != 6 || f3.getDenom() != 12)
	{
	    if (VERBOSE)
		cout << "ERROR - after multFracs() call, fraction F3 values seem to have changed!" << endl;
		failed++;
		f3.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - after multFracs() call, fraction F3 is set as expected!" << endl;
		passed++;
//		f3.print();
	}

	//testing toDecimal conversion
	if (f3.toDecimal() != 0.5)
	{
		failed++;
	    if (VERBOSE)
		cout << "ERROR - toDecimal() call, fraction F3 values output as " << f3.toDecimal() << " (expected 0.5)" << endl;
	}
	else {
	    if (VERBOSE)
		cout << "PASS - toDecimal() call, fraction F3 values output as " << f3.toDecimal() << endl;
		passed++;
	}

	///////////////////CONSTRUCTOR TESTS
	Fraction f4, f5(4), f6(3,4), f7(f3);
	//DEFAULT Constructor Fraction F4 should be 0/1 or 1/1
	if ((f4.getNumer() != 0 && f4.getNumer() != 1)|| f4.getDenom() != 1)
	{
	    if (VERBOSE)
		cout << "ERROR - DEFAULT Constructor should return 0/1 or 1/1!" << endl;
		failed++;
		f4.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - DEFAULT Constructor returned " << endl;
		passed++;
//		f4.print();
	}
	//OVERLOADED Constructor Fraction F5 should be 4/1
	if (f5.getNumer() != 4 || f5.getDenom() != 1)
	{
	    if (VERBOSE)
		cout << "ERROR - OVERLOADED Constructor (one param) should return num/1!" << endl;
		failed++;
		f5.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - OVERLOADED Constructor (one param) success!" << endl;
		passed++;
//		f5.print();
	}
	//OVERLOADED Constructor Fraction F6 should be 3/4
	if (f6.getNumer() != 3 || f6.getDenom() != 4)
	{
	    if (VERBOSE)
		cout << "ERROR - OVERLOADED Constructor (two param) should return num/den!" << endl;
		failed++;
		f6.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - OVERLOADED Constructor (two param) success!" << endl;
		passed++;
//		f6.print();
	}
	//COPY Constructor Fraction F7 should be the previous F3 result
	if (f7.getNumer() != 6 || f7.getDenom() != 12)
	{
	    if (VERBOSE)
		cout << "ERROR - after COPY Constructor call!" << endl;
		failed++;
		f7.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - COPY Constructor call, fraction F7 is set as expected!" << endl;
		passed++;
//		f7.print();
	}

	//Testing safety of two-param constructor (den cannot be 0)
	Fraction f8(0,0);
	if (f8.getDenom() == 0)
	{
	    if (VERBOSE)
		cout << "ERROR - allowed setting denominator to 0 in CONSTRUCTOR!" << endl;
		failed++;
		f8.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - CONSTRUCTOR did not allow setting denominator to 0" << endl;
		passed++;
//		f8.print();
	}

	//TESTING FRIEND INVERT FUNCTION
	Fraction f9(0,1), f10(1,2);
	invert(f9);
	if (f9.getDenom() == 0)
	{
	    if (VERBOSE)
		cout << "ERROR - INVERT allowed setting denominator to 0 !" << endl;
		failed++;
		f9.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - INVERT did not allow setting denominator to 0" << endl;
		passed++;
//		f9.print();
	}

	invert(f10);
	if (f10.getNumer() != 2 || f10.getDenom() != 1)
	{
	    if (VERBOSE)
		cout << "ERROR - INVERT did not invert!" << endl;
		failed++;
		f10.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - INVERT inverted as expected!" << endl;
		passed++;
//		f10.print();
	}

    /////////////////////////////// OPERATOR TESTING
	Fraction f11, f12;
	f11 = f12 = f10;
	if (f11.getNumer() != 2 || f11.getDenom() != 1 || f12.getNumer() != 2 || f12.getDenom() != 1)
	{
	    if (VERBOSE)
		cout << "ERROR - ASSIGNMENT did not chain!" << endl;
		failed++;
		f11.print();
		f12.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - ASSIGNMENT chained as expected!" << endl;
		passed++;
//		f11.print();
//		f12.print();
	}

	Fraction f13(1,2);
	f10 = f11 = f12 = f13;
	f10 *= f11 *= f12 *= f13;
//	cout << f10 << "  " << f11 << "  " << f12 << "  " << f13 << endl;
	if (f10.getNumer() != 1 || f10.getDenom() != 16
			|| f11.getNumer() != 1 || f11.getDenom() != 8
			|| f12.getNumer() != 1 || f12.getDenom() != 4
			|| f13.getNumer() != 1 || f13.getDenom() != 2)
	{
	    if (VERBOSE)
		cout << "ERROR - *= did not chain!" << endl;
		failed++;
		f10.print();
		f11.print();
		f12.print();
		f13.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - *= chained as expected!" << endl;
		passed++;
//		f10.print();
//		f11.print();
//		f12.print();
//		f13.print();
	}

	if ((f10 < f11) && (f11 < f12) && (f12 < f13))
	{
	    if (VERBOSE)
		cout << "PASS - operator< working as expected" << endl;
		passed++;
	}
	else
	{
	    if (VERBOSE)
		cout << "ERROR - operator< not working as expected!" << endl;
		failed++;
		f10.print();
		f11.print();
		f12.print();
		f13.print();
	}

	if (!(f10 >= f11) && !(f11 >= f12) && !(f12 >= f13))
	{
	    if (VERBOSE)
		cout << "PASS - operator>= working as expected" << endl;
		passed++;
	}
	else
	{
	    if (VERBOSE)
		cout << "ERROR - operator>= not working as expected!" << endl;
		failed++;
		f10.print();
		f11.print();
		f12.print();
		f13.print();
	}

	if ((f13 > f12) && (f12 > f11) && (f11 > f10))
	{
	    if (VERBOSE)
		cout << "PASS - operator> working as expected" << endl;
		passed++;
	}
	else
	{
	    if (VERBOSE)
		cout << "ERROR - operator> not working as expected!" << endl;
		failed++;
		f10.print();
		f11.print();
		f12.print();
		f13.print();
	}

	if (!(f13 <= f12) && !(f12 <= f11) && !(f11 <= f10))
	{
	    if (VERBOSE)
		cout << "PASS - operator<= working as expected" << endl;
		passed++;
	}
	else
	{
	    if (VERBOSE)
		cout << "ERROR - operator<= not working as expected!" << endl;
		failed++;
		f10.print();
		f11.print();
		f12.print();
		f13.print();
	}

	f11 = f13;
	if (f11 == f13)
	{
	    if (VERBOSE)
		cout << "PASS - operator== working as expected" << endl;
		passed++;
	}
	else
	{
	    if (VERBOSE)
		cout << "ERROR - operator== not working as expected!" << endl;
		failed++;
		f11.print();
		f13.print();
	}

	f11 = f13;
	if (f11 == f13)
	{
	    if (VERBOSE)
		cout << "PASS - operator== working as expected" << endl;
		passed++;
	}
	else
	{
	    if (VERBOSE)
		cout << "ERROR - operator== not working as expected!" << endl;
		failed++;
		f11.print();
		f13.print();
	}

	if ((f11 != f12) && !(f11 == f12))
	{
	    if (VERBOSE)
		cout << "PASS - operator!= working as expected" << endl;
		passed++;
	}
	else
	{
	    if (VERBOSE)
		cout << "ERROR - operator!= not working as expected!" << endl;
		failed++;
		f11.print();
		f12.print();
	}


	f10 = f13 * f13;
	if (f10.getNumer() != 1 || f10.getDenom() != 4
			|| f13.getNumer() != 1 || f13.getDenom() != 2)
	{
	    if (VERBOSE)
		cout << "ERROR - operator* did not work!" << endl;
		failed++;
		f10.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - operator* worked as expected!" << endl;
		passed++;
	}

	Fraction f14(0,1), f15(1,2);
	!f14;
	if (f14.getDenom() == 0)
	{
	    if (VERBOSE)
		cout << "ERROR - operator! allowed setting denominator to 0 !" << endl;
		failed++;
		f14.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - operator! did not allow setting denominator to 0" << endl;
		passed++;
	}

	!f15;
	if (f15.getNumer() != 2 || f15.getDenom() != 1)
	{
	    if (VERBOSE)
		cout << "ERROR - operator! did not invert!" << endl;
		failed++;
		f15.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - operator! inverted as expected!" << endl;
		passed++;
	}

	!f15;
	if (f15.getNumer() != 1 || f15.getDenom() != 2)
	{
	    if (VERBOSE)
		cout << "ERROR - operator! did not RE-invert!" << endl;
		failed++;
		f15.print();
	}
	else
	{
	    if (VERBOSE)
		cout << "PASS - operator! RE-inverted as expected!" << endl;
		passed++;
	}

	if (Fraction::getZeroTol() == 0.0001) {
        if (VERBOSE)
            cout << "PASS - ZeroTol initially at 0.0001" << endl;
        passed++;
	}
	else {
        if (VERBOSE)
            cout << "FAIL - ZeroTol NOT initially at 0.0001" << endl;
        failed++;
	}

	Fraction::setZeroTol(0.01);
	if (Fraction::getZeroTol() == 0.01) {
        if (VERBOSE)
            cout << "PASS - ZeroTol reset to 0.01" << endl;
        passed++;
	}
	else {
        if (VERBOSE)
            cout << "FAIL - ZeroTol NOT reset to 0.01" << endl;
        failed++;
	}


	cout << endl << "YOU SHOULD SEE (1/2) HERE --> " << f13 << endl << endl;

	cout << "Testing results: " << endl;
	cout << "PASSED: " << passed << endl;
	cout << "FAILED: " << failed << endl << endl;

	return 0;
}