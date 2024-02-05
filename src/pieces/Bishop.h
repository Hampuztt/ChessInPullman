
#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece {
 public:
  Bishop(Color color);
  char symbol() const override;
};
