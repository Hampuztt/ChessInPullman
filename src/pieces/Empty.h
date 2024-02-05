
#pragma once
#include "ChessPiece.h"

class Empty : public ChessPiece {
 public:
  Empty(Color color);
  char symbol() const override;
};
