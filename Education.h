// Education Declarization Class

#ifndef EDUCATION_H
#define EDUCATION_H

#include "PayrollSystem.h"
#include <iostream>
#include <string>
using namespace std;

// Create an Education class
class Education {
	
	// Declare the private attributes 
	private:
		Deg Degree; // MS or PhD
		string Major; // Engineering, Chemistry, English, etc ...
		int Research; // Number of Researches
		
	// Delcare the public methods 
	public:
		
		// Declare the public getters and setters
		Deg getDegree();
		string getMajor();
		int getResearch();
		
		void setDegree(Deg degree);
		void setMajor(string major);
		void setResearch(int research);
		
		// Declare the public default constructor and argument constructor
		Education();
		Education(Deg degree, string major, int research);

		//-------------------------------------------------------------- PART 3 --------------------------------------------------------------//
		void getEducation();
		
};
#endif
