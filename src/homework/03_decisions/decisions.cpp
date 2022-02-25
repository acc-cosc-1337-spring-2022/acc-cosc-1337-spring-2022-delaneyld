//write include statement for decisions header
#include "decisions.h"
#include <string>

//Function get_letter_grade_using_if 
//function returns letter grade (string)
std::string get_letter_grade_using_if(int grade)
{
	std::string letter_grade; 

	//Test to see which letter bracket grade falls into 
	if (grade >= 90 && grade <= 100)
	{
		letter_grade = "A"; 
	}
	else if (grade >= 80 && grade <= 89)
	{
		letter_grade = "B"; 
	}
	else if (grade >= 70 && grade <= 79)
	{
		letter_grade = "C"; 
	}
	else if (grade >= 60 && grade <= 69)
	{
		letter_grade = "D"; 
	}
	else if (grade >= 00 && grade <= 59)
	{
		letter_grade = "F"; 
	}
	
	// Return letter_grade 
	return letter_grade; 
}


//Function get_letter_grade_using_switch 
//function returns letter grade (string)
std::string get_letter_grade_using_switch(int grade)
{
	int grade_10; 
	std::string letter_grade_sw; 

	//int divide grade by 10 to avoid too many case options 
	grade_10 = grade / 10; 

	switch(grade_10)
	{
		case 0: 
		// this is not needed because it will skip straight to case 5
		// 	letter_grade_sw = "F"; 
		// 	break; 
		case 1: 
		// 	letter_grade_sw = "F"; 
		// 	break; 
		case 2: 
		// 	letter_grade_sw = "F"; 
		// 	break; 
		case 3: 
		// 	letter_grade_sw = "F"; 
		// 	break; 
		case 4: 
		// 	letter_grade_sw = "F"; 
		// 	break; 
		case 5: 
			letter_grade_sw = "F"; 
			break; 
		case 6:
			letter_grade_sw = "D"; 
			break; 
		case 7: 
			letter_grade_sw = "C"; 
			break; 
		case 8: 
			letter_grade_sw = "B"; 
			break; 
		case 9:
			letter_grade_sw = "A"; 
			break; 
		case 10: 
			letter_grade_sw = "A";
			break; 

	}

	// Return letter_grade_sw
	return letter_grade_sw; 
}






//OLD CODE 
//Write code for function get_grade_points that accepts a string letter_grade and returns 
//the grade_points for as follows:
//given grade "A" returns 4
//given grade "B" returns 3
//given grade "C" returns 2
//given grade "D" returns 1
//given grade "F" returns 0
// //another other value return -1
// int get_grade_points(std::string letter_grade)
// {
// 	if (letter_grade == "A") 
// 	{
// 		return 4;
// 	}
// 	else if(letter_grade == "B") 
// 	{
// 		return 3;
// 	}
// 	else if (letter_grade == "C")
// 	{
// 		return 2;
// 	}
// 	else if (letter_grade == "D")
// 	{
// 		return 1;
// 	}
// 	else if (letter_grade == "F")
// 	{
// 		return 0;
// 	}
// 	else 
// 	{
// 		return -1;
// 	}
// }


// //Write code for function calculate_gpa that accepts an int named credit_hours and
// //a double named credit_points.  The function returns the quotient of credit_points divided by
// //credit_hours. In the function account for division by zero by returning a -1.
// double calculate_gpa(int credit_hours, double credit_points)
// {
// 	return credit_points / credit_hours;
// }

