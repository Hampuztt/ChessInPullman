#include "Rook.h"
Rook::Rook(Color color) : ChessPiece(color) {}
char Rook::symbol() const { return 'R'; }
std::vector<Move> Rook::generateMoves(std::pair<int, int> position) {
  return {};
};
