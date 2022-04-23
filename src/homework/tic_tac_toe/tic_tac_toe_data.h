//h

//#include <string>
//#include <vector>
//#include <iostream>
#include "tic_tac_toe.h"
//#include "tic_tac_toe_3.h" 
//#include "tic_tac_toe_4.h"

#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

class TicTacToeData: public TicTacToe
{
public: 
TicTacToeData(){}
//TicTacToeData():data(get_games()){} //MAY need to delete later 
void save_games(const std::vector<std::unique_ptr<TicTacToe>>& games); 
std::vector<std::unique_ptr<TicTacToe>> get_games(); 

private: 
const std::string file_name{"/Users/Delaney/Documents/tictactoegames.txt"}; 

}; 

#endif