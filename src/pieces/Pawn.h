
#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece {
 public:
  Pawn(Color color);
  char symbol() const override;
  std::vector<Move> generateMoves(std::pair<int, int> position) override;
};
