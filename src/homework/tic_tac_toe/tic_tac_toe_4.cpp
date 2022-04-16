#include "tic_tac_toe_4.h"
#include <iostream>

using std::string, std::cout, std::cin, std::vector, std::ostream, std::istream; 

bool TicTacToe4::check_column_win()
{
    //wins with marked values 1/5/9/13, 2/6/10/14, or 3/7/11/15, 4/8/12/16 with all Os or Xs
    //vector index subtracts 1 from all of the above values 
    bool check_empty = false; 
    bool check_col_win = false; 
    auto count = 0; 

    while (check_col_win == false && count < 4)
    {
        if (pegs[count]=="")
        {
            check_empty = true; 
        }
        else if (pegs[count]=="X")
        {
            if (pegs[count+4] == "X" && pegs[count+8]== "X" && pegs[count+12]== "X")
            {
                check_col_win = true; 
            }
        }
        else if (pegs[count]=="O")
        {
            if (pegs[count+4]=="O" && pegs[count+8]=="O" && pegs[count+12]== "O")
            {
                check_col_win = true; 
            }
        }

        ++count; 
    }

    return check_col_win; 
}

bool TicTacToe4::check_row_win()
{
    //wins with marked values 1/2/3/4 or 5/6/7/8 or 9/10/11/12 or 13/14/15/16 with all Os or Xs 
    bool check_empty = false; 
    bool check_row_win = false; 
    auto count = 0; 

    while (check_row_win == false && count < 13)
    {
        if (pegs[count]=="")
        {
            check_empty = true; 
        }
        else if (pegs[count]=="X")
        {
            if (pegs[count+1] == "X" && pegs[count+2]== "X" && pegs[count+3]=="X")
            {
                check_row_win = true; 
            }
        }
        else if (pegs[count]=="O")
        {
            if (pegs[count+1]=="O" && pegs[count+2]=="O" && pegs[count+3]=="O")
            {
                check_row_win = true; 
            }
        }

        count += 4; 
    }

    return check_row_win; 

}

bool TicTacToe4::check_diagonal_win()
{
    //wins with marked values 1/6/11/16 or 4/7/10/13 with all Os or Xs
    bool check_empty = false; 
    bool check_diagonal_win = false; 
    auto count = 0; 
    auto count2 = 99; //variable for switch loop, will hit default if board space is empty

    while (check_diagonal_win == false && count < 4)
    {
        if (pegs[count]=="")
        {
            check_empty = true; 
        }
        else
        {
            count2 = count; 
        }
        
        switch(count2)
        {
            case 0: 
                if (pegs[count]=="X")
                {
                    if(pegs[count+5]=="X" && pegs[count+10] == "X" && pegs[count+15] == "X")
                    {
                        check_diagonal_win = true; 
                    }
                }
                else if (pegs[count]=="O")
                {
                    if(pegs[count+5]=="O" && pegs[count+10] == "O"&& pegs[count+15] == "O")
                    {
                        check_diagonal_win = true; 
                    }
                }
                break; 
            
            case 3: 
                if (pegs[count]=="X")
                {
                    if(pegs[count+3]=="X" && pegs[count+6] == "X" && pegs[count+9] == "X")
                    {
                        check_diagonal_win = true; 
                    }
                }
                else if (pegs[count]=="O")
                {
                    if(pegs[count+3]=="O" && pegs[count+6] == "O" && pegs[count+9] == "O")
                    {
                        check_diagonal_win = true; 
                    }
                }
                break; 
            
            default: 
                break; 

        }

        count += 3; 
    }

    return check_diagonal_win; 

}



/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/




/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/



/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/
