//
//  Game.h
//

#pragma once

#include <string>

#include "Board.h"
#include "ArtificialIntelligence.h"



// uses composition
class Game
{
public:
	Game ();
	Game (const std::string& filename_in);
  Game (int boardsize);

	void printBoard () const;
	void printWinner () const;
	const Board& getBoard () const;

	void blackPass ();
	bool blackPlay (int row_in, int column_in);
	bool whiteAi ();

private:
	void printRemoved (const StonesRemoved& removed_in) const;

private:
	Board board;
	ArtificialIntelligence white;
};
