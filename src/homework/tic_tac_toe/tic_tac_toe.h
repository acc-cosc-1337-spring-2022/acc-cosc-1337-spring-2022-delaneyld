//h

#include <string>
#include <vector>
#include <iostream>



#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe
{
public: 
    bool game_over(); 
    void start_game(std::string first_player); 
    void mark_board(int position); 
    std::string get_player()const{return player;} //if only 1 var do here
    std::string get_winner()const{return winner;}
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game); 
    friend std::istream& operator>>(std::istream& in, TicTacToe& game); 

private: 
    std::string player; 
    std::string winner; 
    std::vector<std::string> pegs{9, " "}; 
    void set_next_player(); 
    bool check_board_full(); 
    void clear_board(); 
    bool check_column_win(); 
    bool check_row_win(); 
    bool check_diagonal_win();
    void set_winner(); 
}; 

#endif

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

class TicTacToeManager
{
public: 
    void save_game(TicTacToe b); 
    friend std::ostream& operator<<(std::ostream & out, const TicTacToeManager & manager); 
    void get_winner_total(int& o, int& x, int& t); // note - w changed to x here 

private: 
    std::vector <TicTacToe> games; 
    int x_win{0};
    int o_win{0}; 
    int ties{0}; 
    void update_winner_count(std::string winner); 

}; 

#endif