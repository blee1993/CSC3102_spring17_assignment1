/**
 * Describes a univariate polynomial and basic operations
 * on it.
 * @author Duncan
 * @since 01-12-2017
 * @note test
 */

#ifndef POLYNOMIAL_H
#define	POLYNOMIAL_H

#include <string>
using namespace std;

class Polynomial
{
private:
    /**
     * An array of coefficients of this polynomial arranged in order of 
     * descending powers.
     */
    double *coeffs;
	/**
	 * the degree of this polynomial
	 */
	int deg;
public:
    /**
     * Creates the polynomial 0.
     */
    Polynomial();
	
    /**
     * Creates a polynomial with the specified coefficients.
     * @param c the coefficients of this polynomial in order of descending powers
	 * @param d the degree of this polynomial
     */
    Polynomial(double c[], int d);
		
	/**
	 * Deallocates the memory associated with this polynomial
	 */
	~Polynomial();	
    
    /**
     * Evaluates this polynomial at the specified point using the
     * Horner's evaluation method.
     * @param x the point at which this polynomial is to be evaluated
     * @return the value of the polynomial at the specified point
     */
    double hornerEval(double x) const;
    
    /**
     * Evaluates this polynomial at the specified point using a
     * naive evaluation method.
     * @param x the point at which this polynomial is to be evaluated.
     * @return the value of the polynomial at the specified point.
     */
    double naiveEval(double x) const;
    
    /**
     * Gives the degree of this polynomial.
     * @return the degree of this polynomial
     */
    int degree() const;
    
    /**
     * Gives a string representation of this polynomial in descending powers
     * as an array of its coefficients
     * @return a string representation of this polynomial
     */
   string str() const;
};
#endif	/* POLYNOMIAL_H */

