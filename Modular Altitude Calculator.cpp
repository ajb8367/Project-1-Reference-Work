/**
*   CMPSC 201 - Project 1*
*   Modular)Altitude_Calculator.cpp
*   Purpose: To recreate the prior altitude calculator utilizing C++ features such as vector objects, functions, and other files/namespaces
* 
*   @author Aidan Block
*   @version 1.0 11/02/24
*/

#include <iostream>
#include <vector>
#include "PolyFunc.h"
#include "CalculatorIO.h"

using namespace std;

int main()
{
    const vector<double> POLY = { -0.12, 12.0, -380.0, 4100.0, 220.0 }; // Coefficients for the polynomial approximation, assumed cubic with the first coefficient being negative.
    const double INTERVAL_MIN = 0.001, INTERVAL_MAX = 1500.0; // Bounds for the interval input
    constexpr double EPSILON = 1.0 / (2 << 16); // Epsilon used for error calculation. The convergence is actually insanely fast, it takes 5 steps usually.
    const unsigned int LOOP_CAP = 256, TABLE_ABB = 64; // Loop caps and how many table rows to make.
    const vector<string> YES_RESPONSES = { "yes", "Yes", "YES", "Y", "y"}; // Allowed "yes" responses
    const vector<string> NO_RESPONSES = { "no", "No", "NO", "N", "n" }; // Allowed "no" responses
    
    double landingTime = PolyFunc::findPosRoot(POLY);
    double timeMax = ceil(landingTime); // Using our max time to bound the input... praying that the hardcoded polynomial isn't a huge issue
    
    bool isRunning = true; // Flag representing that the program is running


    // Standard introduction output
    cout << "Hello, welcome to the balloon altitide simulator!" << endl;
    cout << "It will ask for the start time and end time of the balloon in hours, and ask for the interval to output data at!\n(Max of " << TABLE_ABB << " points)\n" << endl;


    do { // Loop while the program is running
        double begin, end, interval; //Input doubles

        //Three IO loops through the CalculatorIO namespace functions
        cout << fixed << setprecision(2) << "Enter the starting time in hours within 0.00 and " << timeMax << ": ";
        begin = CalculatorIO::doubleIn(0.0, timeMax);

        cout << "Enter the ending time in hours within " << fixed << setprecision(2) << begin << " and " << timeMax << ": ";
        end = CalculatorIO::doubleIn(begin, timeMax);

        cout << "Enter the starting time in *MINUTES* within " << INTERVAL_MIN << " and " << INTERVAL_MAX << ": ";
        interval = CalculatorIO::doubleIn(INTERVAL_MIN, INTERVAL_MAX) / 60.0;


        // First few variables evaluation, primarily for the purpose of making sure the values aren't a priori negative.
        double time = begin;
        double tAlt = PolyFunc::evalPoly(POLY, time);
        
        // The actual vectors stored for the table
        vector <double> times, altitudes, velocities;

        // Evaluation loop for the purpose of filling the above vectors with the table of values
        // Three short circuited conditions to cap the number of rows, make sure the altitude doesn't go negative, and to only print within range
        for (int i = 0; (i < TABLE_ABB) && (tAlt >= 0.0) && (time < end); i++) { 
            tAlt = PolyFunc::evalPoly(POLY, time); // Evaluating for the altitude
            
            // Putting the values at the end of the vectors
            times.push_back(time);
            altitudes.push_back(tAlt);
            velocities.push_back(PolyFunc::evalDeriv(POLY, time));
            
            time += interval; // Incrementing the time
        }

        // Printing out the table and the end values
        cout << CalculatorIO::formatTableau(times, altitudes, velocities) << endl;
        cout << "The balloon lands after " << setprecision(3) << landingTime << " hours!"; // Spit out the root approximation last? I could do this first, it's precomputed.

        // Prompt the user if they want to run the program again
        cout << "\nDo you want to run the program again (Y/N)? ";
        isRunning = CalculatorIO::getBool(YES_RESPONSES, NO_RESPONSES);
    
    } while (isRunning);
    
    // Standard exit message
    cout << "Have a good day!";

    return 0; // Successful exit 
}