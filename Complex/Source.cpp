#include "Header.h"

Complex::Complex()
{
	Re = 0;
	Im = 0;
}

Complex::Complex(double re, double im)
{
	Re = re;
	Im = im;
}
Complex::Complex(const Complex& other)
{
	this->Re = other.Re;
	this->Im = other.Im;
}

void Complex::SetComplex(double re, double im)
{
	Re = re;
	Im = im;
}

Complex Complex::Getcomplex()
{
	Complex z(Re, Im);
	return z;
}

Complex& Complex::operator= (const Complex& other)
{
	if (this != &other)
	{
		Re = other.Re;
		Im = other.Im;
	}
	return *this;
}

Complex operator+ (Complex& a, Complex& b)
{
	Complex z;
	z.Re = a.Re + b.Re;
	z.Im = a.Im + b.Im;
	return z;
}

Complex operator- (Complex& a, Complex& b)
{
	Complex z;
	z.Re = a.Re - b.Re;
	z.Im = a.Im - b.Im;
	return z;
}

Complex operator* (Complex& a, Complex& b)
{
	Complex z;
	z.Re = (a.Re * b.Re) - (a.Im * b.Im);
	z.Im = (a.Re * b.Im) + (a.Im * b.Re);
	return z;
}

Complex operator/ (Complex& a, Complex& b)
{
	Complex z;
	z.Re = ((a.Re * b.Re) + (a.Im * b.Im)) / (b.Re * b.Re + b.Im * b.Im);
	z.Im = ((a.Re * b.Im) - (a.Im * b.Re)) / (b.Re * b.Re + b.Im * b.Im);
	return z;
}

bool operator== (Complex& a, Complex& b)
{
	return ((a.Re == b.Re) && (a.Im == b.Im));
}

ostream& operator<<(ostream& output, const Complex& other)
{
	if (other.Im < 0)
		output << other.Re << "+" << "(" << other.Im << ")" << "i" << endl;
	else
		output << other.Re << "+" << other.Im << "i" << endl;
	return output;

}

istream& operator>>(istream& input, Complex& other)
{
	input >> other.Re;
	input >> other.Im;
	return input;
}
double Complex::get_real_part() const
{
	return Re;
}
double Complex::get_imaginary_part() const
{
	return Re;
}

double Complex::module()
{
	return sqrt(Re * Re + Im * Im);
}

double Complex::pow(Complex x)
{
	double fi = atan2(Im / module(), Re / module());
	Complex ln_part(log(module()), fi);
	Complex product = ln_part * x;
	Complex exp_form(exp(product.Re) * cos(product.Im), exp(product.Re) * sin(product.Im));
	Re = exp_form.Re;
	Im = exp_form.Im;
	return 0;
}

void Complex::print_trig(ostream& out)
{
	double fi = atan2(Im / module(), Re / module());
	out << module() << "*(cos(" << fi << ") + i*sin(" << fi << "))";
	return;
}

