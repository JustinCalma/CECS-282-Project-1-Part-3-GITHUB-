// Faculty Header File

#ifndef FACULTY_H
#define FACULTY_H

#include "Employee.h"
#include "Education.h"
#include "PayrollSystem.h" // ADDED 
#include <iostream>
#include <string>
using namespace std;

// Create an Faculty class that is the child of Employee class
class Faculty: public Employee {
	
	// Declare the private attributes 
	private:
		
		// AS: Assistant Professor, AO: Associate Professor, FU: Professor
		// Declare an attribute of type enum Level
		Level level;
		
		// Create an Education object
		Education education;
		
	// Delcare the public methods 
	public:
		
		// Declare the public getters and setters
		Level getLevel();
		Education getEducation();
		
		void setLevel(Level level);
		void setEducation(Education edu);
		
		// Declare monthlyEarning that will return the monthly salary based on faculty's level
		float monthlyEarning();
		
		// Declare putData that will output the data to the user
		void putData();
		
		// Declare the public default constructor and argument constructor
		Faculty();
		Faculty(string lName, string fName, string idNum, Sex gender, string bdate, Level lvl, Education edu);
		
		//-------------------------------------------------------------- PART 3 --------------------------------------------------------------//
		void getData();

		
};
#endif
