/***************************************************************************
* Program: TicTacToe Game
***************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

// Constants for the game board
const int SIZE = 3;
const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

// Function to print the game board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
    }
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

// Function to check for a win condition
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Top-left to bottom-right diagonal win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Top-right to bottom-left diagonal win
    }
    return false;
}

int main() {
    vector<vector<char>> board(SIZE, vector<char>(SIZE, EMPTY));
    bool player1Turn = true;

    cout << "Welcome to Tic Tac Toe!\n";

    while (true) {
        cout << "Current board:\n";
        printBoard(board);

        char currentPlayer = (player1Turn) ? PLAYER1 : PLAYER2;
        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        
        int row, col;
        cin >> row >> col;
        row--; // Convert to 0-based indexing
        col--; // Convert to 0-based indexing
        
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = currentPlayer;
            if (checkWin(board, currentPlayer)) {
                cout << "Current board:\n";
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (isBoardFull(board)) {
                cout << "Current board:\n";
                printBoard(board);
                cout << "It's a tie!\n";
                break;
            }
            player1Turn = !player1Turn; // Switch players
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }

    return 0;
}
