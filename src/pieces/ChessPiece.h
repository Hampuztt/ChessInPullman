#pragma once
#include <vector>

#include "Helpers.h"

class ChessPiece {
 public:
  virtual ~ChessPiece() = default;
  virtual char symbol() const = 0;
  ChessPiece(Color color);
  virtual std::vector<Move> generateMoves(std::pair<int, int> position);
  char getNotationName() const;
  Color color_;

 protected:
  void addMove(std::vector<Move>& moves, std::pair<int, int> position, int dx,
               int dy, MoveCondition movetype = MoveCondition::None) const;
};
