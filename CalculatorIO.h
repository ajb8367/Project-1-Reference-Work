#pragma once


#include <iostream> 
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

namespace CalculatorIO {

	/* doubleIn - Takes in a valid input within the specified bounds of the function
	* [double] lBound - The lower bound for acceptable inputs
	* [double] uBound - The upper bound for acceptable inputs
	* Return [double] - The desired double taken in from user input
	*/
	double doubleIn(double lBound, double uBound);

	/* formatTableau - Takes in three arrays of double values as references and outputs a nicely formatted table
	* [double vector ref] timeRef - The vector reference for the time
	* [double vector ref] altRef - The vector reference for the altitudes
	* [double vector ref] velRef - The vector reference for the velocities
	* Return [string] - The formatted table as a string
	*/
	string formatTableau(const vector<double> &timeRef, const vector<double> &altRef, const vector<double> &velRef);

	/* getBool - Takes in user inputs and matches against vectors of allowed "True" strings and allowed "False" strings with true precedence
	* [string vector ref] trueIns - The string vector reference for the allowed true values
	* [string vector ref] falseIns - The string vector reference for the allowed false values
	* Return [bool] - Wether the user put in a true or false string input
	*/
	bool getBool(const vector<string>& trueIns, const vector<string>& falseIns);

}
