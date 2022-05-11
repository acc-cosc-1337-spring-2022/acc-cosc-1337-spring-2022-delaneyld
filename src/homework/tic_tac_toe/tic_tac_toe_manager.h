//h

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include "tic_tac_toe_data.h"


#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

class TicTacToeManager
{
public: 
    TicTacToeManager() = default; //add default constructor 
    TicTacToeManager(TicTacToeData data); //TicTacToeData reference parameter
    void save_game(std::unique_ptr<TicTacToe>& b); //unique pointer of TicTacToe reference 
    friend std::ostream& operator<<(std::ostream & out, const TicTacToeManager & manager); 
    void get_winner_total(int& o, int& x, int& t); // note - w changed to x here 
    ~ TicTacToeManager(); //destructor 

private: 
    std::vector<std::unique_ptr<TicTacToe>> games; 
    int x_win{0};
    int o_win{0}; 
    int ties{0}; 
    void update_winner_count(std::string winner); 
    TicTacToeData data; 

}; 

#endif
