#include "Board.h"
#include "Move.h"
#include "PlaceString.h"
#include "BoardSize.h"
#include "BoardValue.h"
#include "Board.h"


class Game;

struct MoveResult 
{
  bool legal;
  float net_score;
};

class ArtificialIntelligence
{
  private:
    ArtificialIntelligence();
    Board player_value[BOARD_SIZE][BOARD_SIZE];
    float calculateNetScore (const Board& board_in) const;
    MoveResult getPlayResult (const Board& board_in,int row_in, int column_in) const;
    bool isInvariantTrue () const;
    void printRemoved (const StonesRemoved& removed_in) const;

  public:
    ArtificialIntelligence (char us_value_in);
    Move chooseMove (const Board& board_in) const;


};