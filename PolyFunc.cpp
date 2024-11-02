#include "PolyFunc.h"


namespace PolyFunc {

	const unsigned int LOOP_CAP = 124U; // Cap for the amount of loops in the Haley's method routine
	constexpr double EPSILON = 1.0 / (2 << 16); // Expression evaluating a dyadic machine epsilon value for the Haley's method routine

	double evalPoly(const vector<double>& coeffs, const double x) {
		double y = coeffs.at(0); // Accumulating variable for the output
		for (int i = 1; i < coeffs.size();  ++i) { // Loop using Horner's rule for evaluating a polynomial off the coeffs vector
			y = y * x + coeffs.at(i);
		}
		return y;
	}



	double evalDeriv(const vector<double>& coeffs, const double x) {
		double y = coeffs.at(0) * (coeffs.size() - 1); // Accumulating variable for the output
		for (int i = 1; i < coeffs.size() - 1; ++i) { // Loop using Horner's rule for evaluating the derivative of the polynomial off the coeffs vector
			y = y * x + coeffs.at(i) * (coeffs.size() - 1 - i);
		}
		return y;
	
	}



	double evalSecDeriv(const vector<double>& coeffs, const double x) {
		double y = coeffs.at(0) * (coeffs.size() - 1) * (coeffs.size() - 2); // Accumulating variable for the output
		for (int i = 1; i < coeffs.size() - 2; ++i) { // Loop using Horner's rule for evaluating the second derivative of the polynomial off the coeffs vector
			y = y * x + coeffs.at(i) * (coeffs.size() - 1 - i) * (coeffs.size() - 2 - i);
		}
		return y;
	}


	vector<double> euclLinDivide(vector<double> coeffs, const double x) {
		for (int i = 1; i < coeffs.size(); ++i) { // Applying the euclidean division algorithm to the coeffs vector variable copy of the original vector
			coeffs.at(i) += x * coeffs.at(i - 1);
		}
		coeffs.pop_back(); // Popping off the remainder term, which is not necessary here.
		return coeffs; // Returning the vector object reference
	}

	double approxRoot(const vector<double>& coeffs, double x) {
		double x = EPSILON + 1.0, v, a; //Starting x a little off from the EPSILON bound checked by the for loop

		for (unsigned i = 0; (fabs(x) > EPSILON) && (i < LOOP_CAP); i++) {
			// Storing the variables useful for the evaluation
			y = evalPoly(coeffs, x);
			v = evalDeriv(coeffs, x);
			a = evalSecDeriv(coeffs, x);
			
			// Calculating the numerator and the denominator for Haley's method
			double denom = (2.0 * v * v - x * a), num = 2.0 * x * v;
			
			if (denom == 0.0) { denom = EPSILON; } // Checking for the exceedingly rare case where the denominator is actually flat out just 0.0
			
			x -= num / denom; // Adjusting the time variable
		}

		return x; //Returning the time which should be fairly accurate
	}

	double findPosRoot(vector<double> coeffs) {
		double approx = approxRoot(coeffs, 0); // Run a first approximation

		if (approx < 0.0) { // Run one more approximation by shaving off the original root.
			vector<double> nextPoly = euclLinDivide(coeffs, approx);
			approx = approxRoot(nextPoly, 0.0);
		}

		/* For future reference: I can probably make this a loop until the vector is completely reduced down assuming roots are found
		* The only issue is that some even polynomials have no real roots, and extremely rarely there is some polynomials with basins that cause oscillatory behavior or massive jumps
		* For the purposes of the project, I am just going to impose the quadric precondition and call it a day.
		*/

		return approx; // Return the approximation that is HOPEFULLY positive
	}

}