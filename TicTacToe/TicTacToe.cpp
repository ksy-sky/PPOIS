#include "TicTacToe.h"
#include <algorithm> 

TicTacToe::TicTacToe(int size) : size(size) {
    board.resize(size, std::vector<char>(size, ' '));
}

TicTacToe::TicTacToe(const TicTacToe& other) {
    copyBoard(other);
}

TicTacToe& TicTacToe::operator=(const TicTacToe& other) {
    if (this != &other) {
        copyBoard(other);
    }
    return *this;
}

TicTacToe::~TicTacToe() {}

void TicTacToe::copyBoard(const TicTacToe& other) {
    size = other.size;
    board = other.board;
}

bool TicTacToe::isValidMove(int x, int y) const {
    return x >= 0 && x < size && y >= 0 && y < size && board[x][y] == ' ';
}

void TicTacToe::setMove(int x, int y, char player) {
    if (gameWon) {
        throw std::invalid_argument("Game already won");
    }
    
    if (isValidMove(x, y)) {
        board[x][y] = player;
        if (checkWin(player)) {
            gameWon = true;
        }
    } else {
        throw std::invalid_argument("Invalid move");
    }
}
char TicTacToe::getValue(int x, int y) const {
    return board[x][y];
}

bool TicTacToe::checkWin(char player) const {
    for (int i = 0; i < size; ++i) {
        if (std::all_of(board[i].begin(), board[i].end(), [player](char c) { return c == player; })) return true;
        if (std::all_of(board.begin(), board.end(), [i, player](const std::vector<char>& row) { return row[i] == player; })) return true;
    }

    bool diag1 = true, diag2 = true;
    for (int i = 0; i < size; ++i) {
        diag1 &= (board[i][i] == player);
        diag2 &= (board[i][size - 1 - i] == player);
    }
    return diag1 || diag2;
}

char& TicTacToe::operator[](std::pair<int, int> pos) {
    return board[pos.first][pos.second];
}

const char& TicTacToe::operator[](std::pair<int, int> pos) const {
    return board[pos.first][pos.second];
}

std::ostream& operator<<(std::ostream& os, const TicTacToe& game) {
    for (const auto& row : game.board) {
        for (char cell : row) {
            os << cell << " | ";
        }
        os << "\n" << std::string(game.size * 4 - 1, '-') << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, TicTacToe& game) {
    for (int i = 0; i < game.size; ++i) {
        for (int j = 0; j < game.size; ++j) {
            is >> game.board[i][j];
        }
    }
    return is;
}
bool TicTacToe::operator==(const TicTacToe& other) const {
    return board == other.board && size == other.size && gameWon == other.gameWon;
}

bool TicTacToe::operator!=(const TicTacToe& other) const {
    return !(*this == other);
}
