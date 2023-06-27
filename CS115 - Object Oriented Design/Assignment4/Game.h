#pragma once

#include "Board.h"

using namespace std;

static const float KOMI = 7.5f;





class Game
{
  private:
    Board board;
    void printRemoved (const StonesRemoved& removed_in) const;

  public:
    Game();
    Game (const std::string& filename_in);
    void printBoard () const;
    void printWinner () const;
    const Board& getBoard () const;
    void blackPass ();
    bool blackPlay (int row_in, int column_in);
    bool whiteAi ();


};