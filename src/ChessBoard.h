
#pragma once

#include <algorithm>
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
#include "pieces/Helpers.h"
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
  void loadFenBoard(const std::string &fenString);
  bool makeMove(const std::string &from, const std::string &to);

 private:
  std::array<std::array<std::unique_ptr<ChessPiece>, 8>, 8> gameBoard;
  std::vector<Move> getLegalPieceMoves(ChessPiece *piece,
                                       std::pair<int, int> position);
  std::unique_ptr<ChessPiece> buildChessPiece(char letter);
  bool isPawnCapture(Move move);
  void filterInvalidMoves(std::vector<Move> &moves);
  ChessPiece *getPiece(std::pair<int, int> position);
};
