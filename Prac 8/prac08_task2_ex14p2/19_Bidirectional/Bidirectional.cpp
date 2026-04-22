#include <iostream>;
#include <fstream>;
#include <string>;
#include <string_view>;
#include <exception>;

using namespace std;

void changeNumberForID(string_view filename, int id, string_view newNumber)
{
	fstream ioData{ filename.data() };

	// Loop until the end of file
	while (ioData) {
		// Read the next ID.
		int idRead;
		ioData >> idRead;
		if (!ioData)
			break;

		// Check to see if the current record is the one being changed.
		if (idRead == id) {
			// Seek the write position to the current read position.
			ioData.seekp(ioData.tellg());
			// Output a space, then the new number.
			ioData << " " << newNumber;
			break;
		}

		// Read the current number to advance the stream.
		string number;
		ioData >> number;
	}
}

int main()
{
	try {
		changeNumberForID("data.txt", 263, "415-555-3333");
	}
	catch (const logic_error &caughtException)
	{
		cerr << "Exception caught. Aborting" << endl;

		throw caughtException;
	}
		
}