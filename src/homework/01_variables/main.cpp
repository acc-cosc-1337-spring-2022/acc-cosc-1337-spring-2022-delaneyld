//write include statements
#include<iostream>
#include "variables.h"

//write namespace using statement for cout and cin
using std::cin, std::cout;

int main()
{
	int num; 
	cout << "Number: "; 
	cin >> num; 

	int result; 
    result = multiply_numbers(num); 
    cout << "The result value for " << num << " is: " << result << "\n";

	int num1 = 4; 
	result = multiply_numbers(num1); 
	cout << "The result value for " << num1 << " is: " << result << "\n"; 

	return 0;
}
