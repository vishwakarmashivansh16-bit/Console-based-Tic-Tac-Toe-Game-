/*
------------------------------------------------------------
|   Project Title : Console-based Tic Tac Toe Game          |
|   Author        : SHIVANSH VISHWAKARMA                    |
|   Language      : C++                                     |
|   Date Created  : November 2025                           |
|-----------------------------------------------------------|
|   Description:                                            |
|   This is a simple 2-player Tic Tac Toe game made using   |
|   only the 'main()' function in C++. The game is played   |
|   in the console where players take turns marking slots   |
|   on a 3x3 board using 'X' and 'O'.                       |
|                                                           |
|   Features:                                               |
|   - Fully interactive turn-based gameplay                 |
|   - Input validation for correct slot numbers             |
|   - Detects and announces the winner or a draw            |
|   - Simple ASCII-based board display                      |
|-----------------------------------------------------------|
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int slot;                    // Stores the slot number entered by the player
    int currentplayer = 1;       // Player 1 starts first
    char currentmark;            // Stores the current mark ('X' or 'O')
    int winner = 0;              // 0 means no winner yet

    // Initialize the 3x3 board with numbers 1–9
    char board[3][3] = { {'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'} };

    // Display the game title and instructions
    cout << "====== TIC TAC TOE ======\n";
    cout<<endl;
    cout << "Player 1 = 'X'   Player 2 = 'O'\n";
    cout<<endl;
    cout << "=============================================\n";

    // There can be a maximum of 9 turns in a Tic Tac Toe game
    for (int turn = 0; turn < 9; turn++) {
        // Display the board
        cout << "\n-------------\n";
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " | ";
            }
            cout << "\n-------------\n";
        }

        // Ask the current player for their move
        cout << "Player " << currentplayer << " Mark Your Chance (1-9): ";
        cin >> slot;

        // Input validation: check if the slot is between 1 and 9
        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            turn--;
            continue;
        }

        // Convert slot number to board row and column
        int row = (slot - 1) / 3;
        int col = (slot - 1) % 3;

        // Check if the chosen slot is already taken
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Slot already taken! Try again.\n";
            turn--;
            continue;
        }

        // Assign 'X' or 'O' mark based on the current player
        if (currentplayer == 1)
            currentmark = 'X';
        else
            currentmark = 'O';

        // Update the board
        board[row][col] = currentmark;

        // Check all possible winning conditions
        for (int i = 0; i < 3; i++) {
            // Check rows
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                winner = currentplayer;
            // Check columns
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                winner = currentplayer;
        }

        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            winner = currentplayer;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            winner = currentplayer;

        // If a player wins, display the final board and winner message
        if (winner != 0) {
            cout << "\n-------------\n";
            for (int i = 0; i < 3; i++) {
                cout << "| ";
                for (int j = 0; j < 3; j++) {
                    cout << board[i][j] << " | ";
                }
                cout << "\n-------------\n";
            }
            cout << "🎉 Player " << winner << " wins! 🎉\n";
            break;
        }

        // Switch player for the next turn
        if (currentplayer == 1)
            currentplayer = 2;
        else
            currentplayer = 1;
    }

    // If no one wins after all 9 turns, it's a draw
    if (winner == 0)
        cout << "It's a draw! 😐\n";

    cout << "===========================\n";
    return 0;
}
