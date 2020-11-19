// Staff Implemenation File 

#include "Staff.h"

#include <iostream>
#include <string>
using namespace std;

// Definition of the default constructor
Staff::Staff():Employee() {
	
	// Set HourlyRate to be the default value
	HourlyRate = 0;
	
}

// Definition of the arugment constructor
Staff::Staff(string lName, string fName, string idNum, Sex gender, string bdate, float rate):Employee(lName, fName, idNum, gender, bdate) {
	
	// Set the HourlyRate to be the passed in value
	HourlyRate = rate;
	
}

// Getter for the HourlyRate
float Staff::getHourlyRate() {
	
	// Return the HourlyRate
	return HourlyRate;
	
}

// Setter for the HourlyRate
void Staff::setHourlyRate(float rate) {
	
	// Set the HourlyRate to be the passed in value
	HourlyRate = rate;
	
}

// Calculate the monthly earning of the staff
float Staff::monthlyEarning() {
	
	// HourlyRate * 160
	return (HourlyRate * STAFF_MONTHLY_HOURS_WORKED);
	
}

// Output the data of Staff to the user
void Staff::putData() {
	
	// Call putData from Employee and override it
	// Displays IDNumber, Employee Full Name, and Birth date
	Employee::putData();
	
	// Display "Full Time" and Monthly Salary
	cout << "Full Time" << endl;
	cout << "Monthly Salary: " << monthlyEarning() << endl;
	
}

//-------------------------------------------------------------- PART 3 --------------------------------------------------------------//

// Function that will get the data of the Staff class from the usre
void Staff::getData() {
	
	// Call getData() from Employee to get the Employee data
	Employee::getData();
	
	cout << "Enter the Hourly Rate of pay: ";
	cin >> HourlyRate;
	
}
