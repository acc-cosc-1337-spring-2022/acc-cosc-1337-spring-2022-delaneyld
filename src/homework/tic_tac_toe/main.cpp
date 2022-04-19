#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h" 
#include "tic_tac_toe_4.h"
#include <memory>

using std::cout; using std::cin; using std::string; using std::unique_ptr; using std::make_unique; 

int main() 
{
	unique_ptr<TicTacToe> game3 = make_unique<TicTacToe3>(); 
	unique_ptr<TicTacToe> game4 = make_unique<TicTacToe4>();
	unique_ptr<TicTacToe> game;  
	TicTacToeManager manager; 
	string first_player;
	char choice; 
	int o; int x; int t; int type; 
	type = 99; //default value for type to detect input validation errors for game type 

	do
	{

		cout<<"Type 3 for TicTacToe3 or 4 for TicTacToe4: "; 
		cin>>type; 

		if (type == 3)
		{
			game3.reset(new TicTacToe3); //reset pointer for case of multiple games 

			cout<<"Enter first player (X or O): "; 
			cin>>first_player; 

			if (first_player == "O" || first_player == "X") //input validation that first player symbol was X or O 
			{
				game3 -> start_game(first_player); 
			}
			else 
			{
				cout<<"Please enter only O or X for your player symbol: "; 
				cin>>first_player; 
				game3 -> start_game(first_player); 
			}

			while( game3 -> game_over() == false) //play while game board is not full 
			{
				cin>>*game3; //call overloaded position function - needs to be dereferenced 
				cout<<*game3; //call overloaded display board function - needs to be dereferenced 

			}

			if (game3 -> game_over() == true) //display winner 
			{

				if (game3 -> get_winner() != "C") //check that there is no tie and display winner 
				{
					cout<< "\n" << game3 -> get_winner() << " is the winner!"<< "\n\n"; 
				}
				else //tie case 
				{
					cout<< "\nThere is no winner. The game was a tie."<< "\n\n"; 
				}

				manager.save_game(game3); //save game to TicTacToeManager
				manager.get_winner_total(o, x, t); //display running scores to user 

			}
		}
		else if (type == 4)
		{
			//unique_ptr<TicTacToe> game4 = std::move(game3); 
			game4.reset(new TicTacToe4); //reset pointer for case of multiple games 

			cout<<"Enter first player (X or O): "; 
			cin>>first_player; 

			if (first_player == "O" || first_player == "X") //input validation that first player symbol was X or O 
			{
				game4 -> start_game(first_player); 
			}
			else 
			{
				cout<<"Please enter only O or X for your player symbol: "; 
				cin>>first_player; 
				game4 -> start_game(first_player); 
			}

			while( game4 -> game_over() == false) //play while game board is not full 
			{
				cin>>*game4; //call overloaded position function - needs to be dereferenced 
				cout<<*game4; //call overloaded display board function - needs to be dereferenced 

			}

			if (game4 -> game_over() == true) //display winner 
			{

				if (game4 -> get_winner() != "C") //check that there is no tie and display winner 
				{
					cout<< "\n" << game4 -> get_winner() << " is the winner!"<< "\n\n"; 
				}
				else //tie case 
				{
					cout<< "\nThere is no winner. The game was a tie."<< "\n\n"; 
				}

				manager.save_game(game4); //save game to TicTacToeManager
				manager.get_winner_total(o, x, t); //display running scores to user 

			}
			

		}
		else
		{
			cout<<"Input not valid. Please enter 3 or 4 for your TicTacToe game. "; 
		}


		
		cout<<"\nContinue type Y: ";
		cin>>choice; 


	} while(choice == 'Y'|| choice == 'y');

	//after user opts out of playing, display all the games played 
	cout<<manager; 
	

	return 0;
}