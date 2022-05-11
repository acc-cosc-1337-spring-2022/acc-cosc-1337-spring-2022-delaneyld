//h

#include <string>
#include <vector>
#include <iostream>
#include <memory>


#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe
{
public: 
    TicTacToe(){} //default constructor 
    TicTacToe(int size):pegs(size*size, " "){}; //SomeConstructor(int s) :some_vector(s*s, " " ){} -- this will initialize some_vector to s*s elements of " "- This is called an initializer list
    TicTacToe(std::vector<std::string> p, std::string winner):pegs({p}), winner(winner){} //MISSING code here to initialize the pegs vector with p and initialize winner

    bool game_over(); 
    void start_game(std::string first_player); 
    void mark_board(int position); 
    std::string get_player()const{return player;} //if only 1 var do here
    std::string get_winner()const{return winner;}
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game); 
    friend std::istream& operator>>(std::istream& in, TicTacToe& game); 
    std::vector<std::string> get_pegs()const{return pegs;}
    virtual ~TicTacToe(){} 

private: 
    std::string player; 
    std::string winner; 
    void set_next_player(); 
    bool check_board_full(); 
    void clear_board(); 
    void set_winner(); 

protected: 
    std::vector<std::string> pegs; 
    // bool check_column_win(); 
    // bool check_row_win(); 
    // bool check_diagonal_win(); 
    virtual bool check_column_win(); 
    virtual bool check_row_win(); 
    virtual bool check_diagonal_win();
}; 

#endif

