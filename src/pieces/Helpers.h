#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include <ostream>
#include <string>
#include <utility>

enum class Color { White, Black, None };
enum class MoveCondition { None, PawnCapture, Castling, Promotion, EnPassant };

class Move {
 public:
  Move(std::pair<int, int> from, std::pair<int, int> to,
       MoveCondition type = MoveCondition::None, char promotion = '\0');

  std::pair<int, int> from() const;
  std::pair<int, int> to() const;
  MoveCondition type() const;
  char promotion() const;

 private:
  std::pair<int, int> from_, to_;
  MoveCondition type_;
  char promotion_;  // For pawn promotions, stores the promoted piece type
};

bool isValidNotation(const std::string& notation);
bool isValidPosition(const std::pair<int, int> position);
std::pair<int, int> getPositionFromNotation(const std::string& notation);

#endif  // HELPER_H
