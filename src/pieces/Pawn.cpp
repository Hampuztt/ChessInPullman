#include "Pawn.h"

Pawn::Pawn(Color color) : ChessPiece(color) {}
char Pawn::symbol() const { return 'P'; }
std::vector<Move> Pawn::generateMoves(std::pair<int, int> position) {
  std::vector<Move> result = {};
  int direction = (color_ == Color::White) ? 1 : -1;
  int startRow = (color_ == Color::White) ? 1 : 6;

  addMove(result, position, 0, 1 * direction);

  bool pawnInStartPosition = position.second == 1 or position.second == 6;
  if (position.second == startRow) {
    addMove(result, position, 0, 2 * direction);
  }
  return result;
};
