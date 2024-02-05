#include <iostream>
#include <ostream>
#include <string>

#include "ChessBoard.cpp"
int main(int argc, char *argv[]) {
  std::string start_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
  ChessBoard gameboard = ChessBoard();
  gameboard.setUpBoard();
  gameboard.loadFenBoard(start_fen);
  gameboard.printBoard();
  return 0;
}
