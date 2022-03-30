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
	game.mark_board(1); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(2); 
	REQUIRE(false == game.game_over()); 
	game.mark_board(3); 
	REQUIRE(false == game.game_over());
	game.mark_board(4); 
	REQUIRE(false == game.game_over());
	game.mark_board(5); 
	REQUIRE(false == game.game_over());
	game.mark_board(6); 
	REQUIRE(false == game.game_over());
	game.mark_board(7); 
	REQUIRE(false == game.game_over());
	game.mark_board(8); 
	REQUIRE(false == game.game_over());
	game.mark_board(9); 
	REQUIRE(true == game.game_over());


}

