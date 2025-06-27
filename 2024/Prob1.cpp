/*

File:   main.cpp
Author: Aurelisa Sindhunirmala and Aprajita
Created on June 27, 2025
Purpose: Problem 1 ICPC 2024*/

// System Libraries
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// User Libraries

// Global Constants Math/Physics/Chemistry/Conversions ONLY!!!!!

// Function Prototypes

// Execution Begins HERE!!!!
int main(int argc, char **argv) {
  // Set random number seed

  // Declare variables
  int numInp = 10; 
  vector<int> numbers = {8, 5, 10, 4, 9,
                         3, 1, 2,  7, 6}; 
  set<int> sumset;

  // Initialize Inputs
  //  cin >> numInp;  

  // Read the c distinct integers
  // for(int i = 0; i < numInp; i++) {  
  //     int num;
  //     cin >> num;
  //     numbers.push_back(num);
  // }

  // Calculate all pairs and their sums
  for (int i = 0; i < numInp; i++) {
    for (int j = i + 1; j < numInp; j++) {
      sumset.insert(numbers[i] + numbers[j]);
    }
  }

  // Calculate number of pairs: c choose 2 = c*(c-1)/2
  int numPairs = numInp * (numInp - 1) / 2;

  // Output: number of pairs followed by size of sumset
  cout << numPairs << " " << sumset.size() << endl;

  // Exit stage right
  return 0;
}