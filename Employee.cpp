// Implementation File for class Employee

#include "Employee.h"
#include "Faculty.h"
#include "Staff.h"
#include "PartTime.h"

#include <fstream>            //for file-stream functions
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// Default Constructor
Employee::Employee() {
	
	// Set all data members to have default values
	LastName = "";
	FirstName = "";
	IDNumber = "";
	sex = M;
	BirthDate = "";
	
}

// Argument Construct
Employee::Employee(string lName, string fName, string idNum, Sex gender, string bdate) {
	
	// Initialize the class attributes
	LastName = lName;
	FirstName = fName;
	IDNumber = idNum;
	sex = gender;
	BirthDate = bdate;
	
}

// Display Employee to the user
void Employee::putData() {
	
	// Output the IDNumber, Employee Full Name, and Birth date
	cout << "ID Employee number: " << IDNumber << endl;
	cout << "Employee name: " << FirstName << " " << LastName << endl;
	cout << "Birth date: " << BirthDate << endl;
	
}

//-------------------------------------------------------------- PART 3 --------------------------------------------------------------//

// Virtual function that will get the input from the user
void Employee::getData() {
	
	// Create a temp variable for the gender
	int temp;
	
	// Flush the input buffer
	cin.ignore(10, '\n');
	
	// Prompt and get the attributes of the Employee
	cout << "Enter the last name: ";
	cin >> LastName;
	cout << "Enter the first name: ";
	cin >> FirstName;
	cout << "Enter the ID Employee number: ";
	cin >> IDNumber;
	cout << "Enter the gender M(0) or F(1): ";
	cin >> temp;
	sex = static_cast<Sex>(temp);
	cout << "Enter the birthday (mm/dd/yy): ";
	cin >> BirthDate;	
	
}

// Add employee to list in memory
void Employee::add() {

	char ch;
	cout << "'f' to add a Faculty"
			"\n's' to add a Staff"
			"\n'p' to add a PartTime"
			"\nEnter selection: ";
	cin >> ch;
	switch(ch)
		{                       //create specified employee type
		case 'f': employees[n] = new Faculty;   	break;
		case 's': employees[n] = new Staff; 		break;
		case 'p': employees[n] = new PartTime;   	break;
		default: cout << "\nUnknown employee type\n"; return;
		}
	employees[n++]->getData();     //get employee data from user

}

// Display all employees
void Employee::display() {

	for(int j=0; j<n; j++)
    {
    cout  << (j+1);           //display number
    switch( employees[j]->get_type() )   //display type
        {
        case tFaculty:    	cout << ". Type: Faculty";   	break;
        case tStaff:  		cout << ". Type: Staff"; 		break;
        case tPartTime:    cout << ". Type: PartTime";   	break;
        default: cout << ". Unknown type";
        }
    employees[j]->putData();    //display employee data
    cout << endl;
    }

	// Create variables to store the calculated total salaries
	float totalPartTimeSalary = 0.0;
	float totalEmployeeSalary = 0.0;

	// Loop through the vector and print calculate the total salary for Part time employees and all Employees
	for (int i = 0; i < employees.size(); i++) {

		if (employees[i] != NULL) {

			// If the current object type is Part Time then enter
			if (employees[i]->get_type() == tPartTime) {

				// Calculate the total salary for part time employees
				totalPartTimeSalary += employees[i]->monthlyEarning();

			}

			// Calculate the total salary for all the employees
			totalEmployeeSalary += employees[i]->monthlyEarning();

		}
	}

	// Output the calculated total salary for Staff and all Employees
	cout << "Total monthly salary for all the part-time staff: $" << totalPartTimeSalary << endl;
	cout << "Total monthly salary for all employees: $" << totalEmployeeSalary << endl;
	cout << endl;

}

// Return the type of this object
employee_type Employee::get_type() {
	
	if( typeid(*this) == typeid(Faculty) )
		return tFaculty;
	else if( typeid(*this)==typeid(Staff) )
		return tStaff;
	else if( typeid(*this)==typeid(PartTime) )
		return tPartTime;
	else
		{ cerr << "\nBad employee type"; exit(1); }
	return tFaculty;
	
}

// Write all current memory objects to file
void Employee::write() {

	int size;	
	cout << "Writing " << n << " employees.\n";
	ofstream ouf;              //open ofstream in binary
	employee_type etype;       //type of each employee object

	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if(!ouf)
		{ cout << "\nCan't open file\n"; return; }
	for(int j=0; j<n; j++)     //for every employee object
		{                       //get its type
		etype = employees[j]->get_type();
								//write type to file
		ouf.write( (char*)&etype, sizeof(etype) );
		switch(etype)           //find its size
			{
			case tFaculty:   	size=sizeof(Faculty); 	break;
			case tStaff: 		size=sizeof(Staff); 	break;
			case tPartTime:   	size=sizeof(PartTime); 	break;
			}                    //write employee object to file
		ouf.write( (char*)(employees[j]), size );
		if(!ouf)
			{ cout << "\nCan't write to file\n"; return; }
		}
	
}

// Read data for all employees from file into memory
void Employee::read() {

	int size;                  //size of employee object
	employee_type etype;       //type of employee
	ifstream inf;              //open ifstream in binary
	inf.open("EMPLOY.DAT", ios::binary);
	if(!inf)
		{ cout << "\nCan't open file\n"; return; }
	n = 0;                     //no employees in memory yet
	while(true)
		{                       //read type of next employee
		inf.read( (char*)&etype, sizeof(etype) );
		if( inf.eof() )         //quit loop on eof
			break;
		if(!inf)                //error reading type
			{ cout << "\nCan't read type from file\n"; return; }
		switch(etype)
			{                    //make new employee
			case tFaculty:       //of correct type
			employees[n] = new Faculty;
			size=sizeof(Faculty);
			break;
			case tStaff:
			employees[n] = new Staff;
			size=sizeof(Staff);
			break;
			case tPartTime:
			employees[n] = new PartTime;
			size=sizeof(PartTime);
			break;
			default: cout << "\nUnknown type in file\n"; return;
			}                    //read data from file into it
		inf.read( (char*)employees[n], size  );
		if(!inf)                //error but not eof
			{ cout << "\nCan't read data from file\n"; return; }
		n++;                    //count employee
		}  //end while
	cout << "Reading " << n << " employees\n";
	
}

//-------------------------------------------------------------- PART 3 END --------------------------------------------------------------//

// Getter for Last Name
string Employee::getLastName() {
	
	// Return Last Name
	return LastName;
	
}

// Getter for First Name
string Employee::getFirstName() {
	
	// Return First name
	return FirstName;
	
}

// Getter for ID Number
string Employee::getIDNumber() {
	
	// Return ID Number
	return IDNumber;
	
}

// Getter for Sex
Sex Employee::getSex() {
	
	// Return the Sex
	return sex;
	
}

// Getter for Birth Date
string Employee::getBirthDate() {
	
	// Return Birth Date
	return BirthDate;
	
}

// Setter for Last Name
void Employee::setLastName(string lName) {
	
	// Set LastName to be the passed in value
	LastName = lName;
	
}

// Setter for First Name
void Employee::setFirstName(string fName) {
	
	// Set FirstName to be the passed in value
	FirstName = fName;
	
}

// Setter for ID Number
void Employee::setIDNumber(string idNum) {
	
	// Set the IDNumber to be the passed in value
	IDNumber = idNum;
	
}

// Setter for Sex
void Employee::setSex(Sex gender) {
	
	sex = gender;
	
}

// Setter for Birth Date
void Employee::setBirthDate(string bdate) {
	
	// Set BirthDate to be the passed in value
	BirthDate = bdate;
	
}


	
