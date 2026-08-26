#include <iostream>
using namespace std;

void display(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1]
             << " | " << board[i][2] << "\n";
        if (i < 2)
            cout << "---|---|---\n";
    }
    cout << "\n";
}

bool win(char board[3][3], char p) {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return true;

        if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
            return true;
    }

    // Diagonals
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return true;

    if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
        return true;

    return false;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char player = 'X';
    int row, col;

    for (int turn = 0; turn < 9; turn++) {
        display(board);

        cout << "Player " << player << ", enter row and column (1-3): ";
        cin >> row >> col;

        // Validate move
        if (row < 1 || row > 3 || col < 1 || col > 3 ||
            board[row - 1][col - 1] != ' ') {
            cout << "Invalid move! Try again.\n";
            turn--;
            continue;
        }

        board[row - 1][col - 1] = player;

        // Check winner
        if (win(board, player)) {
            display(board);
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        // Switch player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    display(board);
    cout << "It's a draw!\n";

    return 0;
}

