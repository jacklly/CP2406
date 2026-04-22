#include <iostream>
#include <string>

using namespace std;

int main()
{
    /* set userinputs */
    string userInput1;
    string userInput2;

    /* ask for string inputs */
    cout << "Alphabetical Printer" << endl << string("Please input the first string:");
    cin >> userInput1;
    cout << string("Please input the second string:");
    cin >> userInput2;

    /* compare strings and output */
    auto result {userInput1.compare(userInput2)};
    if (result < 0) {cout << userInput1 << endl << userInput2;};     /*Less*/
    if (result > 0) {cout << userInput2 << endl << userInput1;};     /*Greater*/
    if (result == 0) {cout << "These are the same!";};
    
    return 0;
}