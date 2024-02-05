#include <utility>
enum class Color { White, Black };

enum class MoveType { Normal, Capture, Castling, Promotion, EnPassant };

class Move {
 public:
  Move(std::pair<int, int> from, std::pair<int, int> to,
       MoveType type = MoveType::Normal, char promotion = '\0')
      : from_(from), to_(to), type_(type), promotion_(promotion) {}

  // Getters for move details
  std::pair<int, int> from() const { return from_; }
  std::pair<int, int> to() const { return to_; }
  MoveType type() const { return type_; }
  char promotion() const { return promotion_; }

 private:
  std::pair<int, int> from_, to_;
  MoveType type_;
  char promotion_;  // For pawn promotions, stores the promoted piece type
};
