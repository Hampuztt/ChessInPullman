
#pragma once

#include <array>
#include <cctype>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "pieces/Bishop.h"
#include "pieces/ChessPiece.h"
#include "pieces/Empty.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"

class ChessBoard {
 public:
  ChessBoard();  // Constructor

  void setUpBoard();
  void printBoard();
  void loadFenBoard(std::string fenString);

 private:
  std::array<std::array<std::unique_ptr<ChessPiece>, 8>, 8> gameBoard;

  std::unique_ptr<ChessPiece> buildChessPiece(char letter);
};
