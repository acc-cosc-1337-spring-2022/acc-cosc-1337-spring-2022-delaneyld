#include "tic_tac_toe.h"

using std::cout; using std::cin; using std::string; 

int main() 
{
	TicTacToe game; 
	string first_player;
	char choice; 

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

	int position; 

	while( game.game_over() == false) //play while game board is not full 
	{
		cout<<"Enter position [1-9]: "; 
		cin>>position; 
		if (position >= 1 && position <= 9) //input validation to ensure that postion is within accepted range, otherwise board will stay empty 
		{
			game.mark_board(position); 
		}
		game.display_board(); 

	}

	if (game.game_over() == true) //display winner 
	{

		if (game.get_winner() != "C") //check that there is no tie and display winner 
		{
			cout<< "\n" << game.get_winner() << " is the winner!"<< "\n"; 
		}
		else //tie case 
		{
			cout<< "\nThere is no winner. The game was a tie."<< "\n"; 
		}

	}

	cout<<"Continue type Y: ";
	cin>>choice; 

	} while(choice == 'Y'|| choice == 'y');
	

	return 0;
}