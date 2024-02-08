#include "ChessBoard.h"

#include <iostream>

#include "pieces/ChessPiece.h"

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

ChessPiece *ChessBoard::getPiece(std::pair<int, int> position) {
  return gameBoard[position.second][position.first].get();
}
// Filters moves that are outside board & that would self capture
void ChessBoard::filterInvalidMoves(std::vector<Move> &moves) {
  std::vector<Move> validMoves;

  for (const auto &move : moves) {
    bool validPositions =
        isValidPosition(move.from()) && isValidPosition(move.to());

    bool notSamecolor =
        getPiece(move.from())->color_ != getPiece(move.to())->color_;

    if (validPositions &&
        (notSamecolor or move.type() == MoveCondition::Castling)) {
      validMoves.push_back(move);
    }
  }
  moves = validMoves;
}

bool ChessBoard::isPawnCapture(Move move) {
  ChessPiece *toPiece = getPiece(move.to());
  return toPiece->symbol() != '.';
}

std::vector<Move> ChessBoard::getLegalPieceMoves(ChessPiece *piece,
                                                 std::pair<int, int> position) {
  std::vector<Move> possibleMoves = piece->generateMoves(position);
  filterInvalidMoves(possibleMoves);

  std::vector<Move> legalMoves = {};

  // We can now assume our moves won't make program crash
  for (auto &move : possibleMoves) {
    switch (move.type()) {
      case MoveCondition::None:
        legalMoves.push_back(move);
      case MoveCondition::PawnCapture:
        if (isPawnCapture(move)) {
          legalMoves.push_back(move);
        }
        legalMoves.push_back(move);
      case MoveCondition::Castling:
      case MoveCondition::Promotion:
      case MoveCondition::EnPassant:
        break;
    };
  }

  for (auto &move : legalMoves) {
    std::cout << "Legal Move: From (" << move.from().first << ", "
              << move.from().second << ") To (" << move.to().first << ", "
              << move.to().second << ")\n";
  }
  return legalMoves;
}

bool ChessBoard::makeMove(const std::string &from, const std::string &to) {
  std::pair<int, int> moveFrom = getPositionFromNotation(from);
  std::pair<int, int> moveTo = getPositionFromNotation(to);
  if ((moveTo.first == -1 && moveTo.second == -1) ||
      (moveFrom.first == -1 && moveFrom.second == -1)) {
    return false;
  }
  // std::cout << "move FROM " << (std::string)moveFrom << "which was og " <<
  // from << std::endl;
  auto &chosen_piece_ptr = gameBoard[moveFrom.second][moveFrom.first];
  auto &target_piece_ptr = gameBoard[moveTo.second][moveTo.first];

  // Prevent moving onto a piece of the same color
  if (chosen_piece_ptr->color_ == target_piece_ptr->color_ or
      chosen_piece_ptr->symbol() == '.') {
    return false;
  }

  getLegalPieceMoves(chosen_piece_ptr.get(), moveFrom);

  target_piece_ptr = std::move(chosen_piece_ptr);

  chosen_piece_ptr = std::make_unique<Empty>(Color::None);

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
      return std::make_unique<Empty>(Color::None);
  }
  throw std::invalid_argument("Invalid input character: " +
                              std::string(1, letter));
}
