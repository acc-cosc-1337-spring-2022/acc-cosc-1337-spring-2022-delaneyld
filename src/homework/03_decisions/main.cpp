#include<iostream>
#include<string>
using std::cout; using std::cin; using std::string;
//write include statements
#include "decisions.h"

/*
In main write code to capture an int grade from the keyboard and call functions 
get_letter_grade_using_if and get_letter_grade_using_switch to display letter grade to screen 
*/

int main() 
{
	string letter_grade; 
	int option, grade; 

	// Display main menu 
	cout << "MAIN MENU\n\n";
	cout << "1 - Letter grade using if\n";
	cout << "2 - Letter grade using switch\n"; 
	cout << "3 - Exit\n\n";
	cin >> option; 

	// Code depending on option entered
	if (option == 1)
	{
		cout << "Please enter a number between 0-100: "; 
		cin >> grade; 
		
		//test to see if grade within range 
		if (grade < 0 || grade > 100)
		{
				cout << "The number is out of range.\n"; 
		}
		else 
		{
			//Call get_letter_grade_using_if
			letter_grade = get_letter_grade_using_if(grade); 
			cout << "The letter grade is: " << letter_grade << "\n"; 
		}
		
	}
	else if (option == 2)
	{
		cout << "Please enter a number between 0-100: "; 
		cin >> grade; 
		
		//test to see if grade within range 
		if (grade < 0 || grade > 100)
		{
			cout << "The number is out of range.\n"; 
		}
		else 
		{
			//Call get_letter_grade_using_switch
			letter_grade = get_letter_grade_using_switch(grade); 
			cout << "The letter grade is: " << letter_grade << "\n"; 
		}
	}
	else if (option == 3)
	{
		cout << "Exited menu.\n";

	}

	return 0;
}

//OLD CODE 
/*
In main write code to capture a letter_grade and credit_hours from the keyboard:


Grade   Credit Hours	grade_points   credit_points
A          3            4              12
B          3            3               9
C          3            2               6
-----------------------------------------------
           9                           27
After each user input convert the Grade to grade points by calling the get_grade_points function, and
keep a running total for both credit_points and credit_hours.

Call the calculate_gpa function with its arguments.
The GPA should calculate to 3.0, make sure to display it before program exits.

Display:
GPA 3.0

*/
// int main() 
// {
// 	string letter_grade;
// 	int credit_hours, sum_credit_hours = 0, sum_credit_points = 0;

// 	cout << "Enter letter grade: ";
// 	cin >> letter_grade;
// 	cout << "Enter credit hours: ";
// 	cin >> credit_hours;
// 	sum_credit_points += get_grade_points(letter_grade) * credit_hours;
// 	sum_credit_hours += credit_hours;

// 	cout << "Enter letter grade: ";
// 	cin >> letter_grade;
// 	cout << "Enter credit hours: ";
// 	cin >> credit_hours;
// 	sum_credit_points += get_grade_points(letter_grade)  * credit_hours;
// 	sum_credit_hours += credit_hours;

// 	cout << "Enter letter grade: ";
// 	cin >> letter_grade;
// 	cout << "Enter credit hours: ";
// 	cin >> credit_hours;
// 	sum_credit_points += get_grade_points(letter_grade)  * credit_hours;
// 	sum_credit_hours += credit_hours;


// 	double gpa = calculate_gpa(sum_credit_hours, sum_credit_points);
// 	cout << "GPA: " << gpa;

// 	return 0;
// }