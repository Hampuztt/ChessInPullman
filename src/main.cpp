#include <string>

#include "ChessBoard.h"
int main(int argc, char *argv[]) {
  std::string start_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
  ChessBoard gameboard;
  gameboard.loadFenBoard(start_fen);
  gameboard.printBoard();
  gameboard.makeMove("e2", "e3");
  // gameboard.makeMove
  return 0;
}
