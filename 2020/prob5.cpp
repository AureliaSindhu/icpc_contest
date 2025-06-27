/* 
 * File:   main.cpp
 * Author: Aurelia Sindhunirmala
 * Created on June 27, 2025
 * Purpose: Problem 5 ICPC 2021
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
    const double tf = 0.25;
    const double tr = 0.75;
    
    const int inp = 9;

    const float speed[inp] = {0, 2.0, 5.7, 5.8, 5.7, 5.2, 5.7, 0.8, 0.2};

    //Initialize Inputs
    
    //Map Inputs to Outputs - Process
    cout << "tf: " << tf << endl;
    cout << "tr: " << tr << endl;

    for (int i = 0; i < inp; i++) {
        cout << "speed[" << i << "]: " << speed[i] << endl;
    }

    int last = 0;

    for (int i = 0; i < inp; i++) {
        double s = speed[i];
        int curr;

        if (s > 0 && s < 1.0) {
            curr = 1;
        }else{
            int i = floor(s);

            double low = i + tf;
            double high = i + tr;

            if (s <= low){
                curr = i;
            } else if (s >= high){
                curr = i + 1;
            } else {
                // curr = last;
                curr = (last > i ? i + 1 : i);

            }
        }
        cout << "sppedometer[" << i << "]: " << curr << endl;
        last = curr;
    }
    
    //Display output
    
    //Exit stage right
    return 0;
}
