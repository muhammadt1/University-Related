#pragma once
#include <string>
#include "BoardSize.h"
using namespace std;


struct Board
{
  char boardArray [BOARD_SIZE][BOARD_SIZE];
};

const int STAR_POINT_SPACING = 6;


char boardGetAt (const Board& board_in, int row_in, int column_in);
void boardSetAt (Board& board_in, int row_in, int column_in, char value_in);
void boardClear (Board& board_in);
void boardLoad (Board& board_in, const string& filename_in);
int boardCountWithValue (const Board& board_in, char value_in);
void boardPrint (const Board& board_in);

bool boardIsAlignedForStarPoint (int index_in);

void boardPrintRowNumber (int row_in);
void boardPrintColumnLetters (const Board& board_in);

