#include "Polynomial.h"
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf


Polynomial::Polynomial()
{
    coeffs = new double[1] {0};
    deg = 0;
}

Polynomial::Polynomial(double c[], int d)
{
    deg = d;
    coeffs = c;
}

Polynomial::~Polynomial()
{

}

double  Polynomial::hornerEval(double x) const
{
	double result = 0.0;
	for	(int i=0; i<deg-1; i++)
	{
		result = x * (coeffs[i] + result);
	}
	result += coeffs[deg-1];
	return result;
}

double Polynomial::naiveEval(double x) const
{
	double result = 0;
	double power = 1;
	int inc = 0;

	for (int i=deg-1; i>=0; i--)
	{
		for (int j=1; j<= i; j++)
		{
			power *= x;
		}

		result += coeffs[inc] * power;
		power = 1;
		inc++;

	}
	return result;
}

int Polynomial::degree() const
{
    return deg;
}

string Polynomial::str() const
{
    stringstream ss;

    ss << "[";
    ss << coeffs[0];

    for (int i=1;i<= (deg-1);i++)
    {
    	ss << ", ";
    	ss << coeffs[i];
    }

    ss << "]";
    return ss.str();

}

