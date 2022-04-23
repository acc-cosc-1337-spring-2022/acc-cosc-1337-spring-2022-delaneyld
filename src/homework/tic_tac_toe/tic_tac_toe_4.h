//h

//#include <string>
//#include <iostream> 
#include "tic_tac_toe.h"

#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H

//doesn't inherit construcotr, operator=, friends, private 

class TicTacToe4: public TicTacToe
{
public:  
    TicTacToe4(std::vector<std::string> p, std::string winner):TicTacToe(p, winner){} 
    TicTacToe4():TicTacToe(4){} //default constructor with inializer for TicTacToe

private: 
    bool check_column_win(); 
    bool check_row_win(); 
    bool check_diagonal_win(); 

}; 

#endif