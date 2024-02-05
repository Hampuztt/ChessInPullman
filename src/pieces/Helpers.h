#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <utility>

enum class Color { White, Black };

enum class MoveType { Normal, Capture, Castling, Promotion, EnPassant };

class Move {
 public:
  Move(std::pair<int, int> from, std::pair<int, int> to,
       MoveType type = MoveType::Normal, char promotion = '\0');

  std::pair<int, int> from() const;
  std::pair<int, int> to() const;
  MoveType type() const;
  char promotion() const;

 private:
  std::pair<int, int> from_, to_;
  MoveType type_;
  char promotion_;  // For pawn promotions, stores the promoted piece type
};

bool isValidNotation(const std::string& notation);

#endif  // HELPER_H
