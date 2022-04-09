#include "tic_tac_toe.h"

using std::cout; using std::cin; using std::string; 

int main() 
{
	TicTacToe game; 
	TicTacToeManager manager; 
	string first_player;
	char choice; 
	int o; int x; int t; 

	do
	{

	cout<<"Enter first player (X or O): "; 
	cin>>first_player; 

	if (first_player == "O" || first_player == "X") //input validation that first player symbol was X or O 
	{
		game.start_game(first_player); 
	}
	else 
	{
		cout<<"Please enter only O or X for your player symbol: "; 
		cin>>first_player; 
		game.start_game(first_player); 
	}

	while( game.game_over() == false) //play while game board is not full 
	{
		cin >> game; //call overloaded position function 
		cout << game; //call overloaded display board function 

	}

	if (game.game_over() == true) //display winner 
	{

		if (game.get_winner() != "C") //check that there is no tie and display winner 
		{
			cout<< "\n" << game.get_winner() << " is the winner!"<< "\n\n"; 
		}
		else //tie case 
		{
			cout<< "\nThere is no winner. The game was a tie."<< "\n\n"; 
		}

		manager.save_game(game); //save game to TicTacToeManager
		manager.get_winner_total(o, x, t); //display running scores to user 

	}

	cout<<"\nContinue type Y: ";
	cin>>choice; 

	} while(choice == 'Y'|| choice == 'y');

	//after user opts out of playing, display all the games played 
	cout<<manager; 
	

	return 0;
}