//h

#include <string>
#include <vector>
#include <iostream>
#include "tic_tac_toe.h"

#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H

//derived class
//doesn't inherit construcotr, operator=, friends, private 

class TicTacToe3: public TicTacToe
{
public: 
    TicTacToe3():TicTacToe(3){} //default contructor with initizer to initialize TicTacToe to 3
    //virtual ~TicTacToe3(){}

private: 
    // bool check_column_win(); 
    // bool check_row_win(); 
    // bool check_diagonal_win(); 
    bool check_column_win() override; 
    bool check_row_win() override; 
    bool check_diagonal_win() override; 

}; 

#endif