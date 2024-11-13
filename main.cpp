#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 

void createBoard(char board[3][3])
{ 
	cout << "\n—————————————\n"; 
	for (int i = 0; i < 3; i++)
    { 
		cout << "❚ "; 
		for (int j = 0; j < 3; j++)
        { 
			cout << board[i][j] << " ❚ "; 
		} 
		cout << "\n—————————————\n"; 
	} 
}

bool checkWin(char board[3][3], char player) 
{ 
	for (int i = 0; i < 3; i++)
    { 
		if ((board[i][0] == player) && (board[i][1] == player) 
			&& (board[i][2] == player))
        {
            return true;
        }

		if ((board[0][i] == player) && (board[1][i] == player)
			&& (board[2][i] == player))
        {
            return true;
        }
	} 

	if ((board[0][0] == player) && (board[1][1] == player) 
		&& (board[2][2] == player))
        {
            return true;
        }

	if ((board[0][2] == player) && (board[1][1] == player 
		&& board[2][0] == player))
    {
        return true;
    }
	return false; 
} 

int main(void) 
{ 
    cout << "Welcome to the game!\nPlease input the character for player 1:\n";
    string playerOne;
    cin >> playerOne;
    if (playerOne.length() != 1)
    {
        while (true)
        {
            cout << "ERROR: Invalid length.\nPlease input the character for player 1:\n";
            cin >> playerOne;
            if (playerOne.length() == 1)
            {
                break;
            }
        }
    }
    
    
    cout << "Please input the character for player 2:\n";
    string playerTwo;
    cin >> playerTwo;
    if ((playerTwo.length() != 1) || (playerTwo == playerOne))
    {
        while (true)
        {
            if (playerTwo.length() != 1)
            {
                cout << "ERROR: Invalid length.\nPlease input the character for player 2:\n";
            } else if (playerTwo == playerOne)
            {
                cout << "ERROR: Marker is identical to player 1.\nPlease input the character for player 2:\n";
            }
            
            cin >> playerTwo;
            if ((playerTwo.length() == 1) && (playerTwo != playerOne))
            {
                break;
            }
        }
    }

    string repeat = "y";
    while ((repeat == "Y") || (repeat == "y"))
    {
        char board[3][3] = { { ' ', ' ', ' ' }, 
                            { ' ', ' ', ' ' }, 
                            { ' ', ' ', ' ' } }; 
        char player = playerOne[0]; 
        int row, col; 
        int turn;
    
        for (turn = 0; turn < 9; turn++)
        { 
            createBoard(board); 

            while (true)
            { 
                cout << "Player " << player << ", enter a row (0-2) and column (0-2) to play:\n"; 

                while (!(cin >> row))
                {
                    cout << "ERROR: Invalid move. Try again.\nPlayer " << player << ", enter a row (0-2) and column (0-2) to play:\n"; 
                    cin.clear();
                    cin.ignore(40, '\n');
                    
                }

                while (!(cin >> col))
                {
                    cout << "ERROR: Invalid move. Try again.\nPlayer " << player << ", enter row (0-2) and column (0-2):\n"; 
                    cin.clear();
                    cin.ignore(40, '\n');
                }

                if (((row < 0) || (row > 2) || (col < 0) || (col > 2)))
                {
                    cout << "ERROR: Invalid move. Try again.\n";
                } else if (board[row][col] != ' ')
                { 
                    cout <<  "This space is already filled. Try again.\n";
                } else { 
                    break;
                } 
            } 

            board[row][col] = player; 

            if (checkWin(board, player))
            { 
                createBoard(board); 
                cout << "Player " << player << " wins!"; 
                break; 
            } 

            player = (player == playerOne[0]) ? playerTwo[0] : playerOne[0]; 
        } 

        createBoard(board); 

        if (turn == 9 && !checkWin(board, playerOne[0]) && (!checkWin(board, playerTwo[0])))
        { 
            cout << "It's a draw!\n"; 
        } 

        cout << "Do you want to play again? (Y/N)\n";

        while ((!(cin >> repeat)) || ((repeat != "Y") && (repeat != "N") && (repeat != "y") && (repeat != "n")))
        {
            cout << "ERROR: Invalid response.\nDo you want to play again? (Y/N)\n";
            cin.clear();
            cin.ignore(40, '\n');
        }

        if ((repeat == "Y") || (repeat == "y"))
        {
            cout << "Starting new game:\n";
        } else if ((repeat == "N") || (repeat == "n")) {
            cout << "So long!\n";
            break;
        }
    }
}
