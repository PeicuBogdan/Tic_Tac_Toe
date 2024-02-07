#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void pBoard();
void rBoard();
int checkSpaces();
void playerMove();
void computerMove();
char checkWinner();
void pWinner(char);

int main()
{
    char winner = ' ';
   
    rBoard();
    do{
        pBoard();

        playerMove();

        winner = checkWinner();

        if (checkSpaces() == 0 || winner != ' ')
        {
            break;
        }
                
        computerMove();

        winner = checkWinner();

        if (checkSpaces() == 0 || checkWinner() != ' ')
        {
            break;
        }

    }while( winner == ' ' && checkSpaces() != 0);

    pBoard();

    pWinner(winner);



    
    return 0;
}

void pBoard()
{
    printf("\n %c | %c | %c ", board[0][0] , board[0][1] , board[0][2]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c ", board[1][0] , board[1][1] , board[1][2]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c ", board[2][0] , board[2][1] , board[2][2]);
}

void rBoard()
{
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            board[i][j] = ' ' ;
        }
    }
}

int checkSpaces()
{
    
    int spaces=9;

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            if(board[i][j] != ' ')
            {
                spaces--;
            }
        }
    }

    return spaces;
}

void playerMove()
{
    int x, y;
    do{
    printf("\nChoose where you want to place 'row' (0-2)");
    scanf("%d", &x);
    printf("\nChoose where you want to place 'coloumn' (0-2)");
    scanf("%d", &y);
    if(board[x][y] != ' ')
        {
            printf("\nSpace allready ocupied");
        }else{
            board[x][y] = PLAYER;
            break;
        }
    }while(board[x][y] != ' ');
}

void computerMove()
{
    int x,y;
    if(checkSpaces > 0){
        do{
            x = rand() % 3;
            y = rand() % 3;

            if(board[x][y] == ' ')
            {
                board[x][y] = COMPUTER;
                break;
            }
        }while(board[x][y] != ' ');
    }

}

char checkWinner()
{
    for(int i = 0 ; i <= 2 ; i++)
    {
        
        //rows
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }else

        //coloumns
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }else

        //diagonals
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
            return board[0][0];
        }else{
            return ' ';
        }
    }
}

void pWinner(char winner)
{
    if (winner != ' ' && winner == 'O') {
        printf("\nThe winner is O. You lose :(((");
        printf("\nThank you for playing!");
    } else if (winner != ' ' && winner == 'X') {
        printf("\nThe winner is X. You win :))))");
        printf("\nThank you for playing!");
    } else {
        printf("\nDRAW!"); 
    }
}
    
