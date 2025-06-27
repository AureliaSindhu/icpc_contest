/* 
 * File:   main.cpp
 * Author: Aurelia Sindhunirmala
 * Created on June 27, 2025
 * Purpose: Problem 3 ICPC 2021
 */

// System Libraries
#include <iostream>
#include <cmath>
using namespace std; 

//User Libraries

//Global Constants Math/Physics/Chemistry/Conversions ONLY!!!!!
const float CONSTANT_TERM = 0.16f;
const float DIVISOR = 0.067f;

//Function Prototypes

//Execution Begins HERE!!!!
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare variables
    const int radius[] = {1433, 1433, 2000, 600};
    const float sElv[] = {.09f, .12f, .09f, .12f};
    
    //Initialize Inputs
    
    //Map Inputs to Outputs - Process
    for (int i = 0; i < 4; i++) {
        // Calculate velocity directly without intermediate variables
        int v = sqrt((radius[i] * (sElv[i] + CONSTANT_TERM)) / DIVISOR);
        cout << "v" << i << " = " << v << endl;
    }
    
    //Display output
    
    //Exit stage right
    return 0;
}
