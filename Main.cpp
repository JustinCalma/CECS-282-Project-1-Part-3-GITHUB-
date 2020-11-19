// Justin Calma
// CECS 282 Project 1 Part 3

// Main File

#include "Employee.h"
#include "Staff.h"
#include "Education.h"
#include "Faculty.h"
#include "PartTime.h"

#include <process.h>          //for exit()
#include <typeinfo>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Initialize static members of class Employee
int Employee::n;              					//current number of employees
vector<Employee*> Employee::employees(100);  //array of ptrs to emps

// Definition of the main function
int main() {

//-------------------------------------------------------------- PART 3 --------------------------------------------------------------//
	
	char ch;
	while(true) {
		cout << "'a' -- add data for an employee"
				"\n'd' -- display data for all employees"
				"\n'w' -- write all employee data to file"
				"\n'r' -- read all employee data from file"
				"\n'x' -- exit"
				"\nEnter selection: ";
		cin >> ch;
		switch(ch) {
			// Add an employee to list
			case 'a':            
				Employee::add(); 
				break;
			// Display all employees	
			case 'd':            
				Employee::display(); 
				break;
			// Write employees to file	
			case 'w':            
				Employee::write(); 
				break;
			// Read all employees from file
			case 'r':            
				Employee::read(); 
				break;
			// Exit program
			case 'x': 
				exit(0);   
			default: cout << "\nUnknown command";
		}  //end switch
	}  //end while
	
//-------------------------------------------------------------- PART 3 END --------------------------------------------------------------//	

	// Return 0 to main
	return 0;
	
}



