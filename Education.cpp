// Education Implemenation Class

#include "Education.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Education::Education() {

	// Set the data members to default values	
	Degree = None;
	Major = "";
	Research = 0;
	
}

// Agrument constructor
Education::Education(Deg degree, string major, int research) {
	
	// Set the attributes to be the passed in arguments
	Degree = degree;
	Major = major;
	Research = research;
	
}

// Getter for Degree
Deg Education::getDegree() {
	
	// Returns the degree
	return Degree;
	
}

// Getter for Major
string Education::getMajor() {
	
	// Returns the major
	return Major;
	
}

// Getter for Research
int Education::getResearch() {
	
	// Returns the number of researches 
	return Research;
	
}

// Setter for Degree
void Education::setDegree(Deg degree) {
	
	// Set Degree to be the passed in value
	Degree = degree;
	
}

// Setter for Major
void Education::setMajor(string major) {
	
	// Set the Major to be the passed in value
	Major = major;
	
}

// Setter for Research
void Education::setResearch(int research) {
	
	// Set the Research to be the passed in value
	Research = research;
	
}

//-------------------------------------------------------------- PART 3 --------------------------------------------------------------//

// Function get the education of the employee
void Education::getEducation() {
	
	// Create a temp variable for degree
	int temp;
	
	// Get the input from the user
	cout << "Enter the Degree: None(0), Master(1), PhD(2): ";
	cin >> temp;
	Degree = static_cast<Deg>(temp);
	cout << "Enter the major: ";
	cin >> Major;
	cout << "Enter the number of researches: ";
	cin >> Research;
	
}
