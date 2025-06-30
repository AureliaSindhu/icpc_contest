/*

File:   main.cpp
Author: Aprajita
Created on June 27, 2025
Purpose: Problem 1 ICPC 2024*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a structure for a Point in 2D space
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

// Function to compute the cross product of vectors (p1p2) × (p1p3)
// Used to check colinearity and orientation
int crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

// Check if any three of the four points are colinear
bool areAnyThreeColinear(vector<Point>& points) {
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            for (int k = j + 1; k < 4; ++k) {
                // If cross product is zero, the points are colinear
                if (crossProduct(points[i], points[j], points[k]) == 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Check if all four points are on the convex hull (i.e., no point lies inside the triangle formed by the other three)
bool areAllOnConvexHull(vector<Point>& points) {
    for (int i = 0; i < 4; ++i) {
        Point p = points[i];
        vector<Point> otherPoints;

        // Get the other three points
        for (int j = 0; j < 4; ++j) {
            if (j != i) otherPoints.push_back(points[j]);
        }

        Point A = otherPoints[0], B = otherPoints[1], C = otherPoints[2];

        // Calculate the area of triangle ABC using cross product
        int areaABC = abs(crossProduct(A, B, C));

        // Calculate area of triangle PAB, PBC, PCA
        int areaPAB = abs(crossProduct(p, A, B));
        int areaPBC = abs(crossProduct(p, B, C));
        int areaPCA = abs(crossProduct(p, C, A));

        // If P is inside triangle ABC, then the sum of smaller areas equals the big triangle's area
        if (areaPAB + areaPBC + areaPCA == areaABC) {
            return false; // One point is inside — not a convex hull
        }
    }
    return true; // All points are on the convex hull
}

// Final check function that uses above two checks to decide if the points form a valid quadrilateral
bool canDivide(vector<Point>& points) {
    if (areAnyThreeColinear(points)) {
        return false; // Invalid if any three are colinear
    }
    return areAllOnConvexHull(points); // Valid if all lie on the convex hull
}

int main() {
    // Sample Test Cases
    vector<vector<int>> testCases = {
        {0, 0, 0, 1, 0, 2, 0, 3},        // All points are on a straight line → "No"
        {-5, 0, 5, 3, 2, 10, -6, -3},    // Convex quadrilateral → "Yes"
    };

    // Evaluate each test case
    for (auto& testCase : testCases) {
        vector<Point> points;
        for (int i = 0; i < 8; i += 2) {
            points.emplace_back(testCase[i], testCase[i + 1]);
        }
        cout << (canDivide(points) ? "Yes" : "No") << endl;
    }

    return 0;
}
