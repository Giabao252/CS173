#include <sstream>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

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

Complex::Complex(void)
{
	real = 0;
	imag = 0;
}


Complex::Complex(float a, float b)
{
	real = a;
	imag = b;
}


Complex::Complex(const Complex &c)
{
	real = c.real;
	imag = c.imag;
}

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


Complex Complex::add(const Complex c) const
{
	Complex result(real, imag);
	
	result.real = real + c.real;
	result.imag = imag + c.imag;

	return result;
}

Complex Complex::add(float a) const
{
	Complex result(real, imag);

	result.real = real + a;
	result.imag = imag;

	return result; 
}


float Complex::abs(void) const
{

}


void Complex::setReal(float a)
{
	real = a;
}

float Complex::getReal(void) const
{
	return real;
}

void Complex::setImag(float b)
{
	imag = b;
}

float Complex::getImag(void) const
{
	return imag;
}

void Complex::makeCopy(const Complex c)
{
	reaL = .getReal
	imag = c.imag;
}

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
	/*
	Complex c7(3,-4);
	float f = c7.abs();
	cout << "abs(c7) = " << fixed << setprecision(3) << f << endl;
	*/
/*
	Complex c5;
	c5.setReal(3);
	c5.setImag(2);
	cout << "c5 = " << c5.getReal() << "+" << c5.getImag() << "i\n";
*/	
	Complex c6;
	c6.makeCopy(c4);
	cout << "c6 = " << c6.to_string() << endl;
	
	return 0;
}