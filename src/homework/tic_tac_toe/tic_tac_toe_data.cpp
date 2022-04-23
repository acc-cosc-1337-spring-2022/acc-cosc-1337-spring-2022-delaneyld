//cpp
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <string>
#include <memory> 

using std::string, std::cout, std::cin, std::vector, std::ostream, std::istream, std::fstream, std::ofstream, std::ifstream, std::ios;  

void TicTacToeData::save_games(const std::vector<std::unique_ptr<TicTacToe>>& games)
{
    //open file for writing 
    //fstream outFile(file_name, ios::trunc); //this does not work 
    ofstream outFile; 
    outFile.open(file_name); 
    
    //initialize counter variable 
    int count = 0; 

    //check if file is open 
    if(outFile.is_open())
    {
        //for each vector of TicTacToe
        for (auto &game : games)
        {
        
            //int len = game -> get_pegs()[count].length(); - convert string to char 
            //char char_array[len];  - convert string to char 
            //string sample = game -> get_pegs()[count]; - OLD, removed 


            //for each char in string - OLD, removed
            //for (int i= 0; i < len; i++)
            //for (char &sample_char : sample) - OLD, removed 

            for (auto& peg: game -> get_pegs())
            {
                //write char to file 
                //outFile.put(sample_char); 

                //write string to file 
                outFile<<peg; 


                //strcpy(char_array, len.c_str()); - convert string to char 
        
                //end char in string loop 


            }

            //write get winner of game to file - with new line after
            outFile << game -> get_winner() << "\n"; 
            ++count; //add 1 to counter 
            //std::move (game); //MAY HAVE TO DELETE
        }
    }

    //close file 
    outFile.close(); 
}


std::vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    //create vector unique ptr of TicTacToe boards 
    std::vector<std::unique_ptr<TicTacToe>> boards; 
    std::vector<string> sample_pegs;
    string win = "W"; //initial value of winner to create the pointers 
    std::unique_ptr<TicTacToe> sample_board_3 = std::make_unique<TicTacToe3>(sample_pegs, win); //initial pointer for game 3 //REMOVED 
    std::unique_ptr<TicTacToe> sample_board_4 = std::make_unique<TicTacToe4>(sample_pegs, win); //initial pointer for game 4 //REMOVED

    //open file 
    //fstream inFile(file_name, ios::in); //this does not work 
    std::ifstream inFile; 
    inFile.open(file_name); 

    //create a string line 
    string line; 

    //check if file is open 
    if(inFile.is_open())
    {

        while( getline(inFile , line) ) //while loop - loop while lines in file
        {
            std::vector<string> pegs; 
            //string line2; OLD, REMOVED

            //read only first 9 or 16 characters 
            for (int i=0; i < line.length() - 1; ++i)
            {
                string char_string(1, line[i]); 
                pegs.push_back(char_string); 
                //line2.push_back(line[i]); //append char to string - OLD, REMOVED
                //pegs.push_back(line2); // NEW

            }

            //pegs.push_back(line2); //NEW

            //add string to vector of string 
            //pegs.push_back(line2); - REMOVED

            //create a string to get the winner 
            //string win( 1, line[line.length()-1] ); - REMOVED
            string win{line[line.length()-1]}; 

            //create unique ptr of TicTacToe board 
            std::unique_ptr<TicTacToe> game; 

            //if size 9 
            if (pegs.size() == 9) 
            {
                sample_board_3.reset(new TicTacToe3(pegs, win)); //this allows for multiple boards 
                boards.push_back(std::move(sample_board_3)); //add the board to the boards vector 
            }
            //if size 16
            else if (pegs.size() == 16)
            {
                sample_board_4.reset(new TicTacToe4(pegs, win)); //this allows for multiple boards
                boards.push_back(std::move(sample_board_4)); //add the board to the boards vector 
            }

        }
    }

     //close the file 
    inFile.close(); 

    //return boards vector 
    return boards; 

}