
#pragma once
#include "ChessPiece.h"

class King : public ChessPiece {
 public:
  King(Color color);
  char symbol() const override;
};
