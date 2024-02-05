
#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece {
 public:
  Queen(Color color);
  char symbol() const override;
};
