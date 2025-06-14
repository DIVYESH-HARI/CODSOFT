#include <iostream>
using namespace std;

char board[3][3];  // 3x3 Game Board
char currentPlayer;  // 'X' or 'O'

// Initialize the board with numbers 1–9
void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
    currentPlayer = 'X'; // X always starts
}

// Display the game board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Switch between players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Check if the current player wins
bool checkWin() {
    // Rows and Columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Diagonals
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

// Check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Handle player move
void makeMove() {
    int choice;
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // clear error
            cin.ignore(10000, '\n'); // discard input
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice < 1 || choice > 9) {
            cout << "Invalid move. Choose a number between 1 and 9.\n";
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "That spot is already taken. Try another.\n";
        } else {
            board[row][col] = currentPlayer;
            break;
        }
    }
}

int main() {
    char playAgain;

    do {
        resetBoard();
        bool gameWon = false;

        cout << "Welcome to Tic-Tac-Toe!\n";

        while (true) {
            displayBoard();
            makeMove();

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins! 🎉\n";
                gameWon = true;
                break;
            }

            if (checkDraw()) {
                displayBoard();
                cout << "It's a draw! 🤝\n";
                break;
            }

            switchPlayer();
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        cout << "\n";

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
