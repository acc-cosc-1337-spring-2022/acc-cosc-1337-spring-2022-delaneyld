#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include <string>

using std::string; 

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test tic tac toe game over for a tie" )
{
	TicTacToe game; 
	string first_player = "X"; 
	game.start_game(first_player); 
	game.mark_board(1); // X move
	REQUIRE(false == game.game_over()); 
	game.mark_board(3); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(2); // X move 
	REQUIRE(false == game.game_over());
	game.mark_board(4); 
	REQUIRE(false == game.game_over());
	game.mark_board(5); // X move 
	REQUIRE(false == game.game_over());
	game.mark_board(8); 
	REQUIRE(false == game.game_over());
	game.mark_board(7); // X move 
	REQUIRE(false == game.game_over());
	game.mark_board(9); 
	REQUIRE(false == game.game_over());
	game.mark_board(6); // X move 
	REQUIRE(true == game.game_over());

	REQUIRE("C" == game.get_winner()); 


}

TEST_CASE("Test first player set to x" )
{
	TicTacToe game; 
	string first_player = "X"; 
	game.start_game(first_player); 
	REQUIRE("X" == game.get_player()); 

}

TEST_CASE("Test first player set to O" )
{
	TicTacToe game; 
	string first_player = "O"; 
	game.start_game(first_player); 
	REQUIRE("O" == game.get_player()); 

}

TEST_CASE("Test win by first column" )
{
	TicTacToe game; 
	string first_player = "X"; 
	game.start_game(first_player); 
	game.mark_board(1); //X move
	REQUIRE(false == game.game_over()); 
	game.mark_board(2); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(4); //X move 
	REQUIRE(false == game.game_over()); 
	game.mark_board(8); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(7); //X move 
	REQUIRE(true == game.game_over()); 

}

TEST_CASE("Test win by second column" )
{
	TicTacToe game; 
	string first_player = "X"; 
	game.start_game(first_player); 
	game.mark_board(2); //X move
	REQUIRE(false == game.game_over()); 
	game.mark_board(3); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(5); //X move 
	REQUIRE(false == game.game_over()); 
	game.mark_board(7); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(8); //X move 
	REQUIRE(true == game.game_over()); 

}

TEST_CASE("Test win by third column" )
{
	TicTacToe game; 
	string first_player = "X"; 
	game.start_game(first_player); 
	game.mark_board(3); //X move
	REQUIRE(false == game.game_over()); 
	game.mark_board(4); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(6); //X move 
	REQUIRE(false == game.game_over()); 
	game.mark_board(7); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(9); //X move 
	REQUIRE(true == game.game_over()); 

}

TEST_CASE("Test win by first row" )
{
	TicTacToe game; 
	string first_player = "X"; 
	game.start_game(first_player); 
	game.mark_board(1); //X move
	REQUIRE(false == game.game_over()); 
	game.mark_board(8); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(2); //X move 
	REQUIRE(false == game.game_over()); 
	game.mark_board(7); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(3); //X move 
	REQUIRE(true == game.game_over()); 

}

TEST_CASE("Test win by second row" )
{
	TicTacToe game; 
	string first_player = "X"; 
	game.start_game(first_player); 
	game.mark_board(4); //X move
	REQUIRE(false == game.game_over()); 
	game.mark_board(8); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(5); //X move 
	REQUIRE(false == game.game_over()); 
	game.mark_board(7); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(6); //X move 
	REQUIRE(true == game.game_over()); 

}

TEST_CASE("Test win by third row" )
{
	TicTacToe game; 
	string first_player = "X"; 
	game.start_game(first_player); 
	game.mark_board(7); //X move
	REQUIRE(false == game.game_over()); 
	game.mark_board(5); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(8); //X move 
	REQUIRE(false == game.game_over()); 
	game.mark_board(6); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(9); //X move 
	REQUIRE(true == game.game_over()); 

}

TEST_CASE("Test win diagonally from top left" )
{
	TicTacToe game; 
	string first_player = "X"; 
	game.start_game(first_player); 
	game.mark_board(1); //X move
	REQUIRE(false == game.game_over()); 
	game.mark_board(2); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(5); //X move 
	REQUIRE(false == game.game_over()); 
	game.mark_board(6); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(9); //X move 
	REQUIRE(true == game.game_over()); 

}

TEST_CASE("Test win diagonally from bottom left" )
{
	TicTacToe game; 
	string first_player = "X"; 
	game.start_game(first_player); 
	game.mark_board(7); //X move
	REQUIRE(false == game.game_over()); 
	game.mark_board(2); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(5); //X move 
	REQUIRE(false == game.game_over()); 
	game.mark_board(6); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(3); //X move 
	REQUIRE(true == game.game_over()); 

}