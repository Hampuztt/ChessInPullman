
#pragma once
#include "ChessPiece.h"

class Rook : public ChessPiece {
 public:
  Rook(Color color);
  char symbol() const override;

  std::vector<Move> generateMoves(std::pair<int, int> position) override;
};
