#include "Header.h"
#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main()
{
	bool f;
	Complex t;
	Complex z(5, 8);
	Complex g(z);
	cout <<   "u=" << t << endl << "z=" << z << endl;
	cout <<   "g=" << g << endl;
	cout << " g= " << g.Getcomplex() << endl;

	z.SetComplex(3, 1);
	cout << " z= " << z.Getcomplex() << endl;
	t = z;
	cout << "t=" <<t << endl;
	t = z + g;
	cout <<  "t=" <<t << endl;
	t = z - g;
	cout <<  "t=" <<t << endl;
	t = z * g;
	cout << "t=" <<t << endl;
	t = z / g;
	cout  << "t=" <<t << endl;
	f = (t == z);
	cout  << "f=" << f << endl;
	Complex d = t;
	cout << "D = ";
	cout << d << '\n';
	cout << "|B| = ";
	cout << z.module() << '\n';
	cout << "Trig. B: ";
	z.print_trig(cout);
	cout << '\n';
	z.pow(z);
	cout << "B ^ B = ";
	cout << z << '\n';


	return 0;
}

