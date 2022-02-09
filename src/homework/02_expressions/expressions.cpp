#include "../src/homework/02_expressions/expressions.h" 

//code for get_sales_tax_amount
//function returns prod of meal amount and tax rate constant
double get_sales_tax_amount(double meal_amount)
{
	return meal_amount * ( TAX_RATE / 100 ); 
}

//code for get_tip_amount
//function returns prod of meal amount and tip rate 
double get_tip_amount(double meal_amount, double tip_rate)
{
	return meal_amount * ( tip_rate / 100 ); 
}

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

//write code for multiply_numbers function here
//function returns product of num1 and num2