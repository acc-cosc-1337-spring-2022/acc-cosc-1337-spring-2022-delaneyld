//write include statements 
#include <string>
#include <iostream>
#include <cctype>
#include "sequence.h"

using std::cout, std::string, std::cin; 

//function get_gc_content 
//returns decimal percent of G and C from a given constant dna string 
double get_gc_content(const std::string& dna)
{   
    double percent_gc, size_s, count; 
    count = 0; 
    size_s = dna.size(); 

    for (auto& ch: dna)
    {

        //convert ch to uppercase, doesn't work because ch is constant 
        //ch = toupper(ch); 

        if (ch == 'G' || ch == 'C')
        {
            ++count;
        }

    }
    percent_gc = count / size_s; 
    
    return percent_gc; 


}

//function get_dna_complement 
//returns the reverse complement from a given dna string value
//calls reverse_string to get reverse dna string 
//then finds the complement 
string get_dna_complement(string dna)
{
    int count = 0; 

    string dna_new = reverse_string(dna); 

    for (auto ch: dna_new)
    {

        if (ch == 'A')
        {
            ch = 'T'; 
            dna_new[count] = ch; 

        }
        else if (ch == 'T')
        {
            ch = 'A'; 
            dna_new[count] = ch; 

        }
        else if (ch == 'G')
        {
            ch = 'C'; 
            dna_new[count] = ch; 

        }
        else if (ch == 'C')
        {
            ch = 'G'; 
            dna_new[count] = ch; 

        }

        ++count; 
    }

    return dna_new; 

}

//function reverse_string 
//returns the reverse string from a given dna string value 
string reverse_string(string dna)
{
    int size_s, count_for;
    size_s = dna.size(); 
    string new_string=dna; 
    count_for=0; 

    for(int count_back = size_s - 1; count_back >= 0; --count_back)
    {
        new_string[count_for] = dna[count_back]; 
        ++count_for; 
    }

    return new_string; 

}

//function user_menu 
void user_menu()
{

    cout<< "\nMAIN MENU\n\n";
    cout<< "1 - Get GC Content\n";
    cout<< "2 - Get DNA Complement\n";
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
    string dna_test, result_string; 
    double result_doub; 

    // switch loop to handle menu choices 
    switch(choice)
		{
			//GC Content
			case 1: 
				cout<<"Please enter a DNA string: "; 
				cin>>dna_test; 
				result_doub = get_gc_content(dna_test); 
                cout<<"The decimal percent of GC is: "<< result_doub << "\n";
				break; 

			//Get DNA Complement 
			case 2:
				cout<<"Please enter a DNA string: "; 
				cin>>dna_test; 
				result_string = get_dna_complement(dna_test); 
                cout<<"The DNA complement is: "<< result_string << "\n"; 
				break; 

			//exit with user confirm 
			case 3:
				break;

			default:
				cout<<"Menu number choice entered was not valid.\n"; 
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



// Helping to test code from the discussion board of this HW 
// //function test 
// string test_reverse(string dna)
// {
//     string temp_st; 
//     for (int i = dna.length()-1; i>=0; i--)
//     {
//         temp_st += dna[i]; 

//     }
//     return temp_st; 
// }



/*
Write code for void function display_vector that accepts parameter const reference vector of strings.
The function will iterate through the vector and display a string per line.
*/


/*
Write code for void function update_vector_element that accepts parameter reference vector of strings,
a string vector search_value, and a string replace_value.
The function will iterate through the vector and search for the search_value and if found will
replace the vector element with the replace_value.
*/
