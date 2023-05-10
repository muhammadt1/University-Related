#include <iostream>
#include <cassert>
#include <fstream>
#include <iomanip>
#include "BoardSize.h"
#include "Board.h"
#include "BoardValue.h"
using namespace std;

char boardGetAt (const Board& board_in, int row_in, int column_in)
{
  int boardCheck = (isOnBoard(row_in,column_in));
  assert(boardCheck);
  int arrays = board_in.boardArray[row_in][column_in];
  
  return arrays;
  
}
void boardSetAt (Board& board_in, int row_in, int column_in, char value_in)
{
  int boardCheck = (isOnBoard(row_in,column_in));
  
  assert(boardCheck);
  assert(isBoardValueValid(value_in));
  

  board_in.boardArray[row_in][column_in] =value_in; 
  cout << board_in.boardArray[row_in][column_in];
  
}
void boardClear (Board& board_in)
{
  int i,j;

  for (i = 0; i < BOARD_SIZE; i++)
  {
    for (j = 0; j < BOARD_SIZE; j++)
    {
      board_in.boardArray[i][j] = BOARD_VALUE_EMPTY;
    }
  }
  
}
int boardCountWithValue (const Board& board_in, char value_in)
{
  int valid = isBoardValueValid(value_in);
  assert(valid);
  int i = 0; 
  int loop = 0;
  int j;
  int increment = 0;

  //While loop used to avoid confusion for myself with boardClear for loops.

  while (i < BOARD_SIZE)
  {
    for (j = 0; j < BOARD_SIZE; j++)
    {
      if (board_in.boardArray[i][j] == value_in)
      {
        increment++;
      }
    }
    i++;  
  }
  return increment;
  
}
void boardPrint (const Board& board_in)
{
  int i, j;

  boardPrintColumnLetters (board_in);

  cout <<" ";

  for (i = 0; i < BOARD_SIZE; i++)
  {
    cout << setw(2) << i+1;
    cout << " ";
    for (j = 0; j < BOARD_SIZE;j++)
    {
      if (board_in.boardArray[i][j]==0)
      {
        if(board_in.boardArray[i])
        {
          if (board_in.boardArray[j])
          {
            cout << "*";
          }
        }
      }
      else
      {
        cout << board_in.boardArray[i][j]<<' ';
      }
      
    }
  }
 
  
  cout <<endl;
}

void boardLoad (Board& board_in,
                const string& filename_in)
{
	assert(filename_in != "");

	// open file with name filename_in
	// fin will read from that file
	// use fin like you use cin
	ifstream fin(filename_in);

	if(!fin)
	{
		cout << "Error: Could not open file \"" << filename_in << "\"" << endl;
		return;  // end function immediately
	}

	// read in the board size
	string line;
	int board_size_read;
	fin >> board_size_read;
	if(!fin)
	{
		cout << "Error: File \"" << filename_in << "\" does not start with board size" << endl;
		return;  // end function immediately
	}
	if(board_size_read != BOARD_SIZE)
	{
		cout << "Error: File \"" << filename_in << "\" has board size "
		     << board_size_read << ", but must be " << BOARD_SIZE << endl;
		return;  // end function immediately
	}
	assert(fin);
	string dummy;
	getline(fin, dummy);  // throw away whatever else is on the line

	// read in board state
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
				boardSetAt(board_in, r, c, line[c]);
			else
			{
				boardSetAt(board_in, r, c, BOARD_VALUE_EMPTY);
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
}
bool boardIsAlignedForStarPoint (int index_in)
{
  if (index_in > 0)
  {
    return true;
  }

  int modulus = (BOARD_SIZE % STAR_POINT_SPACING) / 2;
  if (index_in % STAR_POINT_SPACING != modulus )
  {
    return false;
    
  }
  return index_in % STAR_POINT_SPACING == modulus;
}
void boardPrintRowNumber (int row_in)
{
  if (row_in < 9)
  {
    cout << " "<<row_in<<" ";
  }
  else 
  {
    cout << row_in << " ";
  }
}
void boardPrintColumnLetters (const Board& board_in)
{
  int i;
  char letter;

  if (char(letter)+i == 'I' ||char(letter)+i == 'O') 
  {
    cout << "Ill formed string"<<endl;
  }
  for (i = 0; i < BOARD_SIZE; i++)
  {
    cout << " ";
    cout << (char)('A'+i);
  }
  
  cout << endl;
}
