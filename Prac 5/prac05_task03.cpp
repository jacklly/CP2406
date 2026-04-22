#include <cstddef>
// import <iostream>;
#include <iostream>
// import vector
#include <vector>

using namespace std;

int main()
{
	const size_t numberOfElements{ 10 };
	vector<int> values(numberOfElements);
	// Set values to their index value.
	for (int index{ 0 }; index < numberOfElements; ++index) {
		values[index] = index;
	}
	// Set last value to 99, to ensure no memory error use "-1".
	values[numberOfElements - 1] = 99;
	// Print all values.
	for (int index{ 0 }; index < numberOfElements; ++index) {
		cout << values[index] << " ";
	}
}