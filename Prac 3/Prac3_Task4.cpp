#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main() 
{
    // A vector to store all values.
    vector<double> values;

    // Ask the user to enter values until 0 is entered.
    cout << "Input values, one at a time followed by Enter:" << endl;
    while (true) {
        double value;
        cin >> value;
        if (value == 0.0) {
            break;
        }
        values.push_back(value);
    }

    // Format the values in a table with a couple of columns.
    for (auto value : values) 
    {
        cout << setw(16) << fixed << setprecision(6) << value 
             << " | " << setw(12) << value 
             << " | " << setw(12) << value << endl;
    }

    return 0;
}