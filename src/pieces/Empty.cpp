#include "Empty.h"
Empty::Empty(Color color) : ChessPiece(color) {}
char Empty::symbol() const { return '.'; }
