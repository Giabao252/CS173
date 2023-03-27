//=================================================
// K M Asif
// driver.cpp
// This file tests the Complex class
// This is the actual file I will test your program
// against for Part 1.  You can compare your output
// to my program output.  
//=================================================

#include <iostream>
#include <iomanip>
#include <string>
#include "Complex.h"
using namespace std;

int main ( void )
{
	Complex c1;
	Complex c2(3,0);
	Complex c3(c2);
	Complex c4(-4.5,-3.1235);
	
	cout << "c1 = " << c1.to_string() << endl;
	cout << "c2 = " << c2.to_string() << endl;
	cout << "c3 = " << c3.to_string() << endl;
	cout << "c4 = " << c4.to_string() << endl;
	
	c4 = c2.add(c3);
	cout << "c4 = c2+c3 = " << c4.to_string() << endl;
	c4 = c2.add(4.5);
	cout << "c4 = c2+4.5 = " << c4.to_string() << endl;
	c4 = c2.add(4);
	cout << "c4 = c2+4 = " << c4.to_string() << endl;
	
	Complex c7(3,-4);
	float f = c7.abs();
	cout << "abs(c7) = " << fixed << setprecision(3) << f << endl;
	
	Complex c5;
	c5.setReal(3);
	c5.setImag(2);
	cout << "c5 = " << c5.getReal() << "+" <<c5.getImag() << "i\n";
	
	Complex c6;
	c6.makeCopy(c4);
	cout << "c6 = " << c6.to_string() << endl;
	
	return 0;
}

	

