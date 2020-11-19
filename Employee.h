// Header file for Employee Class

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "PayrollSystem.h" 
#include <string>
#include <vector>
using namespace std;

// Create an abstract class Employee 
class Employee {

	// Declare the private attributes 
	private:
		string LastName;
		string FirstName;
		string IDNumber;
		string BirthDate;
		
		// Declare an attribute of the enum Gender for Employee
		Sex sex;
		
		//-------------------------------------------------------------- PART 3 --------------------------------------------------------------//
		
		// Declare a static vector that will store the employee objects
		static vector<Employee*> employees;
		
		// Current number of employees
		static int n;           

		
	// Declare the public methods 
	public:
		// Declare default constructor and argument constructor
		Employee();
		Employee(string lName, string fName, string idNum, Sex gender, string bdate);
		
		// Declare the private members
		virtual void putData();
		
		// Declare getters and setters
		string getLastName();
		string getFirstName();
		string getIDNumber();
		Sex getSex();
		string getBirthDate();
		
		void setLastName(string lName);
		void setFirstName(string fName);
		void setIDNumber(string idNum);
 		void setSex(Sex gender);
 		void setBirthDate(string bdate);
		
		// Declare pure virtual method
		virtual float monthlyEarning() = 0;
		
		//-------------------------------------------------------------- PART 3 --------------------------------------------------------------//
		virtual void getData(); // Get the input from the user
		virtual employee_type get_type();  // Get type
		static void add();      // Add an employee
		static void display();  // Display all employees
		static void read();     // Read from disk file
		static void write();    // Write to disk file
		//void calcMonthlyEarning(); // Calculate the Monthly Earnings
		
};
#endif
