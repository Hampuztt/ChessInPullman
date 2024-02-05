#include "ChessBoard.h"

#include <iostream>
#include <ostream>
#include <utility>

#include "pieces/Helpers.h"

ChessBoard::ChessBoard() {
  // Constructor
}

void ChessBoard::printBoard() {
  // Reversed to get standardized ranks order
  for (int j = 7; j >= 0; j--) {
    std::cout << j + 1 << " ";
    for (int i = 0; i < std::size(gameBoard); i++) {
      std::cout << "[" << gameBoard[j][i]->getNotationName() << "]";
    }
    std::cout << std::endl;
  }
  std::cout << "   ";
  for (int i = 0; i < std::size(gameBoard); i++) {
    std::cout << char('a' + i) << "  ";
  }
  std::cout << std::endl;
}

void ChessBoard::loadFenBoard(const std::string &fenString) {
  int x = 0, y = 0;
  for (char c : fenString) {
    if (isalpha(c)) {
      this->gameBoard[y][x] = buildChessPiece(c);
      x += 1;
    } else if (isdigit(c)) {
      int digit = c - '0';
      for (int i = 0; i < digit; i++) {
        // This is safe because we only switch row at '/'
        this->gameBoard[y][x] = buildChessPiece('.');
        x += 1;
      }
    } else if (c == '/') {
      y += 1;
      x = 0;
    } else {
      // Handle other cases (if any)
      std::cout << "Unknown Character ";
    }
  }
}
std::pair<int, int> ChessBoard::getPositionFromNotation(
    const std::string &notation) {
  if (!isValidNotation(notation)) {
    return {-1, -1};
  }
  // Convert the letter (a-h) to x coordinate (0-7) and the number (1-8) to y
  // coordinate (0-7)
  int x = notation[0] - 'a';
  int y = 8 - (notation[1] - '0');

  return {x, y};
}

bool ChessBoard::makeMove(const std::string &from, const std::string &to) {
  std::pair<int, int> moveFrom = getPositionFromNotation(from);
  std::pair<int, int> moveTo = getPositionFromNotation(to);
  // std::cout << "move FROM " << (std::string)moveFrom << "which was og " <<
  // from << std::endl;
  printf("notation from was %s which becomes index [%d %d]", from.c_str(),
         moveFrom.first, moveFrom.second);
  //  printf("move FROM %d which was og %d\n", moveFrom.first, moveFrom.second);

  return true;
}

std::unique_ptr<ChessPiece> ChessBoard::buildChessPiece(char letter) {
  Color pieceColor = Color::White;
  if (islower(letter)) {
    pieceColor = Color::Black;
  }
  char lowerCaseLetter = std::tolower(letter);

  switch (lowerCaseLetter) {
    case 'r':
      return std::make_unique<Rook>(pieceColor);
    case 'n':
      return std::make_unique<Knight>(pieceColor);
    case 'b':
      return std::make_unique<Bishop>(pieceColor);
    case 'q':
      return std::make_unique<Queen>(pieceColor);
    case 'k':
      return std::make_unique<King>(pieceColor);
    case 'p':
      return std::make_unique<Pawn>(pieceColor);
    case '.':
      return std::make_unique<Empty>(pieceColor);
  }
  throw std::invalid_argument("Invalid input character: " +
                              std::string(1, letter));
}
