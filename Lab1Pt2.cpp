#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <cmath>    // For sqrt() function in distance calculation

using namespace std;

// Function to calculate distance from the origin
double calculateDistance(int x, int y) {
    return sqrt(x * x + y * y);
}

int main() {
    int x1, y1, x2, y2;
    char choice;

    cout << "Enter 'e' to input values manually or 'g' to generate random values: ";
    cin >> choice;

    if (choice == 'e') {
        cout << "Please enter 4 integer values between -10 and 10 (as x1, y1, x2, y2): ";
        cin >> x1 >> y1 >> x2 >> y2;
        if (cin.fail()) {
            cout << "Error: Non-numeric input detected." << endl;
            return 1; 
        }
        if ((x1 < -10 || x1 > 10) || (y1 < -10 || y1 > 10) || (x2 < -10 || x2 > 10) || (y2 < -10 || y2 > 10)) {
            cout << "Error: All values must be between -10 and 10." << endl;
            return 1; // Ends program
        }
    } else if (choice == 'g') {
        srand(time(0));  //random number generator
        cout << "Generated values: ";
        x1 = rand() % 21 - 10;  // Generate numbers between -10 and 10
        y1 = rand() % 21 - 10;
        x2 = rand() % 21 - 10;
        y2 = rand() % 21 - 10;
        cout << x1 << ", " << y1 << ", " << x2 << ", " << y2 << endl;
    } else {
        cout << "Invalid choice. Please enter 'e' or 'g'." << endl;
        return 1; // Ends program
    }

    // Calculate distances from the origin
    double dist1 = calculateDistance(x1, y1);
    double dist2 = calculateDistance(x2, y2);

    // Output which point is closer to the origin
    cout << "Distance of point (" << x1 << ", " << y1 << ") from origin is: " << dist1 << endl;
    cout << "Distance of point (" << x2 << ", " << y2 << ") from origin is: " << dist2 << endl;

    if (dist1 < dist2) {
        cout << "Point (" << x1 << ", " << y1 << ") is closer to the origin." << endl;
    } else if (dist2 < dist1) {
        cout << "Point (" << x2 << ", " << y2 << ") is closer to the origin." << endl;
    } else {
        cout << "Both points are equidistant from the origin." << endl;
    }

    return 0;
}
//For the beginning portion the lecture class helped alot 