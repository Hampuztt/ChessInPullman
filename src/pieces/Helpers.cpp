
#include "Helpers.h"

Move::Move(std::pair<int, int> from, std::pair<int, int> to, MoveType type,
           char promotion)
    : from_(from), to_(to), type_(type), promotion_(promotion) {}

std::pair<int, int> Move::from() const { return from_; }

std::pair<int, int> Move::to() const { return to_; }

MoveType Move::type() const { return type_; }

char Move::promotion() const { return promotion_; }

bool isValidNotation(const std::string& notation) {
  if (notation.length() != 2) {
    return false;
  }

  char letter = notation[0];
  if (letter < 'a' || letter > 'h') {
    return false;
  }

  char number = notation[1];
  if (number < '1' || number > '8') {
    return false;
  }

  return true;
}
