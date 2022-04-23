//cpp
#include "tic_tac_toe_manager.h"
#include <iostream>

using std::string, std::cout, std::cin, std::vector, std::ostream, std::istream; 

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

//constructor code in cpp file with initizalization list 
TicTacToeManager::TicTacToeManager(TicTacToeData outputd): data(outputd)
{
    games = outputd.get_games(); 

    for(auto& game: games)
    {
        update_winner_count(game -> get_winner()); 
    }

}

//destructor code 
TicTacToeManager::~TicTacToeManager()
{
    std::cout << "\n Saving games\n"; 
    data.save_games(games); 
}