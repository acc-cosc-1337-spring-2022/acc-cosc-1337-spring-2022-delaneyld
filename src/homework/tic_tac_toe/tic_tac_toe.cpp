//cpp

#include "tic_tac_toe.h"
#include <iostream>

using std::string, std::cout, std::cin, std::vector, std::ostream, std::istream; 

void TicTacToe::start_game(std::string first_player)
{
    player = first_player; 
    clear_board(); 
}

void TicTacToe::mark_board(int position)
{
    pegs[position-1] = player; 
    set_next_player(); 

}


void TicTacToe::set_next_player()
{
    if (player == "X")
    {
        player = "O"; 

    }
    else 
    {
        player = "X"; 
    }

}

bool TicTacToe::check_board_full()
{
    for(auto peg: pegs)
    {
        if(peg == " ")
        {
            return false; 
        }

    }

    return true; 

}

void TicTacToe::clear_board()
{
    for(auto& peg: pegs)
    {
        peg = " "; 
    }

}

bool TicTacToe::game_over()
{

    bool row_win = false; 
    bool column_win = false; 
    bool diagonal_win = false; 
    bool win = false; 

    row_win = check_row_win(); 
    column_win = check_column_win(); 
    diagonal_win = check_diagonal_win(); 

  
    if (row_win == true || column_win == true || diagonal_win == true)
    {
        set_winner(); 
        win = true; 
    }
    else if (check_board_full() == true) //assume tie if the board is full 
    {
        winner = "C"; 
        win = true; 
    }


    return win; 

    
    //return check_board_full();  
    //previous HW06 code 

}

bool TicTacToe::check_column_win()
{
   
    return false; 
}

bool TicTacToe::check_row_win()
{

    return false; 

}

 bool TicTacToe::check_diagonal_win()
{

    return false; 

}

void TicTacToe::set_winner()
{
    if (player=="X")
    {
        winner = "O"; 
    }
    else 
    {
        winner = "X"; 
    }

}

//Overloaded cout to output the board 
std::ostream& operator<<(std::ostream& out, const TicTacToe& game) //probably need to use size to modify 
{
    int length = game.pegs.size(); 
    if (length == 9)
    {
         for(int i=0; i < length; i += 3)  
        {
            out<<game.pegs[i]<<"|"<<game.pegs[i+1]<<"|"<<game.pegs[i+2]<<"\n"; 
         }

    }
    else if (length == 16)
    {
        for (int i=0; i < length; i += 4)  
            {
                out<<game.pegs[i]<<"|"<<game.pegs[i+1]<<"|"<<game.pegs[i+2]<<"|"<<game.pegs[i+3]<<"\n"; 
                }
    }
    return out; 

}


//Overloaded cin to capture position 
std::istream& operator>>(std::istream& in, TicTacToe &game)
{ 
    int position; 
    int length = game.pegs.size(); 
    if (length == 9)
    {
        cout<<"Enter position [1-9]: "; 
	    in>>position; 
    }
    else if (length == 16)
    {
        cout<<"Enter position [1-16]: "; 
	    in>>position; 
    }

    if (position >= 1 && position <= length) //input validation to ensure that postion is within accepted range, otherwise board will stay empty 
		{
			game.mark_board(position); 
		}

    return in; 

}

