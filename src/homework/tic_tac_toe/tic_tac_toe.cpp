//cpp

#include "tic_tac_toe.h"
#include <iostream>

using std::string, std::cout; 

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

void TicTacToe::display_board() const
{
    for(int i=0; i < 9; i +=3)
    {
        cout<<pegs[i]<<"|"<<pegs[i+1]<<"|"<<pegs[i+2]<<"\n"; 

    }

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
    return check_board_full(); 

}