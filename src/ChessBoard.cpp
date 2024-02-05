#include "ChessBoard.h"

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

void ChessBoard::loadFenBoard(std::string fenString) {
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
