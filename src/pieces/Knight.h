
#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece {
 public:
  Knight(Color color);
  char symbol() const override;
};
