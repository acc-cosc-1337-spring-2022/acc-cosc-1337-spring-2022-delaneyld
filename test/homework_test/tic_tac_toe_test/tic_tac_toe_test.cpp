#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <string>
#include <memory> 

using std::string; using std::unique_ptr; using std::make_unique; 

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test tic tac toe game over for a tie" )
{
	//auto board = unique_ptr<TicTacToe>(); 
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>(); 
	//auto null_deleter = [](game*){ /* Do nothing */ };
	string first_player = "X"; 
	game -> start_game(first_player); 
	game -> mark_board(1); // X move
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(3); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(2); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(4); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(5); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(8); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(7); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(9); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(6); // X move 
	REQUIRE(true == game -> game_over());

	REQUIRE("C" == game -> get_winner()); 


}

TEST_CASE("Test first player set to x" )
{
	//unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	string first_player = "X"; 
	game -> start_game(first_player); 
	REQUIRE("X" == game -> get_player()); 

}

TEST_CASE("Test first player set to O" )
{
	//unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	string first_player = "O"; 
	game -> start_game(first_player); 
	REQUIRE("O" == game -> get_player()); 

}

TEST_CASE("Test win by first column" )
{
	//unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	string first_player = "X"; 
	game -> start_game(first_player); 
	game -> mark_board(1); //X move
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(2); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(4); //X move 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(8); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(7); //X move 
	REQUIRE(true == game -> game_over()); 
	REQUIRE("X" == game -> get_winner()); //NEW ASSERTION - to test get winner 

}

TEST_CASE("Test win by second column" )
{
	//unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	string first_player = "X"; 
	game -> start_game(first_player); 
	game -> mark_board(2); //X move
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(3); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(5); //X move 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(7); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(8); //X move 
	REQUIRE(true == game -> game_over()); 
	REQUIRE("X" == game -> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test win by third column" )
{
	//unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	string first_player = "X"; 
	game -> start_game(first_player); 
	game -> mark_board(3); //X move
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(4); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(6); //X move 
	REQUIRE(false == game-> game_over()); 
	game -> mark_board(7); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(9); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game -> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test win by first row" )
{
	//unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	string first_player = "X"; 
	game-> start_game(first_player); 
	game-> mark_board(1); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(8); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(2); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(7); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(3); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test win by second row" )
{
	//unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	string first_player = "X"; 
	game-> start_game(first_player); 
	game-> mark_board(4); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(8); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(5); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(7); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(6); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test win by third row" )
{
	//unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	string first_player = "X"; 
	game-> start_game(first_player); 
	game-> mark_board(7); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(5); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(8); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(6); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(9); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test win diagonally from top left" )
{
	//unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	string first_player = "X"; 
	game->start_game(first_player); 
	game-> mark_board(1); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(2); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(5); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(6); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(9); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test win diagonally from bottom left" )
{
	//unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	string first_player = "X"; 
	game-> start_game(first_player); 
	game-> mark_board(7); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(2); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(5); //X move 
	REQUIRE(false == game->game_over()); 
	game-> mark_board(6); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(3); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test get winner total function with 3 or more games - TicTacToe3")
{
	//x, t, o variables to be used later 
	int x; 
	int t; 
	int o; 

	//first game - X win 
	unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>(); 
	TicTacToeManager manager; //adding tictactoe manager 
	string first_player = "X"; 
	string winner; 

	game-> start_game(first_player); 
	game-> mark_board(7); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(2); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(5); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(6); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(3); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner()); //NEW ASSERTION - to test get winner
	manager.save_game(game); //add game to manager 

	
	// // //second game - X win 
	first_player = "X"; 
	game.reset(new TicTacToe3); 
	game -> start_game(first_player); 
	game -> mark_board(1); //X move
	REQUIRE(false == game ->game_over()); 
	game -> mark_board(2); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(5); //X move 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(6); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(9); //X move 
	REQUIRE(true == game -> game_over()); 
	REQUIRE("X" == game -> get_winner()); //NEW ASSERTION - to test get winner
	manager.save_game(game); //add game to manager 
	// std::cout << manager; //display games 
	// manager.get_winner_total(o, x, t); 


	//third game - tie 
	first_player = "X"; 
	game.reset(new TicTacToe3); 
	game -> start_game(first_player); 
	game -> mark_board(1); // X move
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(3); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(2); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(4); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(5); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(8); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(7); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(9); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(6); // X move 
	REQUIRE(true == game -> game_over());

	REQUIRE("C" == game -> get_winner()); 
	manager.save_game(game); //add game to manager 

	std::cout << manager; //display games 

	manager.get_winner_total(o, x, t); 

	REQUIRE(2 == x); // 2 x wins 

	REQUIRE(1 == t); // 1 tie 

	REQUIRE(0 == o); // 0 o wins 
}

TEST_CASE("Test tic tac toe game over for a tie 4" )
{
	//x, t, o variables to be used later 
	int x; 
	int t; 
	int o; 

	//TicTacToeManager manager; 
	//auto board = unique_ptr<TicTacToe>(); 
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>(); 
	//auto null_deleter = [](game*){ /* Do nothing */ };
	string first_player = "X"; 
	game -> start_game(first_player); 
	game -> mark_board(1); // X move
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(3); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(2); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(4); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(5); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(8); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(7); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(9); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(6); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(10); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(11); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(13); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(14); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(16);  
	REQUIRE(false == game -> game_over());
	game -> mark_board(12);  //X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(15);  
	REQUIRE(true == game -> game_over());

	REQUIRE("C" == game -> get_winner()); 

	//manager.save_game(game); //add game to manager 
	//std::cout << manager; //display games 
	//manager.get_winner_total(o, x, t); 


}

TEST_CASE("Test first player set to x 4" )
{
	unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>(); 
	string first_player = "X"; 
	game -> start_game(first_player); 
	REQUIRE("X" == game -> get_player()); 

}

TEST_CASE("Test first player set to O 4" )
{
	unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>(); 
	string first_player = "O"; 
	game -> start_game(first_player); 
	REQUIRE("O" == game -> get_player()); 

}

TEST_CASE("Test win by first column 4" )
{
	unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>(); 
	string first_player = "X"; 
	game -> start_game(first_player); 
	game -> mark_board(1); //X move
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(2); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(5); //X move 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(8); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(9); //X move 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(10); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(13); //X move 
	REQUIRE(true == game -> game_over()); 
	REQUIRE("X" == game -> get_winner()); //NEW ASSERTION - to test get winner 

}

TEST_CASE("Test win by second column 4" )
{
	unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>(); 
	string first_player = "X"; 
	game -> start_game(first_player); 
	game -> mark_board(2); //X move
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(3); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(6); //X move 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(7); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(10); //X move 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(8);  
	REQUIRE(false == game -> game_over());
	game -> mark_board(14);  //X move 
	REQUIRE(true == game -> game_over());
	REQUIRE("X" == game -> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test win by third column 4" )
{
	unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>(); 
	string first_player = "X"; 
	game -> start_game(first_player); 
	game -> mark_board(3); //X move
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(4); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(7); //X move 
	REQUIRE(false == game-> game_over()); 
	game -> mark_board(9); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(11); //X move 
	REQUIRE(false == game-> game_over()); 
	game -> mark_board(1); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(15); //X move 
	REQUIRE(true == game-> game_over()); 

	REQUIRE("X" == game -> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test win by first row 4" )
{
	unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>(); 
	string first_player = "X"; 
	game-> start_game(first_player); 
	game-> mark_board(1); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(8); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(2); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(7); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(3); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(10); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(4); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test win by second row 4" )
{
	unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>(); 
	string first_player = "X"; 
	game-> start_game(first_player); 
	game-> mark_board(5); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(10); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(6); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(1); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(7); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(2); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(8); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test win by third row 4" )
{
	unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>(); 
	string first_player = "X"; 
	game-> start_game(first_player); 
	game-> mark_board(9); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(5); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(10); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(6); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(11); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(1); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(12); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test win diagonally from top left 4" )
{
	unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>(); 
	string first_player = "X"; 
	game->start_game(first_player); 
	game-> mark_board(1); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(2); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(6); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(8); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(11); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(10); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(16); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test win diagonally from bottom left 4" )
{
	unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>(); 
	string first_player = "X"; 
	game-> start_game(first_player); 
	game-> mark_board(13); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(2); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(10); //X move 
	REQUIRE(false == game->game_over()); 
	game-> mark_board(6); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(7); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(8); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(4); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner()); //NEW ASSERTION - to test get winner

}

TEST_CASE("Test get winner total function with 3 or more games - TicTacToe4")
{
	//x, t, o variables to be used later 
	int x; 
	int t; 
	int o; 

	//first game - X win 
	//unique_ptr<TicTacToe> board; 
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>(); 
	TicTacToeManager manager; //adding tictactoe manager 
	string first_player = "X"; 
	string winner; 

	game-> start_game(first_player); 
	game-> mark_board(13); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(2); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(10); //X move 
	REQUIRE(false == game->game_over()); 
	game-> mark_board(6); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(7); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(8); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(4); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner());
	manager.save_game(game); //add game to manager 

	
	//second game - X win 
	game.reset(new TicTacToe4); 
	first_player = "X"; 
	game->start_game(first_player); 
	game-> mark_board(1); //X move
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(2); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(6); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(8); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(11); //X move 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(10); 
	REQUIRE(false == game-> game_over()); 
	game-> mark_board(16); //X move 
	REQUIRE(true == game-> game_over()); 
	REQUIRE("X" == game-> get_winner()); //NEW ASSERTION - to test get winner
	manager.save_game(game); //add game to manager 
	// std::cout << manager; //display games 
	// manager.get_winner_total(o, x, t); 


	//third game - tie 
	game.reset(new TicTacToe4); 
	first_player = "X"; 
	game -> start_game(first_player); 
	game -> mark_board(1); // X move
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(3); 
	REQUIRE(false == game -> game_over()); 
	game -> mark_board(2); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(4); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(5); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(8); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(7); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(9); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(6); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(10); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(11); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(13); 
	REQUIRE(false == game -> game_over());
	game -> mark_board(14); // X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(16);  
	REQUIRE(false == game -> game_over());
	game -> mark_board(12);  //X move 
	REQUIRE(false == game -> game_over());
	game -> mark_board(15);  
	REQUIRE(true == game -> game_over());

	REQUIRE("C" == game -> get_winner()); 
	manager.save_game(game); //add game to manager 

	std::cout << manager; //display games 

	manager.get_winner_total(o, x, t); 

	REQUIRE(2 == x); // 2 x wins 

	REQUIRE(1 == t); // 1 tie 

	REQUIRE(0 == o); // 0 o wins 
}