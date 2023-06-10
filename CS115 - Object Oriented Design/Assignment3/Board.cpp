//
//  Board.h
//

#include "Board.h"

#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "BoardSize.h"
#include "BoardValue.h"

using namespace std;

bool Board::isInvariantTrue () const
{
  int r, c;
  for (r = 0; r < BOARD_SIZE;r++)
  {
    for (c = 0; c < BOARD_SIZE;c++)
    {
      if (isBoardValueValid(places[r][c]) == false)
      {
        return false;
      }
    }
  }

  return true;
}

char Board::getAt(int row_in, int column_in) const
{
  assert(isInvariantTrue());
  
  assert(isOnBoard(row_in, column_in));


  return places[row_in][column_in];
}

void Board::setAt(int row_in, int column_in, char value_in)
{
  assert(isInvariantTrue());
  
  assert(isOnBoard(row_in, column_in));
  assert(isBoardValueValid(value_in));

  places[row_in][column_in] = value_in;

  assert(isInvariantTrue());
}

Board::Board()
{
  for (int r = 0; r < BOARD_SIZE; r++)
  {
    for (int c = 0; c < BOARD_SIZE; c++)
    {
      places[r][c] = BOARD_VALUE_EMPTY;
    }
  }
  
  assert(isInvariantTrue());
  
}

void Board:: load (const string& filename_in)
{
	assert(filename_in != "");
  assert(isInvariantTrue());
  

	// open file with name filename_in
	// fin will read from that file
	// use fin like you use cin
	ifstream fin(filename_in);

	if(!fin)
	{
		cout << "Error: Could not open file \"" << filename_in << "\"" << endl;
		return;  
	}

	// read in the board size
	string line;
	int board_size_read;
	fin >> board_size_read;
	if(!fin)
	{
		cout << "Error: File \"" << filename_in << "\" does not start with board size" << endl;
		return;  
	}
	if(board_size_read != BOARD_SIZE)
	{
		cout << "Error: File \"" << filename_in << "\" has board size "
		     << board_size_read << ", but must be " << BOARD_SIZE << endl;
		return; 
	}
	assert(fin);
	string dummy;
	getline(fin, dummy);  
  
	bool is_print_error = true;
	for(int r = 0; r < BOARD_SIZE; r++)
	{
		string line;
		getline(fin, line);
		if(!fin)
		{
			if(is_print_error)
			{
				cout << "Error: Could not read line " << r
				     << " of file \"" << filename_in << "\"" << endl;
				cout << "       Replacing with '.'s" << endl;
				is_print_error = false;
			}
			line = string(BOARD_VALUE_EMPTY, BOARD_SIZE);  // set to '.'s
		}
		else if((int)(line.length()) < BOARD_SIZE)
		{
			if(is_print_error)
			{
				cout << "Error: Line " << r << " of file \"" << filename_in
				     << "\" only contains " << line.length()
				     << " / " << BOARD_SIZE << " characters" << endl;
				cout << "       Adding '.'s to end" << endl;
				is_print_error = false;
			}
			line += string(BOARD_VALUE_EMPTY, BOARD_SIZE);  // add '.'s
		}

		for(int c = 0; c < BOARD_SIZE; c++)
		{
			if(isBoardValueValid(line[c]))
				setAt(r, c, line[c]);
			else
			{
				setAt(r, c, BOARD_VALUE_EMPTY);
				if(is_print_error)
				{
					cout << "Error: Line " << r << ", character " << c
						 << " of file \"" << filename_in
						 << "\" is an invalid '" << line[c] << "' character" << endl;
					cout << "       Substituting '" << BOARD_VALUE_EMPTY << "'" << endl;
					is_print_error = false;
				}
			}
		}
	}

	// file will be closed automatically when fin goes out of scope
  assert(isInvariantTrue());
  
}

int Board::countWithValue(char value_in)const
{
  
  assert(isBoardValueValid(value_in));

  int count = 0;

  for (int r = 0; r < BOARD_SIZE; r++)
  {
    for (int c = 0; c < BOARD_SIZE; c++)
    {
      if (places[r][c] == value_in)
        count++;
    }
  }
  assert(isInvariantTrue());
  return count;
}

void Board::print()const
{
  assert(isInvariantTrue());
  
  printColumnLetters();

  for (int r = 0; r < BOARD_SIZE; r++)
  {
    printRowNumber(r);
    cout << " ";

    for (int c = 0; c < BOARD_SIZE; c++)
    {
      if (places[r][c] == BOARD_VALUE_EMPTY &&
          isAlignedForStarPoint(r) && isAlignedForStarPoint(c))
      {
        cout << "*";
      }
      else
        cout << places[r][c];
      cout << " ";
    }

    printRowNumber(r);
    cout << endl;

    
  }

  printColumnLetters();
  
  
}

bool Board:: isAlignedForStarPoint(int index_in)const
{
  
  assert(index_in >= 0);

  int center_modulus = (BOARD_SIZE / 2) % STAR_POINT_SPACING;
  int index_modulus = index_in % STAR_POINT_SPACING;

  if (index_modulus == center_modulus)
    return true;
  else
    return false;

  assert(isInvariantTrue());
}

void Board::printRowNumber(int row_in)const 
{ 
  cout << right << setw(2) << row_in; 
  
}

void Board::printColumnLetters()const
{
  cout << "   "; // space for row numbers

  // column headings
  for (int c = 0; c < BOARD_SIZE; c++)
  {
    char letter = 'A' + c;
    if (letter >= 'I')
      letter++;
    if (letter >= 'O')
      letter++;
    cout << letter << " ";
    
    assert(isInvariantTrue());
  }

  // don't need to leave space at end of line
  cout << endl;
}

void Board::replaceAll (char old_value_in, char new_value_in)
{
  assert (isBoardValueValid(old_value_in));
  assert (isBoardValueValid(new_value_in));
  
  assert (isInvariantTrue());

  int i,j;

  for ( i = 0; i < BOARD_SIZE; i++)
  {
    for ( j = 0; j < BOARD_SIZE; j++) 
    {
      assert(isBoardValueValid(places[i][j]));

      if (places[i][j] == old_value_in)
      {
        places[i][j] = new_value_in;
      }

      assert(isBoardValueValid(places[i][j]));
      
    }
  }  
  assert (isInvariantTrue());
  
}
bool Board:: isANeighbourWithValue (int row_in, int column_in, char value_in) const
{
  assert (isInvariantTrue());

  assert(isOnBoard(row_in, column_in));
  
  assert(isBoardValueValid(value_in));

  //up
  int rowCheck =row_in-1;

  if (row_in >= 0)
  {
    if (row_in > 0  &&  getAt(rowCheck, column_in) == value_in)
    {
      return true;
    }
  }
  

  //left
  int columnCheck = column_in-1;
  if (column_in >= 0)
  {
    if (column_in> 0 && getAt(row_in, columnCheck) == value_in)
    {
      return true;
    }
  }
 

  //down
  int rowCheck2 = row_in+1;
  int updatedBoard = BOARD_SIZE -1;

  if (row_in < updatedBoard)
  {
    if (rowCheck < updatedBoard && getAt(rowCheck2, column_in) == value_in)
    {
      return true;
    }
  }
 

  //right
  int columnCheck2 = column_in+1;
  int updatedBoard2 = BOARD_SIZE -1;

  if(column_in < updatedBoard2)
  {
    if (columnCheck2 < updatedBoard2 && getAt(row_in, columnCheck2)  == value_in)
    {
      return true;
    }
  }
  

  return false;

  
}
void Board:: fillConnected (char old_value_in, char new_value_in, char neighbour_value_in)
{
  assert (isInvariantTrue());

  assert (isBoardValueValid(old_value_in));
  assert (isBoardValueValid(new_value_in));
  assert (isBoardValueValid(neighbour_value_in));

  bool array;

  
  do
  {
    
    int i, j;
    array = false;
    for (i = 0; i < BOARD_SIZE; i++)
    {
      for (j = 0; j < BOARD_SIZE; j++)
      {
        if (getAt(i, j) == old_value_in)
        {
      
            setAt(i, j, new_value_in);
    
            array = true;            
          
        }
      }
    }
    
  } while (array);


  assert (isInvariantTrue());
  
  
}

int Board::calculateScore (char us_value_in) const
{
  assert (isBoardValueValid(us_value_in));
  assert (isInvariantTrue());
  

  int i, j;

  char p2 = getOtherPlayer(us_value_in);
  
  Board copy = *this;


  for (i = 0; i < BOARD_SIZE;i++)
  {
    for (j = 0; j < BOARD_SIZE;j++)
    {
      if(copy.getAt(i, j) == p2)
      {
        copy.fillConnected(i, j, p2); //fillng empty places for player 2.
      }

      
    }
    
  }

  for (i = 0; i < BOARD_SIZE;i++)
  {
    for (j = 0; j < BOARD_SIZE;j++)
    {
      if (copy.getAt(i, j) == us_value_in)
      {
        copy.fillConnected(i, j, us_value_in); //fillng empty places for player 1 (us).
      }
      
    }
    
  }

  assert (copy.isInvariantTrue());
  
  return copy.countWithValue(us_value_in);

}

int Board:: capturePlayer (char player_value_in)
{

  assert (isBoardValuePlayer(player_value_in));
  
  int i,j;
  int filled;

  for (i = 0; i < BOARD_SIZE;i++) //Place marks
  {
    for (j = 0; j < BOARD_SIZE; j++)
    {

      if (player_value_in == getAt(i,j))
      {
         setAt(i, j, BOARD_VALUE_MARKED);
      }
    }
  }

  for (i = 0; i < BOARD_SIZE;i++) //Left over places
  {
    for (j = 0; j < BOARD_SIZE; j++)
    {
      if(filled == 0)
      {
        if (player_value_in == getAt(i,j))
        {
         setAt(i, j, BOARD_VALUE_EMPTY);
        }
        
      }

      
    }
  }
  
  return filled;
}

StonesRemoved Board::playStone (int row_in, int column_in, char us_value_in)
{
  assert (isInvariantTrue());
  assert (row_in < 0|| BOARD_SIZE < row_in|| column_in < 0|| BOARD_SIZE < column_in);
  assert(places[row_in][column_in] == BOARD_VALUE_EMPTY);

  assert(isBoardValuePlayer(us_value_in)); 

  int removeP1, removeP2;
  char p2;
  
  setAt(row_in, column_in, us_value_in);

  p2 = getOtherPlayer(us_value_in);
  removeP2 = capturePlayer(p2);
  removeP1 = capturePlayer(us_value_in);
  

  assert (isInvariantTrue());
  
  return StonesRemoved {removeP1,removeP2};
}

