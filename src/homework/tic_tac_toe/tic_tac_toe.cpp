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

void TicTacToeManager::save_game(std::unique_ptr <TicTacToe> &b)
{
    //call update winner count and pass in get_winner function from tictactoe 
    update_winner_count(b -> get_winner()); //had to replace b.get_winner() with b -> get_winner() 

    //add the TicTacToe to games vector with push_back
    games.push_back(std::move (b) ); //need to add std::move


}

//Loop through vector of TicTacToe and call TicTacToe cout 
std::ostream& operator<<(std::ostream & out, const TicTacToeManager & manager)
{
    // //another way to loop with an iterable 
    // for (auto i = manager.games.begin(); i != manager.games.end(); ++i )
    // {
    //     out << *i << "\n"; 
    // }

    //could also use a for each 
    //for (auto test_game: manager.games)
    //{
    //    out << test_game << "\n";
    //}

    //std::cout<<*manager.games[0]; 

    // for (int i= 0; i < manager.games.size(); i++)
    // {
    //     //  if (i == manager.games.size() - 1) 
    //     //  {
    //     //      break; 

    //     //  }
    //     out << *manager.games[i] << "\n";  

    // }

    //std::cout<<"Loop has been exited. "; 

    for(auto& game: manager.games)
    {
        out << *game << "\n"; //have dereferenced game 

    }

    return out; 

}

//Use references to get the winner, way to verify counts are correct, use for test  
void TicTacToeManager::get_winner_total(int& o, int& x, int& t)  //note - w changed to x here 
{
    
    // o win total 
    o = o_win; // pass private totals to ref var 

    // x win total 
    x = x_win; // pass private totals to ref var 

    // ties total 
    t = ties; // pass private totals to ref var

    //Show the running totals 
    cout << "X wins: "<< x << "\n"; 
    cout << "O wins: "<< o << "\n"; 
    cout << "Ties: " << t << "\n\n"; 
    
}

//update winner count 
void TicTacToeManager::update_winner_count(string winner)
{
    if (winner == "X")
    {
        x_win += 1; 
    }
    else if (winner == "O")
    {
        o_win += 1; 
    }
    else if (winner == "C")
    {
        ties += 1; 
    }

}
