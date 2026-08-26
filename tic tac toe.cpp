#include <iostream>
using namespace std;

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char player = 'X';
    int choice, row, col;

    for (int turn = 0; turn < 9; turn++) {

        // Display board
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " " << board[i][0] << " | "
                 << board[i][1] << " | "
                 << board[i][2] << "\n";
            if (i < 2)
                cout << "---|---|---\n";
        }

        cout << "\nPlayer " << player << ", enter position (1-9): ";
        cin >> choice;

        // Convert position to row and column
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check valid move
        if (choice < 1 || choice > 9 ||
            board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move! Try again.\n";
            turn--;
            continue;
        }

        board[row][col] = player;

        // Check rows and columns
        bool win = false;

        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player &&
                board[i][1] == player &&
                board[i][2] == player)
                win = true;

            if (board[0][i] == player &&
                board[1][i] == player &&
                board[2][i] == player)
                win = true;
        }

        // Check diagonals
        if (board[0][0] == player &&
            board[1][1] == player &&
            board[2][2] == player)
            win = true;

        if (board[0][2] == player &&
            board[1][1] == player &&
            board[2][0] == player)
            win = true;

        if (win) {
            cout << "\nPlayer " << player << " wins! ??\n";
            break;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';

        if (turn == 8)
            cout << "\nGame Draw!\n";
    }

    return 0;
}
