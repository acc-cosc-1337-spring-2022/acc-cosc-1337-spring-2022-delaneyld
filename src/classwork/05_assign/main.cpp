//write include statements
#include<string>
#include<iostream>
#include "sequence.h"

//write using statements for cin cout
using std::string, std::cin, std::cout; 


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
Write code to create a vector of string names, add the values "John", "Mary", "Patty",
"Sam" to the vector, call the function display_vector and pass the names vector as
an argument, prompt user for a name to search for and a value to replace searched value with.
Afterward, call the update_vector_element with the names vector and call the display_vector
function.
Don't worry about displaying a message for values that aren't found.  Assume user will
give you a valid name.
*/