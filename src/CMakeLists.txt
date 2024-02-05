
# Add executable target with source files
add_executable(ChessMain main.cpp ChessBoard.cpp pieces/ChessPiece.cpp pieces/Rook.cpp pieces/Knight.cpp pieces/Bishop.cpp pieces/Queen.cpp pieces/King.cpp pieces/Pawn.cpp pieces/Empty.cpp pieces/Helpers.cpp)


# Link any dependencies here, for example:
# target_link_libraries(ChessMain PUBLIC some_library)
