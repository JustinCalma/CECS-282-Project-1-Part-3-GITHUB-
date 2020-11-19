// Partime Implemenation File

#include "PartTime.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
PartTime::PartTime():Staff() {
	
	// Set the atrributes to be default values
	int HoursWorkedPerWeek = 0;
	
}

// Argument Constructor
PartTime::PartTime(string lName, string fName, string idNum, Sex gender, string bdate, float rate, int hoursWorked):Staff(lName, fName, idNum, gender, bdate, rate) {
	
	// Set the class attributes to be the passed in value
	HoursWorkedPerWeek = hoursWorked;
	
}

// Getter for Hours Worked Per Week
int PartTime::getHoursWorkedPerWeek() {
	
	// Return the Hours Worked Per Week
	return HoursWorkedPerWeek;
	
}

// Setter for Hours Worked Per Week
void PartTime::setHoursWorkedPerWeek(int hoursWorked) {
	
	// Set Hours Worked Per Week to be the passed in value
	HoursWorkedPerWeek = hoursWorked;
	
}

// Calculate the monthly salary
float PartTime::monthlyEarning() {
	
	// Monthly Salary is Hourly Rate * HoursWorkedPerWeek * 4
	return (Staff::getHourlyRate() * HoursWorkedPerWeek * 4);
	
}

// Output the data of Part time to the user
void PartTime::putData() {
	
	// Call putData from Employee and override it
	// Displays IDNumber, Employee Full Name, and Birth date
	Employee::putData();
	
	// Output HoursWorkedPerWeek and Monthly Salary to the user
	cout << "Hours worked per month: " << (HoursWorkedPerWeek * 4) << endl;
	cout << "Monthly Salary: " << monthlyEarning() << endl;
	
}

//-------------------------------------------------------------- PART 3 --------------------------------------------------------------//

// Function to get the data of the PartTime class from the user
void PartTime::getData() {
	
	// Call the getData() from Staff to get the Staff and Employee data
	Staff::getData();
	
	// Get the HoursWorkedPerWeek from the user
	cout << "Enter the amount of hours worked per week: ";
	cin >> HoursWorkedPerWeek;
	
}
