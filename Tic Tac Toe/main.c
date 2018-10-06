#include <stdio.h>
#include <stdlib.h>

char x1 = ' ';
char x2 = ' ';
char x3 = ' ';
char x4 = ' ';
char x5 = ' ';
char x6 = ' ';
char x7 = ' ';
char x8 = ' ';
char x9 = ' ';
int TopRow;
int MidRow;
int BotRow;
int TopCol;
int MidCol;
int BotCol;
int Diag73;
int Diag19;
int Select;
int ScoreX;
int ScoreO;


int main(void)
{
    board();
    while(1)
    {
        printf("\n             Player X's turn \n");
        Player1Turn();
        board();
        winning();
        printf("\n             Player O's turn \n");
        Player2Turn();
        board();
        winning();
    }
}
void board()
{
    system("cls");
    printf(" Player X Score: %d  Player O Score: %d \n", ScoreX, ScoreO);
    printf("              %c ! %c ! %c \n",x7,x8,x9);
    printf("             ----------- \n");
    printf("              %c ! %c ! %c \n",x4,x5,x6);
    printf("             ----------- \n");
    printf("              %c ! %c ! %c \n",x1,x2,x3);
    return(0);
}
void winning()
{
    TopRow = (x7 +x8 +x9);
    MidRow = (x4 +x5 +x6);
    BotRow = (x1+x2+x3);
    TopCol = (x7+x4+x1);
    MidCol = (x8+x5+x2);
    BotCol = (x9+x6+x3);
    Diag73 = (x7+x5+x3);
    Diag19 = (x1+x5+x9);
    if (TopRow == 264 || MidRow == 264 || BotRow == 264 || TopCol == 264 || MidCol == 264 || BotCol == 264 || Diag73 == 264 || Diag19 == 264)
       {
            ScoreX += 1;
            board();
            printf("\n * * * * * X is the winner * * * * * \n");
            system("pause");
            ResetGame();
       }
    else if (TopRow == 237 || MidRow == 237 || BotRow == 237 || TopCol == 237 || MidCol == 237 || BotCol == 237 || Diag73 == 237 || Diag19 == 237)
       {
            ScoreO += 1;
            board();
            printf("\n * * * * * O is the winner * * * * * \n");
            system("pause");
            ResetGame();
       }
    else if (x1 != 32 && x2 != 32 && x3 != 32 && x4 != 32 && x5 != 32 && x6 != 32 && x7 != 32 && x8 != 32 && x9 != 32)
       {
            printf("\n * * * * * Draw * * * * * \n");
            system("pause");
            ResetGame();
       }
    else
       {
            return(0);
       }
}
void Player1Turn()
{
    scanf("%d", &Select);
    if (Select == 1 && x1 == ' ')
        {
            x1 = 'X';
        }
    else if (Select == 2 && x2 == ' ')
        {
            x2 = 'X';
        }
    else if (Select == 3 && x3 == ' ')
        {
            x3 = 'X';
        }
    else if (Select == 4 && x4 == ' ')
        {
            x4 = 'X';
        }
    else if (Select == 5 && x5 == ' ')
        {
            x5 = 'X';
        }
    else if (Select == 6 && x6 == ' ')
        {
            x6 = 'X';
        }
    else if (Select == 7 && x7 == ' ')
        {
            x7 = 'X';
        }
    else if (Select == 8 && x8 == ' ')
        {
            x8 = 'X';
        }
    else if (Select == 9 && x9 == ' ')
        {
            x9 = 'X';
        }
    else
        {
            printf("\n Pick Another \n");
            Player1Turn();
        }
    return(0);
}
void Player2Turn()
{
    scanf("%d", &Select);
    if (Select == 1 && x1 == ' ')
        {
            x1 = 'O';
        }
    else if (Select == 2 && x2 == ' ')
        {
            x2 = 'O';
        }
    else if (Select == 3 && x3 == ' ')
        {
            x3 = 'O';
        }
    else if (Select == 4 && x4 == ' ')
        {
            x4 = 'O';
        }
    else if (Select == 5 && x5 == ' ')
        {
            x5 = 'O';
        }
        else if (Select == 6 && x6 == ' ')
        {
            x6 = 'O';
        }
    else if (Select == 7 && x7 == ' ')
        {
            x7 = 'O';
        }
    else if (Select == 8 && x8 == ' ')
        {
            x8 = 'O';
        }
    else if (Select == 9 && x9 == ' ')
        {
            x9 = 'O';
        }
    else
        {
            printf("\n Pick Another \n");
            Player2Turn();
        }
    return(0);
}
void ResetGame()
{
    x1 = ' ';
    x2 = ' ';
    x3 = ' ';
    x4 = ' ';
    x5 = ' ';
    x6 = ' ';
    x7 = ' ';
    x8 = ' ';
    x9 = ' ';
    main();
}
