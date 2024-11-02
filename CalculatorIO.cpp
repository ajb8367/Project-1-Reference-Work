#include "CalculatorIO.h"


using namespace std;

namespace CalculatorIO{
	double doubleIn(double lBound, double uBound) {
		bool badInput = false; // Flag for bad input
		double input; // Input double variable
		do {
			if (badInput) { cout << "Illegal input! Try again: "; } //If there is currently bad input give an error message
			cin >> input;
			badInput = (input < lBound) || (uBound < input); //See if the input is within acceptable bounds

		} while (badInput);

		return input;
	}

	string formatTableau(const vector<double> &timeRef, const vector<double> &altRef, const vector<double> &velRef) {
		ostringstream tableBuilder;

		tableBuilder << setw(10) << left << "Time (hrs)" << " | " << setw(10) << right << "Altitude (m)" << " | ";
		tableBuilder << setw(13) << right << "Velocity (m/s)" << endl; //Build the table title row
		tableBuilder << setfill('-') << setw(tableBuilder.str().length()) << "" << endl; //Make a row of minus signs.
		tableBuilder << setfill(' '); //Reset the fill


		for (int i = 0; i < timeRef.size(); i++) { //Making the table
			tableBuilder << fixed << setprecision(2) << setw(10) << right << timeRef.at(i) << " | ";
			tableBuilder << setw(13) << right << altRef.at(i) << " | " << setw(13) << right << velRef.at(i) << endl; //Build the table datum row
		}

		return tableBuilder.str(); //Return the formatted string
	}


	bool getBool(const vector<string>& trueIns, const vector<string>& falseIns) {
		bool badInput = false, out; // Flag for bad input
		string input; // Input string variable


		do {
			if (badInput) { cout << "Illegal input! Try again: "; } //If there is currently bad input give an error message
			
			cin >> input;
			badInput = true;

			for (int i = 0; (badInput) && (i < trueIns.size()); ++i) { 
				badInput = (trueIns.at(i) != input);
			}

			if (!badInput) {out = true;}
			else {
				for (int i = 0; (badInput) && (i < falseIns.size()); ++i) {
					badInput = (falseIns.at(i) != input);
				}
				if (!badInput) { out = false; }

			}
		} while (badInput);

		return out;
	}


}