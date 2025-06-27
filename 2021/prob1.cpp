/* 
 * File:   main.cpp
 * Author: Aurelia Sindhunirmala
 * Created on June 27, 2025
 * Purpose: Problem 1 ICPC 2021
 */

// System Libraries
#include <iostream>
using namespace std; 

//User Libraries

//Global Constants Math/Physics/Chemistry/Conversions ONLY!!!!!

//Function Prototypes

//Execution Begins HERE!!!!
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare variables
    const int radius[] = {1433, 1433, 2000, 600};
    const float sElv[] = {.09, .12, .09, .12};

    int v, r;
    float s, part1, part2; 
    
    //Initialize Inputs
    
    //Map Inputs to Outputs - Process
    for (int i = 0; i < 4; i++) {
        r = radius[i];
        s = sElv[i];
        part1 = r * (s + .16);
        part2 = part1 / 0.067;
        v = sqrt(part2);
        cout << "v" << i << " = " << v << endl;
    }
    
    //Display output
    
    //Exit stage right
    return 0;
}
