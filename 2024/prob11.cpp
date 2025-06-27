/* 
 * File:   main.cpp
 * Author: Aurelia Sindhunirmala and Leah Mendez
 * Created on June 27, 2025 
 * Purpose: Problem 9 ICPC 2024
 */

// System Libraries
#include <iostream>
#include <string>
#include <set>
using namespace std; 

//User Libraries

//Global Constants Math/Physics/Chemistry/Conversions ONLY!!!!!
const int inpNum = 4;

const string testCases[inpNum] = {
    "magnesium",
    "silver", 
    "aabb",
    "aabb",
};

const string testB[inpNum] = {
    "mg",
    "ag",
    "bbb",
    "aa",
};

//Function Prototypes

//Execution Begins HERE!!!!
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare variables
    // int inpNum;
    string a, b;
    
    //Initialize Inputs
    // cin >> inpNum;
    cout << "inpNum: " << inpNum << endl;
    for(int i = 0; i < inpNum; i++) {
        //Get first string and convert to set
        // cin >> a;    
        a = testCases[i];
        cout << "a: " << a << endl;
        set<char> aSet;
        for(char c : a) {
            aSet.insert(c);
        }
        
        //Get second string
        // cin >> b;
        b = testB[i];
        cout << "b: " << b << endl;
        //Check if all chars in b are in aSet
        bool isSubset = true;
        for(char c : b) {
            if(aSet.find(c) == aSet.end()) {
                isSubset = false;
                break;
            }
        }
        
        //Display output
        cout << (isSubset ? "YES" : "NO") << endl;
    }
    
    //Exit stage right
    return 0;
}
