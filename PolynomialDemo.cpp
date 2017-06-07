/**
* This program creates two polynomials, displays their degrees,
* and evaluates them. This program also generates 10 polynomials
* of degrees ranging from 1000-10000 with randomly-generated
* coefficients in [0,5]. The polynomials will be evaluated
* Horner's and naive polynomial evaluation methods at a random
* number in [0.5,1.2], then execution times will be displayed
* for each run.
* CSC 3102 Homework Assignment # 1
* @author Breanna Lee
* @since Jan 22, 2017
* @see polynomial.h
*/

#include "Polynomial.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	double *coefficients = new double[5]{3, -2, 1,0,-1};
	Polynomial Poly = Polynomial(coefficients,5);

	cout << "f := " << Poly.str() << endl;
	cout << "deg f(x) := " << Poly.degree() << endl;
	cout << "Using Horner's method, g(" << 3 << ") = " << Poly.hornerEval(3) << endl;
	cout << "Using naive method, f(" << 3 << ") = " << Poly.naiveEval(3) << endl<< endl;

	delete [] coefficients;

	coefficients = new double[3]{3, 2,-5};
	Poly = Polynomial(coefficients,3);

	cout << "g := " << Poly.str() << endl;
	cout << "deg g(x) := " << Poly.degree() << endl;
	cout << "Using Horner's method, g(" << -7.25 << ") = " << Poly.hornerEval(-7.25) << endl;
	cout << "Using naive method, g(" << -7.25 << ") = " << Poly.naiveEval(-7.25) << endl << endl;

	delete [] coefficients;

	srand(time(NULL));
	double x;

	cout << "Empirical Analysis of Naive vs Horner's Methods" << endl;
	cout << "on 10 Polynomials with Random Coefficients" << endl;
	cout << "========================================================" << endl;
	cout << "Degree      Naive Time (ns)          Horner's Time (ns)" << endl;
	cout << "--------------------------------------------------------" << endl;

	for (int i=1000; i <= 10000; i+=1000 )
	{
		coefficients = new double[i+1];

		for (int j=0; j<(i+1); j++)
			{
			coefficients[i] = (rand() % 5000)/1000.0;
			}

		x = (rand() % 8 + 5)/10.0;

		Poly = Polynomial(coefficients,(i));

		auto start = high_resolution_clock::now();
		Poly.naiveEval(x);
		auto elapsed = high_resolution_clock::now() - start;
		cout << (i) <<"\t\t "<< duration_cast<nanoseconds>(elapsed).count();

		//Horner's method
		start = high_resolution_clock::now();
		Poly.hornerEval(x);
		elapsed = high_resolution_clock::now() - start;
		cout <<" \t\t "<< duration_cast<nanoseconds>(elapsed).count() << endl;

		delete [] coefficients;
	}
	cout << "--------------------------------------------------------" << endl;
    return 0;
}

