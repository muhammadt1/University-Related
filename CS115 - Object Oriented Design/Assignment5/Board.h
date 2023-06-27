//
//  Board.h
//

#pragma once

#include <string>


#include "BoardValue.h"

const int BOARD_SIZE = 19;
const int BOARD_SIZE_MIN = 1;
const int BOARD_SIZE_MAX = 24;
const int BOARD_SIZE_DEFAULT = 19;
const int NEW_BOARD = BOARD_SIZE*BOARD_SIZE;

const int STAR_POINT_SPACING = 6;


struct StonesRemoved
{
	int us;
	int them;
};

//
//  Board
//
//  A class to represent the complete position of the game
//    board.  This is which colour of stone (if any) is at each
//    point.
//
//  Class Invariant:
//    <1> isBoardValueValid(places[r][c])
//                                    WHERE 0 <= r < BOARD_SIZE
//                                    WHERE 0 <= c < BOARD_SIZE
//






//
//  isInvariantTrue
//
//  Purpose: Checks if the boars is in a valid state by verifying that the board size is within limits and that the total number of places matches the calculated place count 

//  Parameter(s): N/A
//  Precondition(s): N/A

//  Returns: Returns a voolean value to show if the board is valid or not.
//  Side Effect: No changes are made when this function is implemented. More over used to return information
//


class Board
{
public:
  ~Board ();
  Board (const Board& board_in);
  Board& operator= (const Board& board_in);



//
//  isOnBoard
//
//  Purpose: Checks whether a position is wihin the limits of the board.
//  Parameter(s):
//    <1> row_in: The row of the place to check
//    <2> column_in: The column of the place to check
//  Precondition(s):

//    <1> row_in must be greater than 0.
//    <2> column_in must be greater than 0.
//  Returns: Bool that tell us if its within board limits. True value means its on board and false means its off board.

//  Side Effect: Does not change the code.
//
  bool isOnBoard (int row_in, int column_in) const;



//
//  Board(int size_in)
//
//  Purpose: Constuctor for class Board that initializes the board with a size.
//  Parameter(s):
//    <1> size_in: integer value representing the size of the board that will be made.
//  Precondition(s):

//    <1> size_in must be within the range of BOARD_SIZE_MIN and BOARD_SIZE_MAX.

//  Returns: N/A

//  Side Effect: Function initializes the boards object member variables including the pointer p_places. Also creates a new dynamic array of total_number to represent the board's cells.
//
  Board (int size_in); //size constructor



//
//  getSize
//
//  Purpose: Get the total number of cells on a board.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: total number of cells on the board.
//  Side Effect: No changes are made when this function is implemented. More over used to return information
//
  bool getSize() const;


//
//  Default Constructor
//
//  Purpose: To create an empty Board.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: A new Board is initialized.  Every place is set
//               to BOARD_VALUE_EMPTY.
//
	Board ();

//
//  getAt
//
//  Purpose: To determine the board value at one place.
//  Parameter(s):
//    <1> row_in: The row of the place to check
//    <2> column_in: The column of the place to check
//  Precondition(s):
//    <1> isOnBoard(row_in, column_in)
//  Returns: The board value at place (row_in, column_in).
//  Side Effect: N/A
//
	char getAt (int row_in, int column_in) const;

//
//  print
//
//  Purpose: To display the board.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The current board position (state) is printed
//               to standard output (cout).  This includes the
//               row numbers, column letters, and any empty star
//               points.
//
	void print () const;

//
//  countWithValue
//
//  Purpose: To determine the number of places on the board with
//           the specified value.  This function can be used to
//           count a player's stones.  To determine the player's
//           score, use calculateScore.
//  Parameter(s):
//    <1> value_in: The board value to count
//  Precondition(s):
//    <1> isBoardValueValid(us_value_in)
//  Returns: The number of places on the board that have value
//           value_in.
//  Side Effect: N/A
//
	int countWithValue (char value_in) const;

//
//  calculateScore
//
//  Purpose: To determine the score for a player.  The function
//           considers controlled territory.
//  Parameter(s):
//    <1> us_value_in: The board value for the player
//  Precondition(s):
//    <1> isBoardValuePlayer(us_value_in)
//  Returns: The score for the player playing stones with value
//           us_value_in.
//  Side Effect: N/A
//
	int calculateScore (char us_value_in) const;

//
//  setAt
//
//  Purpose: To set the board value at one place.  This function
//           does not detect captured stones.
//  Parameter(s):
//    <1> row_in: The row of the place to change
//    <2> column_in: The column of the place to change
//    <3> value_in: The new board value
//  Precondition(s):
//    <1> isOnBoard(row_in, column_in)
//    <2> isBoardValueValid(us_value_in)
//  Returns: N/A
//  Side Effect: Board place (row_in, column_in) is set to value
//               value_in.
//
	void setAt (int row_in, int column_in,
	            char value_in);

//
//  load
//
//  Purpose: To load a board position (state) from a file.
//  Parameter(s):
//    <1> filename_in: The name of the file to load from,
//                     including the file extension
//  Precondition(s):
//    <1> filename_in != ""
//  Returns: N/A
//  Side Effect: The contents of this Board are replaced with
//               the board position in file filename_in.  If
//               anything goes wrong, an error message is
//               printed and this Board is left in a
//               consistant state.  It may be unchanged, or it
//               may have a mix of data from the file and
//               BOARD_VALUE_EMPTY values.
//
	void load (const std::string& filename_in);

//
//  playStone
//
//  Purpose: To play a stone and remove any captured stones.
//  Parameter(s):
//    <1> row_in: The row to play the stone at
//    <2> column_in: The column to play the stone at
//    <3> us_value_in: The board value of the stone played
//  Precondition(s):
//    <1> isOnBoard(row_in, column_in)
//    <2> getAt(row_in, column_in) == BOARD_VALUE_EMPTY
//    <3> isBoardValuePlayer(us_value_in)
//  Returns: How many stones of each color were captured.
//  Side Effect: Board place (row_in, column_in) is set to value
//               value_in.  Any stones of either color that are
//               captured are removed.
//
	StonesRemoved playStone (int row_in, int column_in,
	                         char us_value_in);

//
//  replaceAll
//
//  Purpose: To replace all instances of one value on this
//           Board with another value.
//  Parameter(s):
//    <1> old_value_in: The value to replace
//    <2> new_value_in: The replacement value
//  Precondition(s):
//    <1> isBoardValueValid(old_value_in)
//    <2> isBoardValueValid(new_value_in)
//  Returns: N/A
//  Side Effect: Every place on this Board that has value
//               old_value_in is set to have value new_value_in.
//
	void replaceAll (char old_value_in,
char new_value_in);

//
//  fillConnected
//
//  Purpose: To replace all instances of one value on this
//           Board that are connected to another value with a
//           third value.  Place A is connected to place B if
//    <1> A is next to B.
//    <2> A is next to a place of the same type that fulfills
//        either of these conditions.  Note that this allows
//        arbitrarily long connection chains.
//  Parameter(s):
//    <1> old_value_in: The value to replace
//    <2> new_value_in: The replacement value
//    <3> neighbour_value_in: The value old_value_in must be
//                            connected to
//  Precondition(s):
//    <1> isBoardValueValid(old_value_in)
//    <2> isBoardValueValid(new_value_in)
//    <3> isBoardValueValid(neighbour_value_in)
//  Returns: N/A
//  Side Effect: Every place on this Board that has value
//               old_value_in and is connected to at least one
//               place with value neighbour_value_in is set to
//               have value new_value_in.
//  Warning: This function is slow.
//
	void fillConnected (char old_value_in,char new_value_in, char neighbour_value_in);

//
//  isANeighbourWithValue
//
//  Purpose: To determine if a place has a neighbour with the
//           specified board value.  This function correctly
//           handles the edge of the board.
//  Parameter(s):
//    <1> row_in: The row of the place to check
//    <2> column_in: The column of the place to check
//    <3> value_in: The board value to check for
//  Precondition(s):
//    <1> isOnBoard(row_in, column_in)
//    <2> isBoardValueValid(value_in)
//  Returns: Whether any of the four neighbours of board place
//           (row_in, column_in) have value value_in.  Note that
//           a place is NOT its own neighbour.
//  Side Effect: N/A
//
	bool isANeighbourWithValue (int row_in, int column_in,char value_in) const;

private:
	bool isAlignedForStarPoint (int index_in) const;
	void printRowNumber (int row_in) const;
	void printColumnLetters () const;
	int capturePlayer (char player_value_in);
	bool isInvariantTrue () const;
  void copyData (const Board& board_in);
  


private:
	char* p_places; //member pointer of the class
  int toIndex (int row_in, int column_in)const;
  void destroyData ();
  int board_size = BOARD_SIZE;
  int total_number = NEW_BOARD;
  int calculatePlaceCount () const;

};



