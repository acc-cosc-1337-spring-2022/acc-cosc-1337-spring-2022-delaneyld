#include "tic_tac_toe_3.h"
#include <iostream>

using std::string, std::cout, std::cin, std::vector, std::ostream, std::istream; 

bool TicTacToe3::check_column_win()
{
    //wins with marked values 1/4/7, 2/5/8, or 3/6/9 with all Os or Xs
    //vector index subtracts 1 from all of the above values 
    bool check_empty = false; 
    bool check_col_win = false; 
    auto count = 0; 

    while (check_col_win == false && count < 3)
    {
        if (pegs[count]=="")
        {
            check_empty = true; 
        }
        else if (pegs[count]=="X")
        {
            if (pegs[count+3] == "X" && pegs[count+6]== "X")
            {
                check_col_win = true; 
            }
        }
        else if (pegs[count]=="O")
        {
            if (pegs[count+3]=="O" && pegs[count+6]=="O")
            {
                check_col_win = true; 
            }
        }

        ++count; 
    }

    return check_col_win; 
}

bool TicTacToe3::check_row_win()  
{
    //wins with marked values 1/2/3 or 4/5/6 or 7/8/9 with all Os or Xs 
    bool check_empty = false; 
    bool check_row_win = false; 
    auto count = 0; 

    while (check_row_win == false && count < 7)
    {
        if (pegs[count]=="")
        {
            check_empty = true; 
        }
        else if (pegs[count]=="X")
        {
            if (pegs[count+1] == "X" && pegs[count+2]== "X")
            {
                check_row_win = true; 
            }
        }
        else if (pegs[count]=="O")
        {
            if (pegs[count+1]=="O" && pegs[count+2]=="O")
            {
                check_row_win = true; 
            }
        }

        count += 3; 
    }

    return check_row_win; 

}

bool TicTacToe3::check_diagonal_win() 
{
    //wins with marked values 1/5/9 or 7/5/3 with all Os or Xs
    bool check_empty = false; 
    bool check_diagonal_win = false; 
    auto count = 0; 
    auto count2 = 99; //variable for switch loop, will hit default if board space is empty

    while (check_diagonal_win == false && count < 3)
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
                    if(pegs[count+4]=="X" && pegs[count+8] == "X")
                    {
                        check_diagonal_win = true; 
                    }
                }
                else if (pegs[count]=="O")
                {
                    if(pegs[count+4]=="O" && pegs[count+8] == "O")
                    {
                        check_diagonal_win = true; 
                    }
                }
                break; 
            
            case 2: 
                if (pegs[count]=="X")
                {
                    if(pegs[count+2]=="X" && pegs[count+4] == "X")
                    {
                        check_diagonal_win = true; 
                    }
                }
                else if (pegs[count]=="O")
                {
                    if(pegs[count+2]=="O" && pegs[count+4] == "O")
                    {
                        check_diagonal_win = true; 
                    }
                }
                break; 
            
            default: 
                break; 

        }

        count += 2; 
    }

    return check_diagonal_win; 

}

// //Overloaded cout to output the board 
// std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
// //std::ostream& operator<<(std::ostream& out, std::unique_ptr<TicTacToe3> game1)
// {
//     //TicTacToe game = *game1; 
//     for(int i=0; i < 9; i +=3)
//     {
//         //out << game <- pegs[i] << "|" << game <- pegs[i+1] << "|" << game <- pegs[i+2] << "\n"; 
//         out<< game.pegs[i]<<"|"<< game.pegs[i+1]<<"|"<< game.pegs[i+2]<<"\n"; 
//     }

//     return out; 

// }


// //Overloaded cin to capture position 
// std::istream& operator>>(std::istream& in, TicTacToe& game)
// {
//     int position; 
//     cout<<"Enter position [1-9]: "; 
// 	in>>position; 
//     if (position >= 1 && position <= 9) //input validation to ensure that postion is within accepted range, otherwise board will stay empty 
// 		{
// 			game.mark_board(position); 
// 		}

//     return in; 

// }

/*
class function check_column_win
Win by column if and return true if
0,3, and 6 are equal
1, 4, and 7
2, 5, and 8
else
false
*/



/*
class function check_row_win
Win by row if
0, 1, 2 are equal
3,4,5 are equal
6,7,8 are equal
*/



/*
class function check_diagonal_win
Win diagonally
0 1 2
3 4 5
6 7 8

*/
