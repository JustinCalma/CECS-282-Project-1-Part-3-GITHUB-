// Partine Header File

#ifndef PARTTIME_H
#define PARTTIME_H

#include "Staff.h"
#include <iostream>
#include <string>
using namespace std;

// Create class Part time that is a child of class Staff
class PartTime: public Staff {
	
	// Declare the private attribute
	private:
		int HoursWorkedPerWeek;
		
	// Delcare the public functions 
	public:
		
		// Delcare the getters and setters
		int getHoursWorkedPerWeek();
		void setHoursWorkedPerWeek(int hoursWorked);
		
		// Declare monthlyEarning that will return the monthly salary 
		float monthlyEarning();
		
		// Delcare the function that will output Part time data to the user
		void putData();
		
		// Declare the default constructor and argument constructor 
		PartTime();
		PartTime(string lName, string fName, string idNum, Sex gender, string bdate, float rate, int hoursWorked);
		
		//-------------------------------------------------------------- PART 3 --------------------------------------------------------------//
		void getData();
		
};
#endif
