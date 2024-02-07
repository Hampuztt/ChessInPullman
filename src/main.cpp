#include <iostream>
#include <ostream>
#include <string>

#include "ChessBoard.h"
int main(int argc, char *argv[]) {
  std::string start_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
  ChessBoard gameboard;
  gameboard.loadFenBoard(start_fen);
  // gameboard.makeMove("e2", "e3");

  gameboard.printBoard();
  while (true) {
    std::cout << "Make your move (or type 'quit' to exit): ";

    std::string from, to;
    std::cin >> from >> to;
    if (from == "quit") {
      std::cout << "Game ended." << std::endl;
      break;
    }

    if (!gameboard.makeMove(from, to)) {
      std::cout << "Invalid move, try again." << std::endl;
    }

    std::cout << "\033[2J\033[1;1H" << std::endl;
    gameboard.printBoard();
  }

  return 0;
}
