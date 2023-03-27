//=================================================
// K M Asif
// March 2023
// Complex.h
// This file contains the class declaration for the
// Complex number class.
// *** Students should not change this file ever ***
//=================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef COMPLEX
#define COMPLEX

class Complex
{
public:
	Complex(void);			   
	Complex(float a, float b); 
	Complex(const Complex &c); 
	string to_string(void) const;
	Complex add(const Complex c) const;
	Complex add(float a) const;
	// Complex add(int a) const;
	float abs(void) const;
	void setReal(float a);
	float getReal(void) const;
	void setImag(float b);
	float getImag(void) const;
	void makeCopy(const Complex c);

private:
	float real; // real part
	float imag; // imaginary part
};

#endif
