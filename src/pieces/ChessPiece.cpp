#include "ChessPiece.h"

#include <cctype>

ChessPiece::ChessPiece(Color color) : color_(color) {}

// placeholder
std::vector<Move> ChessPiece::generateMoves(std::pair<int, int> position) {
  return {Move(position, std::pair<int, int>(5, 5), MoveType::Normal)};
}

// Implementation of the getNotationName method
char ChessPiece::getNotationName() const {
  if (this->color_ == Color::White) {
    return std::tolower(symbol());
  }
  return std::toupper(symbol());
}

// Helps with creating moves
void ChessPiece::addMove(std::vector<Move>& moves, std::pair<int, int> position,
                         int dx, int dy) const {
  moves.push_back(Move(position, {position.first + dx, position.second + dy},
                       MoveType::Normal));
}
