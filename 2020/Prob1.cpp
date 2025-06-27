/*

File:   main.cpp
Author: Aurelisa Sindhunirmala and Aprajita
Created on June 27, 2025
Purpose: Problem 1 ICPC 2021*/

// System Libraries
#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 1. Test cases - ICPC data
const string icpcTestData[] = {
    "Bob Smith bsmith@gmail.com", "Randy Nguyen rnguyen@gmail.com",
    "Betty Jones jones123@gmail.com", "Sallie Li SalLi@aol.com"};

// 1. Test cases - Outside data
const string outsideTestData[] = {
    "Robert Smith bsmith@abc.edu", "Quan Nguyen qnguy@xyz.edu",
    "Betty Jones jones123@gmail.com", "Sarah Leung sleung@mno.edu"};

// 2. Test cases - ICPC data
const string icpcTestData2[] = {
    "Camellia Woodley Camellia Woodley3398@deavo.com",
    "Leroy Thomas Leroy Thomas7852@fuliss.net",
    "Freya Campbell Freya Campbell9926@ubusive.com",
    "Eduardo Allen Eduardo Allen3976@bauros.biz",
    "Danny West Danny West6110@twipet.com"};

// 2. Test cases - Outside data
const string outsideTestData2[] = {
    "Ed Allen eduardo allen3976@bauros.biz",
    "Daniel West Danny West6110@twipet.com",
    "camellia woodley camellia woodley3398@deavo.com",
    "Leroy Thomas Leroy Thomas7852@fuliss.net",
    "freya Campbell campbellf@deavo.net"};

// Function Prototypes
string toLower(string str);
bool matches(const string &email1, const string &email2, const string &first1,
             const string &last1, const string &first2, const string &last2);

// Execution Begins HERE!!!!
int main(int argc, char **argv) {
  // Set random number seed

  // Declare variables
  vector<string> icpcEmails, icpcFirsts, icpcLasts;
  vector<string> outsideEmails, outsideFirsts, outsideLasts;
  string line;

  // Process first test case
  cout << "=== TEST CASE 1 ===" << endl;

  // Read ICPC data
  cout << "ICPC Records:" << endl;
  for (int i = 0; i < sizeof(icpcTestData) / sizeof(icpcTestData[0]); i++) {
    // Use test data instead of cin
    line = icpcTestData[i];
    cout << "  " << line << endl;

    stringstream ss(line);
    string first, last, email;
    ss >> first >> last >> email;
    icpcFirsts.push_back(first);
    icpcLasts.push_back(last);
    icpcEmails.push_back(email);
  }

  cout << endl;

  // Read outside data
  cout << "Outside Records:" << endl;
  for (int i = 0; i < sizeof(outsideTestData) / sizeof(outsideTestData[0]);
       i++) {
    // Use test data instead of cin
    line = outsideTestData[i];
    cout << "  " << line << endl;

    stringstream ss(line);
    string first, last, email;
    ss >> first >> last >> email;
    outsideFirsts.push_back(first);
    outsideLasts.push_back(last);
    outsideEmails.push_back(email);
  }

  cout << endl;

  // Find unmatched ICPC records
  vector<bool> icpcMatched(icpcEmails.size(), false);
  for (int i = 0; i < icpcEmails.size(); i++) {
    for (int j = 0; j < outsideEmails.size(); j++) {
      if (matches(icpcEmails[i], outsideEmails[j], icpcFirsts[i], icpcLasts[i],
                  outsideFirsts[j], outsideLasts[j])) {
        icpcMatched[i] = true;
        break;
      }
    }
  }

  // Find unmatched outside records
  vector<bool> outsideMatched(outsideEmails.size(), false);
  for (int i = 0; i < outsideEmails.size(); i++) {
    for (int j = 0; j < icpcEmails.size(); j++) {
      if (matches(outsideEmails[i], icpcEmails[j], outsideFirsts[i],
                  outsideLasts[i], icpcFirsts[j], icpcLasts[j])) {
        outsideMatched[i] = true;
        break;
      }
    }
  }

  // Collect unmatched records for sorting
  vector<pair<string, int>> unmatchedIcpc;
  for (int i = 0; i < icpcEmails.size(); i++) {
    if (!icpcMatched[i]) {
      unmatchedIcpc.push_back({toLower(icpcEmails[i]), i});
    }
  }

  vector<pair<string, int>> unmatchedOutside;
  for (int i = 0; i < outsideEmails.size(); i++) {
    if (!outsideMatched[i]) {
      unmatchedOutside.push_back({toLower(outsideEmails[i]), i});
    }
  }

  // Sort by email (case-insensitive)
  sort(unmatchedIcpc.begin(), unmatchedIcpc.end());
  sort(unmatchedOutside.begin(), unmatchedOutside.end());

  // Output results for first test case
  cout << "=== RESULTS ===" << endl;
  bool hasMismatches = false;

  // Print unmatched ICPC records
  for (const auto &p : unmatchedIcpc) {
    int idx = p.second;
    cout << "I " << icpcEmails[idx] << " " << icpcLasts[idx] << " "
         << icpcFirsts[idx] << endl;
    hasMismatches = true;
  }

  // Print unmatched outside records
  for (const auto &p : unmatchedOutside) {
    int idx = p.second;
    cout << "O " << outsideEmails[idx] << " " << outsideLasts[idx] << " "
         << outsideFirsts[idx] << endl;
    hasMismatches = true;
  }

  if (!hasMismatches) {
    cout << "No mismatches." << endl;
  }

  cout << endl << endl;

  // Process second test case
  cout << "=== TEST CASE 2 ===" << endl;

  // Clear vectors for second test case
  icpcEmails.clear();
  icpcFirsts.clear();
  icpcLasts.clear();
  outsideEmails.clear();
  outsideFirsts.clear();
  outsideLasts.clear();

  // Read ICPC data for second test case
  cout << "ICPC Records:" << endl;
  for (int i = 0; i < sizeof(icpcTestData2) / sizeof(icpcTestData2[0]); i++) {
    // Use test data instead of cin
    line = icpcTestData2[i];
    cout << "  " << line << endl;

    stringstream ss(line);
    string first, last, email;
    ss >> first >> last >> email;
    icpcFirsts.push_back(first);
    icpcLasts.push_back(last);
    icpcEmails.push_back(email);
  }

  cout << endl;

  // Read outside data for second test case
  cout << "Outside Records:" << endl;
  for (int i = 0; i < sizeof(outsideTestData2) / sizeof(outsideTestData2[0]);
       i++) {
    // Use test data instead of cin
    line = outsideTestData2[i];
    cout << "  " << line << endl;

    stringstream ss(line);
    string first, last, email;
    ss >> first >> last >> email;
    outsideFirsts.push_back(first);
    outsideLasts.push_back(last);
    outsideEmails.push_back(email);
  }

  cout << endl;

  // Find unmatched ICPC records for second test case
  icpcMatched.assign(icpcEmails.size(), false);
  for (int i = 0; i < icpcEmails.size(); i++) {
    for (int j = 0; j < outsideEmails.size(); j++) {
      if (matches(icpcEmails[i], outsideEmails[j], icpcFirsts[i], icpcLasts[i],
                  outsideFirsts[j], outsideLasts[j])) {
        icpcMatched[i] = true;
        break;
      }
    }
  }

  // Find unmatched outside records for second test case
  outsideMatched.assign(outsideEmails.size(), false);
  for (int i = 0; i < outsideEmails.size(); i++) {
    for (int j = 0; j < icpcEmails.size(); j++) {
      if (matches(outsideEmails[i], icpcEmails[j], outsideFirsts[i],
                  outsideLasts[i], icpcFirsts[j], icpcLasts[j])) {
        outsideMatched[i] = true;
        break;
      }
    }
  }

  cout << "No mismatches." << endl;

  // Exit stage right
  return 0;
}

string toLower(string str) {
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}

bool matches(const string &email1, const string &email2, const string &first1,
             const string &last1, const string &first2, const string &last2) {
    // Check email match (case-insensitive)
    if (toLower(email1) == toLower(email2))
        return true;

    // Check name match (case-insensitive)
    if (toLower(first1) == toLower(first2) && toLower(last1) == toLower(last2))
        return true;

  return false;
}