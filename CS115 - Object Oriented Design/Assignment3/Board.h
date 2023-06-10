//
//  Board.h
//

#pragma once

#include <string>

#include "BoardSize.h"
#include "BoardValue.h"

const int STAR_POINT_SPACING = 6;

//
//  Board
//
//  A record to represent the complete position of the game
//    board.  This is which colour of stone (if any) is at each
//    point.
//
struct StonesRemoved
{
  int us;
  int them;

};

class Board
{
  public:
    Board();

    //
    // getAt
    // 
    // Purpose: To return the place position using a 2D Array.
    //
    // Parameters: 
    //   <1> row_in: The row position of the 2D array that is returned.
    //   <2> column_in: The column position of the array that is returned.
    //
    // Preconditions:
    //   <1> isOnBoard(row_in, column_in): Checks if the place is within limits.
    // 
    // Returns: The place position.
    // 
    char getAt (int row_in, int column_in) const;
    void print()const;
    int countWithValue(char value_in)const;
    void setAt(int row_in, int column_in, char value_in);
    void load(const std::string &filename_in);
    int calculateScore (char us_value_in) const;
    void replaceAll (char old_value_in, char new_value_in);
    void fillConnected (char old_value_in, char new_value_in, char neighbour_value_in);
    bool isANeighbourWithValue (int row_in, int column_in, char value_in) const;

    //
    // playStone
    // 
    // Purpose: To update the board by placing a stone and capturing any stones of the next player.
    //
    // Parameters: 
    //   <1> row_in: The row position of on the board.
    //   <2> column_in: The column position of on the board.
    //
    // Preconditions:
    //   <1> checks if one of the following is true: if row number is negative, board size is less than row number, column size is negative, column fits on the board.
    //   <2> checks if the place is empty
    // 
    // Returns: Any stones removed.
    // 
    StonesRemoved playStone (int row_in, int column_in, char us_value_in);



  
    
  

  private:
    char places[BOARD_SIZE][BOARD_SIZE];

    bool isAlignedForStarPoint(int index_in)const;
    void printRowNumber(int row_in)const;
    void printColumnLetters()const;
    int capturePlayer (char player_value_in);
    bool isInvariantTrue () const; // new

    
    
};

