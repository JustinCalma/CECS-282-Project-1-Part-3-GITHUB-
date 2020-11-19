// Faculty Implemenation File

#include "Faculty.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor 
Faculty::Faculty():Employee() {
	
	// Set the class attributes to be the default values
	level = AS;
	education = Education(); // Use the default constructor of class Education
	
}

// Argument Constructor
Faculty::Faculty(string lName, string fName, string idNum, Sex gender, string bdate, Level lvl, Education edu):Employee(lName, fName, idNum, gender, bdate) {
	
	// Set the class attributes to be the passed in values
	level = lvl;
	education = edu;
	
}

// Getter for Level
Level Faculty::getLevel() {
	
	// Return the level attribute
	return level;
	
}

// Getter for Education
Education Faculty::getEducation() {
	
	// Return the Education object
	return education;
	
}

// Calculate the monthly salary based on the faculty's level
float Faculty::monthlyEarning() {
		
	// If the Faculty level is Assistant Professor
	if (level == AS) {
		
		// Monthly Salary for Assistant Professor is equal to FACULTY_MONTHLY_SALARY
		return FACULTY_MONTHLY_SALARY;
		
	} else if (level == AO) { // If the Faculty level is Associate Professor
		
		// Monthly Salary for Associate Professor is equal to 1.2 * FACULTY_MONTHLY_SALARY
		return (1.2 * FACULTY_MONTHLY_SALARY);
		
	} else { // Else, the Faculty level is Professor
	
		// Monthly Salary for Professor is equal to 1.4 * FACULTY_MONTHLY_SALARY
		return (1.4 * FACULTY_MONTHLY_SALARY);
		
	}
	
	// Return the calculated monthly Earning
	return 0;
	
}

// Output the data of Faculty to the user
void Faculty::putData() {
	
	// Call putData from Employee and override it
	Employee::putData();
	
	// Output the levl of the professor and Monthly Salary
	// Use a switch case branch to check the level of the employee
	switch(level) {
		
		// If the level is Assistant Professor
		case AS: 
			cout << "Assistant Professor" << endl;
			break;
		
		// If the level is Associate Professor
		case AO: 
			cout << "Associate Professor" << endl;
			break;
			
		// If the level is Full Professor
		case FU: 
			cout << "Full Professor" << endl;
			break;
			
	}

	cout << "Monthly Salary: " << monthlyEarning() << endl;
	
}

//-------------------------------------------------------------- PART 3 --------------------------------------------------------------//

// Function to get the data of Faculty class
void Faculty::getData() {
	
	// Create a temp variable for level
	int temp;
	
	// Call the getData() function from Employee to get the data of Employee
	Employee::getData();
	
	// Get the level of the Faculty
	cout << "Enter the level: AS(0), AO(1), FU(2): ";
	cin >> temp;
	level = static_cast<Level>(temp);
	education.getEducation();
	
}
