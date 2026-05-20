#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * Tic Tac Toe - Console Game (C++)
 *
 * Modes:
 *   1. Player vs Player
 *   2. Player vs Computer (random moves)
 *
 * Board positions:
 *   1 | 2 | 3
 *   4 | 5 | 6
 *   7 | 8 | 9
 *
 * @author Anubhav Srivastava
 */

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Display the current board
void display() {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i];
        if (i == 2 || i == 5 || i == 8)
            cout << "\n";
        else
            cout << " |";
    }
    cout << "\n";
}

// Reset the board for a new game
void resetBoard() {
    for (int i = 0; i < 9; i++)
        board[i] = '1' + i;
}

// Mark a position with X or O
void mark(int pos, char symbol) {
    board[pos - 1] = symbol;
}

// Check if a position is already taken
bool isTaken(int pos) {
    return board[pos - 1] == 'X' || board[pos - 1] == 'O';
}

/**
 * Returns:
 *   'X' if X wins
 *   'O' if O wins
 *   'D' if draw
 *   ' ' if game still going
 */
char checkWin() {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == board[i+1] && board[i+1] == board[i+2])
            return board[i];
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i+3] && board[i+3] == board[i+6])
            return board[i];
    }
    // Check diagonals
    if (board[0] == board[4] && board[4] == board[8]) return board[0];
    if (board[2] == board[4] && board[4] == board[6]) return board[2];

    // Check for draw (no empty squares left)
    bool draw = true;
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            draw = false;
            break;
        }
    }
    if (draw) return 'D';

    return ' '; // Game still in progress
}

// Get a valid move from a human player
int getPlayerMove(string playerName) {
    int pos;
    cout << playerName << ", enter position (1-9): ";
    cin >> pos;
    while (pos < 1 || pos > 9 || isTaken(pos)) {
        if (pos < 1 || pos > 9)
            cout << "Invalid position. Enter a number between 1 and 9: ";
        else
            cout << "Position already taken. Choose another: ";
        cin >> pos;
    }
    return pos;
}

// Get a random valid move for the computer
int getComputerMove() {
    int pos;
    do {
        pos = rand() % 9 + 1;
    } while (isTaken(pos));
    return pos;
}

// Player vs Player mode
void playerVsPlayer() {
    resetBoard();
    display();
    char result = ' ';

    while (result == ' ') {
        // Player 1 (X)
        int pos1 = getPlayerMove("Player 1 (X)");
        mark(pos1, 'X');
        display();
        result = checkWin();
        if (result != ' ') break;

        // Player 2 (O)
        int pos2 = getPlayerMove("Player 2 (O)");
        mark(pos2, 'O');
        display();
        result = checkWin();
    }

    if (result == 'X')      cout << "🎉 Congratulations! Player 1 (X) wins!\n";
    else if (result == 'O') cout << "🎉 Congratulations! Player 2 (O) wins!\n";
    else                    cout << "🤝 It's a draw!\n";
}

// Player vs Computer mode
void playerVsComputer() {
    resetBoard();
    display();
    char result = ' ';

    while (result == ' ') {
        // Player (X)
        int pos1 = getPlayerMove("Player (X)");
        mark(pos1, 'X');
        display();
        result = checkWin();
        if (result != ' ') break;

        // Computer (O)
        cout << "Computer (O) is thinking...\n";
        int pos2 = getComputerMove();
        cout << "Computer chose position " << pos2 << "\n";
        mark(pos2, 'O');
        display();
        result = checkWin();
    }

    if (result == 'X')      cout << "🎉 Congratulations! You (X) win!\n";
    else if (result == 'O') cout << "💻 Computer (O) wins! Better luck next time.\n";
    else                    cout << "🤝 It's a draw!\n";
}

int main() {
    srand(time(0)); // Seed random number generator

    cout << "==========================\n";
    cout << "   Welcome to Tic Tac Toe  \n";
    cout << "==========================\n";

    while (true) {
        cout << "\nMain Menu:\n";
        cout << "  1. Player vs Player\n";
        cout << "  2. Player vs Computer\n";
        cout << "  3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                playerVsPlayer();
                break;
            case 2:
                playerVsComputer();
                break;
            case 3:
                cout << "Thanks for playing! Goodbye! 👋\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }

    return 0;
}
