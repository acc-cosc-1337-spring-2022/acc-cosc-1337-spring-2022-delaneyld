#include "dna.h"
#include <iostream>

using std::cout, std::cin; 

//function code for factorial 
int factorial(int num)
{
    //note - using prod instead of sum because calculation is multiplication 
    int prod = 1;  

    //HW instructions stated to loop while num > 0, but I would've looped while num > 1
    while(num > 0)
    {
        prod *= num; 
        --num; 
    }

    return prod; 

}

//function code for gcd
int gcd(int num1, int num2)
{
    int num3 = 0; //define third variable for swapping 

    while(num1 != num2)
    {
        if (num1 < num2)
        {
            //swap num1 and num2
            num3 = num1; 
            num1 = num2; 
            num2 = num3; 

        }
        else if (num1 > num2)
        {
            //subtract num2 from num1
            num1 -= num2; 

        }

    }
    
    return num1; 

}

//function user_menu 
void user_menu()
{

    cout<< "\nMAIN MENU\n\n";
    cout<< "1 - Factorial\n";
    cout<< "2 - Greatest Common Divisor\n";
    cout<< "3 - Exit\n\n"; 

}

//function to run user menu 
int run_user_menu()
{
    int choice; 

    cout<<"Please enter your menu choice number: "; 
	cin>>choice; 
    return choice; 

}

//function for user menu conditions 
void user_menu_conditions(int choice)
{
    int num1, num2, num, prod, gcd_num;

    // switch loop to handle menu choices 
    switch(choice)
		{
			//factorial 
			case 1: 
				cout<<"Please enter a number: "; 
				cin>>num; 
				prod = factorial(num); 
				cout<<"\nThe factorial result is "<< prod << "\n"; 
				break; 

			//gcd
			case 2:
				cout<<"Please enter number 1: "; 
				cin>>num1; 
				cout<<"Please enter number 2: "; 
				cin>>num2; 
				gcd_num = gcd(num1, num2); 
				cout<<"\nThe greatest common divisor is "<< gcd_num << "\n"; 
				break; 

			//exit with user confirm 
			case 3:
                // logic for this case will be handled in main so that I can keep the do while loop in main  
                // with a user_confirm condition 

                // below could have been used here: 
				// user_confirm = user_confirm_check(); 
				// if (user_confirm =='y')
				// {
				// 	cout<<"Exiting program.\n"; 
				// }
				break;
			default:
				cout<<"Number choice entered was not valid.\n"; 
        }

}

//function user_confirm_check  
char user_confirm_check()
{
    char user_confirm; 
    cout << "Are you sure that you want to exit? (y/n): "; 
    cin >> user_confirm; 
    return user_confirm; 
}





/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/




/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/



/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/

