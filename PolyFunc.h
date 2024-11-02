#pragma once

#include <vector>
using namespace std;

namespace PolyFunc {

	/* evalPoly - Takes in a coefficient vector reference and evaluates the polynomial for a given x value
	* [double vector ref] coeffs - the coefficients of the polynomial, leading to constant
	* [double] x - the x value to be evaluated
	* Returns [double] - Evaluated value
	*/
	double evalPoly(const vector<double> &coeffs, const double x);

	/* evalDeriv - Takes in a coefficient vector reference and evaluates the derivative of a polynomial for a given x value
	* [double vector ref] coeffs - the coefficients of the polynomial, leading to constant
	* [double] x - the x value to be evaluated
	* Returns [double] - Evaluated value
	*/
	double evalDeriv(const vector<double>& coeffs, const double x);

	/* evalPoly - Takes in a coefficient vector reference and evaluates the second derivative of a polynomial for a given x value
	* [double vector ref] coeffs - the coefficients of the polynomial, leading to constant
	* [double] x - the x value to be evaluated
	* Returns [double] - Evaluated value
	*/
	double evalSecDeriv(const vector<double>& coeffs, const double x);

	/* euclLinDivide - Makes a copy of the input coefficient vector and applies the linear euclidean algorithm to it for a given x value
	* [double vector] coeffs - the coefficients of the polynomial, leading to constant
	* [double] x - the root of the linear divisor polynomial
	* Returns [double vector reference] - The quotient polynomial as a vector, leading to constant
	*/
	vector<double> euclLinDivide( vector<double> coeffs, const double x);

	/* approxRoot - Runs a Haley's Method approximation to find a root of the given polynomial with an initial value
	* [double vector ref] coeffs - the coefficients of the polynomial, leading to constant
	* [double] x - the initial x value to start the approximation from
	* Returns [double] - an approximation of the root of the polynomial
	*/
	double approxRoot(const vector<double>& coeffs, double x);

	/* approxRoot - Runs a Haley's Method approximation to attempt to find a positive root of the polynomial from initial value 0.0
	* [double vector ref] coeffs - the coefficients of the polynomial, leading to constant
	* Returns [double] - an approximation of a positive root of the polynomial
	*/
	double findPosRoot( vector<double> coeffs);
} 
