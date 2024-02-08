
#include "Helpers.h"

Move::Move(std::pair<int, int> from, std::pair<int, int> to, MoveCondition type,
           char promotion)
    : from_(from), to_(to), type_(type), promotion_(promotion) {}

std::pair<int, int> Move::from() const { return from_; }

std::pair<int, int> Move::to() const { return to_; }

MoveCondition Move::type() const { return type_; }

char Move::promotion() const { return promotion_; }

bool isValidNotation(const std::string& notation) {
  if (notation.length() != 2) {
    std::cout << "Notation length != 2 " << notation << std::endl;
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

std::pair<int, int> getPositionFromNotation(const std::string& notation) {
  if (!isValidNotation(notation)) {
    printf("Invalid move notation! %s", notation.c_str());
    return {-1, -1};
  }
  // Convert the letter (a-h) to x coordinate (0-7) and the number (1-8) to y
  // coordinate (0-7)
  int offset = 1;
  int x = notation[0] - 'a';
  int y = notation[1] - '0' - offset;
  return {x, y};
}

std::string getNotationFromPosition(const std::pair<int, int>& position) {
  // Convert x coordinate (0-7) to letter (a-h) and y coordinate (0-7) to number
  if (position.first < 0 || position.first > 7 || position.second < 0 ||
      position.second > 7) {
    // Return an indication of an invalid position
    return "Invalid";
  }  // (1-8)
  char column = static_cast<char>('a' + position.first);
  int row = position.second + 1;  // Adjusting 0-7 range to 1-8
  return std::string(1, column) + std::to_string(row);
}

bool isValidPosition(const std::pair<int, int> position) {
  return (position.first >= 0 && position.first < 8 && position.second >= 0 &&
          position.second < 8);
};
