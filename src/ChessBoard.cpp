#include <algorithm>
#include <array>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>

enum class Color { White = 0, Black = 1 };

class ChessPiece {
 public:
  virtual ~ChessPiece() = default;
  virtual char symbol() const = 0;
  ChessPiece(Color color) : color_(color) {}  // Constructor to set the color_

  char getNotationName() const {
    if (this->color_ == Color::White) {
      return std::tolower(symbol());
    };
    return std::toupper(symbol());
  }

 private:
  Color color_;
};

class Pawn : public ChessPiece {
 public:
  Pawn(Color color) : ChessPiece(color) {}
  char symbol() const override { return 'P'; }
};

class Rook : public ChessPiece {
 public:
  Rook(Color color) : ChessPiece(color) {}
  char symbol() const override { return 'R'; }
};

class Knight : public ChessPiece {
 public:
  Knight(Color color) : ChessPiece(color) {}
  char symbol() const override { return 'N'; }
};

class Bishop : public ChessPiece {
 public:
  Bishop(Color color) : ChessPiece(color) {}
  char symbol() const override { return 'B'; }
};

class Queen : public ChessPiece {
 public:
  Queen(Color color) : ChessPiece(color) {}
  char symbol() const override { return 'Q'; }
};

class King : public ChessPiece {
 public:
  King(Color color) : ChessPiece(color) {}
  char symbol() const override { return 'K'; }
};

class Empty : public ChessPiece {
 public:
  Empty(Color color) : ChessPiece(color) {}
  char symbol() const override { return '.'; }
};

class ChessBoard {
 public:
  ChessBoard() = default;
  void setUpBoard() {
    for (int i = 0; i < std::size(gameBoard); i++) {
      for (int j = 0; j < std::size(gameBoard); j++) {
        gameBoard[i][j] = std::make_unique<King>(Color::White);
      }
    }
  }

  void printBoard() {
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

  void loadFenBoard(std::string fenString) {
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

 private:
  std::array<std::array<std::unique_ptr<ChessPiece>, 8>, 8> gameBoard;
  std::unique_ptr<ChessPiece> buildChessPiece(char letter) {
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
};
