// Staff Header File

#ifndef STAFF_H
#define STAFF_H

#include "Employee.h"
#include "PayrollSystem.h" // ADDED
#include <iostream>
#include <string>
using namespace std;

// Create class Staff that extends class Employee
class Staff: public Employee {

	// Declare the private attribute of Staff
	private:	
		float HourlyRate;
		
	// Declare the public methods of Staff
	public: 
	
		// Declare the setter and getter for HourlyRate
		float getHourlyRate();
		void setHourlyRate(float rate);
		
		// Declare the method that will calculate monthly salary
		float monthlyEarning();
		
		// Declare the method that will output the data to the user
		void putData();
		
		// Delcare the public default constructor and argument constructor
		Staff();
		Staff(string lName, string fName, string idNum, Sex gender, string bdate, float rate);
		
		//-------------------------------------------------------------- PART 3 --------------------------------------------------------------//
		void getData();
	
};
#endif
