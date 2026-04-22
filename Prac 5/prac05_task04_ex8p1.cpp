#include <cstddef>
// import <iostream>;
#include <iostream>

using namespace std;

class Person {
public:
    //set person
    Person(const string FirstName, const string LastName) 
        : firstName(FirstName), lastName(LastName) {}

    // get full name
    string GetName() 
    {
        return firstName + " " + lastName;
    }

    //set first name
    void SetFirstName(const string FirstName) 
    {
        firstName = FirstName;
    }

    //get first name
    string GetFName()
    const {
        return firstName;
    }

    // get last name
    string GetLName() 
    const {
        return lastName;
    }

    // set last name
    void SetLastName(const string LastName) 
    {
        lastName = LastName;
    }

private:
    string firstName;
    string lastName;
};

int main() 
{
    //make person
    Person person("Robert", "Paulson");

    // show full name
    cout << "Full Name: " << person.GetName() << endl;

    // new first name
    person.SetFirstName("John");
    // new last name
    person.SetLastName("Bonjovi");

    // show new name
    cout << "Updated Full Name: " << person.GetName() << endl;

    //test first / last
    cout << person.GetFName() << " " << person.GetLName() << endl;

}


// FROM page 251:
// export module spreadsheet_cell;

// export class SpreadsheetCell
// {
// public:
// 	void setValue(double value);
// 	double getValue() const;

// private:
// 	double m_value{ 0 };
// };

//export class SpreadsheetCell
//{
//public:
//	void setValue(double value) { m_value = value; }
//	double getValue() const { return m_value; }
//private:
//	double m_value{ 0 };
//};

// FROM: page 253
// module spreadsheet_cell;
// void SpreadsheetCell::setValue(double value)
// {
// 	m_value = value;
// }

// double SpreadsheetCell::getValue() const
// {
// 	return m_value;
// }

