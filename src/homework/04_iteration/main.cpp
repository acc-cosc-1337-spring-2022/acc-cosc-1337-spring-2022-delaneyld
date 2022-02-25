//write include statements
#include <iostream>
#include "dna.h"

//write using statements
using std::cout, std::cin; 

// use a do while loop to create the menu in main 
int main() 
{
	int choice; 
	char user_confirm;

	do
	{	
		user_menu(); 
		choice = run_user_menu(); 

		if (choice != 3)
		{
			user_menu_conditions(choice); 
		}
		else 
		{
			user_confirm = user_confirm_check(); 
			if (user_confirm =='y')
			{
				cout<<"Exiting program.\n"; 
			}
		}

	}while(user_confirm != 'y'); 

	return 0;
}

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/