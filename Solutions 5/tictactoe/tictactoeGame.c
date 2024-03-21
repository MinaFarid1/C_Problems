#include <stdio.h>
#include <stdlib.h>
#define rows 3
#define cols 3
void displayBoard(char board[rows][cols]){
    for (int j = 0; j < cols; j++) 
            printf("---");
        printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(j == 0)
                printf("| %c ", board[i][j]);
            else 
                printf("%c ", board[i][j]);
            if(j == (cols - 1))
                printf("|");
        }
        printf("\n");
    }
    for (int j = 0; j < cols; j++) 
            printf("---");
        printf("\n");
    
};
int updateBoard(char input, int position, char board[rows][cols]){
    int x, y;
    if(position <= rows*cols && position > 0){
        // Turn position into 2D array indices
        x = (position - 1)/cols; 
        y = (position - 1)%cols;
        if(board[x][y] != 'X' && board[x][y] != 'O')
            board[x][y] = input;
        else
            return 1; // Already X or O in position, return error
    }
    else
        return 1; // Position out of index, return error
    return 0;
};
void inputXO(char input, char board[rows][cols]){
    int position;
    printf("%c's turn\n",input);
    displayBoard(board);
    printf("Enter position 1-9: ");
    if(!scanf("%d", &position)){ // Check for non integer value
        printf("Invalid position\n");
        while (getchar() != '\n');// Clear input buffer
        inputXO(input, board);
        return;
    }
    if(updateBoard(input, position, board)){ // Update board and check for invalid position
        printf("Invalid position\n");
        inputXO(input, board);
    }
};
    char check_board_for_winner(char board[rows][cols]) {
    // Check rows and columns for a win for both 'X' and 'O'
    for (int i = 0; i < rows; i++) {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') 
            return 'X';
        if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') 
            return 'O';
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') 
            return 'X';
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') 
            return 'O';
    }

    // Check diagonals for a win for both 'X' and 'O'
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') 
        return 'X';
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') 
        return 'O';
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') 
        return 'X';
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') 
        return 'O';

    return 255; // No winner found
}

int checkDraw(char board[rows][cols]) {
    // Check if any cell is still empty
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0; 
        }
    }
    // All cells are filled but no player has won
    return 1; // It's a draw
}
void resetBoard(char board[rows][cols]) {
    char initBoard[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
    };
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = initBoard[i][j];
        }
    }
}
int main(){
    char xoBoard[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
    };
    int alternate = 1;
    char input = 'X';
    char winner;
    while(1){
        // Check for winner
        winner = check_board_for_winner(xoBoard);
        if (winner == 'X' || winner == 'O') {
            displayBoard(xoBoard);
            printf("Player %c wins!\n", winner);
            break;
        }
        if(checkDraw(xoBoard)){
            displayBoard(xoBoard);
            printf("It is a draw.\n");
            resetBoard(xoBoard);
        }
        // Alternate between X and O turns
        if(alternate){
            input = 'X';
            inputXO(input, xoBoard);
        }
        else{
            input= 'O';
            inputXO(input, xoBoard);
        }
        alternate = !alternate;
        
    };
    return 0;
};

