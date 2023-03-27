//=================================================
// K M Asif
// Complex.cpp
// This file contains the class implementation for the
// Complex number class.
//=================================================

#include "Complex.h"
#include <iomanip>
#include <sstream>
#include <math.h>
#include <cmath>

//=================================================
// default constructor
// PARAMETERS:
// none
// RETURN VALUE
// Creates a complex variable with value 0+0i
//=================================================
Complex::Complex(void)
{
	real = 0;
	imag = 0;
}

//=================================================
// Parameterized constructor
// PARAMETERS:
//		float a: updating the real part 
//		float b: updating the imaginary part
// RETURN VALUE
// Creates a complex variable with value a+bi
//=================================================

Complex::Complex(float a, float b)
{
	real = a;
	imag = b;
}

//=================================================
// Copy constructor
// PARAMETERS: const Complex &c: passing an object of the class by reference
// RETURN VALUE
// Creates a copy of the passed complex object
//=================================================

Complex::Complex(const Complex &c)
{
	real = c.real;
	imag = c.imag;
}

//=================================================
// to_string
// PARAMETERS:
// none
// RETURN VALUE:
// a string containing "a+bi" where a and b are
// the real and complex parts of the number.  Both
// a and b will be with fixed decimal length up to
// two places.
//=================================================

string Complex::to_string(void) const
{
	stringstream stream;
	stream << fixed << setprecision(3) << real;
	if (imag >= 0)
		stream << "+" << fixed << setprecision(3) << imag << "i";
	else
		stream << "-" << fixed << setprecision(3) << fabs(imag) << "i";

	return stream.str();
}

//=================================================
// add function (1)
// PARAMETERS:
// const Complex c: passing another complex number as parameter
// RETURN VALUE:
// a new complex number as a result of adding the passed complex number
// to the existing number
//=================================================

Complex Complex::add(const Complex c) const
{
	Complex result(real, imag);
	
	result.real = real + c.real;
	result.imag = imag + c.imag;

	return result;
}

//=================================================
// add function (2)
// PARAMETERS:
// float a: 
// RETURN VALUE:
// a string containing "a+bi" where a and b are
// the real and complex parts of the number.  Both
// a and b will be with fixed decimal length up to
// two places.
//=================================================
Complex Complex::add(float a) const
{
	Complex result(real, imag);

	result.real = real + a;
	result.imag = imag;

	return result; 
}

//=================================================
// abs function
// PARAMETERS:
// none
// RETURN VALUE:
// 
// 
//=================================================

float Complex::abs(void) const
{
	float abs = pow(real, 2) + pow(imag, 2);
	return sqrt(abs);

}

//=================================================
//setReal function
// PARAMETERS:
// float a: assigning a new value to the real part of the number
// RETURN VALUE:
// none
//=================================================

void Complex::setReal(float a)
{
	real = a;
}

//=================================================
//getReal function
// PARAMETERS:
// none
// RETURN VALUE:
// returning the real part of the current complex number
//=================================================

float Complex::getReal(void) const
{
	return real;
}

//=================================================
//setImag function
// PARAMETERS:
// float b: assigning a new value to the complex part of the number
// RETURN VALUE:
// none
//=================================================

void Complex::setImag(float b)
{
	imag = b;
}

//=================================================
//getImag function
// PARAMETERS:
// none
// RETURN VALUE:
// returning the complex part of the current complex number
//=================================================

float Complex::getImag(void) const
{
	return imag;
}

//=================================================
//makeCopy function
// PARAMETERS:
// const Complex c: passing a complex number as an object of the same class
// RETURN VALUE:
// none
//=================================================

void Complex::makeCopy(const Complex c)
{
	real = c.getReal();
	imag = c.getImag();
}
