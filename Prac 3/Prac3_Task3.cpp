#include <iostream>
#include <string>

using namespace std;

string replace(const string& haystack, const string& needle, const string& change)
{
	// Make a copy of the haystack.
	string result{ haystack };

	// Find all needles and replace them with the replacement string.
	auto position{ result.find(needle) };
	while (position != string::npos) {
		result.replace(position, needle.length(), change);
		position = result.find(needle, position + needle.size());
	}

	return result;
}

int main()
{
    /*Ask for haystack*/
    string haystack;
    cout << "Haystack: ";
    cin >> haystack;

    /*Ask for needle*/
    string needle;
    cout << "Needle: ";
    cin >> needle;

    /*Replace with*/
    string change;
    cout << "Change to: ";
    cin >> change;

    string output{replace(haystack, needle, change)};
    cout << output;
}