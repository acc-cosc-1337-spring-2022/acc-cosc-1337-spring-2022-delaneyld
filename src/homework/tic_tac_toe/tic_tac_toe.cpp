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

bool TicTacToe::check_row_win()
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

bool TicTacToe::check_diagonal_win()
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
std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    for(int i=0; i < 9; i +=3)
    {
       out<<game.pegs[i]<<"|"<<game.pegs[i+1]<<"|"<<game.pegs[i+2]<<"\n"; 
    }

    return out; 

}


//Overloaded cin to capture position 
std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position; 
    cout<<"Enter position [1-9]: "; 
	in>>position; 
    if (position >= 1 && position <= 9) //input validation to ensure that postion is within accepted range, otherwise board will stay empty 
		{
			game.mark_board(position); 
		}

    return in; 

}

void TicTacToeManager::save_game(TicTacToe b)
{
    //add the TicTacToe to games vector with push_back
    games.push_back(b); 

    //call update winner count and pass in get_winner function from tictactoe 
    update_winner_count(b.get_winner()); 

}

//Loop through vector of TicTacToe and call TicTacToe cout 
std::ostream& operator<<(std::ostream & out, const TicTacToeManager & manager)
{
    //another way to loop with an iterable 
    // for (auto i = manager.games.begin(); i != manager.games.end(); ++i )
    // {
    //     out << *i << "\n"; 
    // }

    //could also use a for each 
    //for (auto test_game: manager.games)
    //{
    //    out << test_game << "\n";
    //}

    for (int i= 0; i < manager.games.size(); ++ i)
    {
        out << manager.games[i] << "\n"; 
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
    cout << "Ties: " << t << "\n"; 
    
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
