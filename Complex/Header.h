#pragma once
#include <iostream>
#include <string>
#include <complex>
using namespace std;

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex
{
private:
	double Re;
	double Im;

public:
	Complex();
	Complex(double re, double im);
	Complex(const Complex& other);
	void SetComplex(double re, double im);
	Complex Getcomplex();

	friend Complex operator+ (Complex& a, Complex& b);
	friend Complex operator- (Complex& a, Complex& b);
	friend Complex operator* (Complex& a, Complex& b);
	friend Complex operator/ (Complex& a, Complex& b);
	friend bool operator== (Complex& a, Complex& b);
	Complex& operator= (const Complex& other);

	friend ostream& operator<< (ostream& input, const Complex& other);
	friend istream& operator>> (istream& output, Complex& other);
	double get_real_part() const;

	double get_imaginary_part() const;

	double module();

	double pow(Complex x);

	void print_trig(std::ostream& out);
};

#endif
