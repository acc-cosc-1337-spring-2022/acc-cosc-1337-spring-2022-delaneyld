//write include statements
#include<iostream>
#include<iomanip>
#include "../src/homework/02_expressions/expressions.h" 

//write namespace using statement for cin and cout
//setprecision and fixed are for formatting double decimals to given precision 
using std::cout, std::cin, std::setprecision, std::fixed; 

int main()
{
	double meal_amount, tip_rate, tip_amount, tax_amount, total; 

	//capture meal amount from keyboard
	cout<<"Enter a meal amount: "; 
	cin>>meal_amount; 

	//call function get_sales_tax_amount
	tax_amount = get_sales_tax_amount(meal_amount); 

	//capture tip rate from keyboard
	cout<<"Enter the percentage tip rate (0-100): "; 
	cin>>tip_rate; 

	//call function get_tip_amount
	tip_amount = get_tip_amount(meal_amount, tip_rate); 

	//add tip_amount, tax_amount, meal_amount to get total 
	total = tip_amount + tax_amount + meal_amount; 

	//display a receipt 
	//optional - format decimals 
	cout<< fixed << setprecision(2) << "Meal Amount:  "<< meal_amount << "\n"; 
	cout<< fixed << setprecision(2) << "Sales Tax:  "<< tax_amount << "\n"; 
	cout<< fixed << setprecision(2) << "Tip Amount:  "<< tip_amount << "\n"; 
	cout<< fixed << setprecision(2) << "Total:  "<< total << "\n"; 

	return 0;
}

//example 
/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/