// Крестики-нолики
#include <stdio.h>
#include <stdlib.h>

const int n=3;

void drawField(int field[n][n]);
int endGame(int field[n][n]);
void nextTurn(int field[n][n],int crossFlag);

int main()
{
    int field[3][3]= {0},crossFlag=0;
    drawField(field);
    while (endGame(field)==0)
    {
        nextTurn(field, crossFlag);
        ++crossFlag;
    }
    return 0;
}

void drawField(int field[n][n])
{
    char symbols[3]= {' ','X','O'};
    printf(" A-B-C\n");
    for (int i=0; i<2*n-1; ++i)
    {
        if (i%2==0)
            printf("%d",1+i/2);
        else
            printf("|");
        for (int j=0; j<2*n-1; ++j)
        {
            if (i%2==0 && j%2==0)
                printf("%c",symbols[field[j/2][i/2]]);
            else
                printf("#");
        }
        printf("\n");
    }
}

int endGame(int field[n][n])
{
    for(int i=0; i<n; ++i)
        if (field[i][0]==field[i][1] && field[i][1]==field[i][2] && field[i][2]!=0)
            return 1; // игра завершена
    for(int i=0; i<n; ++i)
        if (field[0][i]==field[1][i] && field[1][i]==field[2][i]&& field[2][i]!=0)
            return 1; // игра завершена
    if (field[0][0]==field[1][1] && field[1][1]==field[2][2] && field[2][2]!=0)
        return 1; // игра завершена
    if (field[0][2]==field[1][1] && field[1][1]==field[2][0] && field[2][0]!=0)
        return 1; // игра завершена
    int s=0;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (field[i][j]==0)
                ++s;
    if (s==0)
        return 2; // ничя
    else
        return 0; //продолжение игры
}

void nextTurn(int field[n][n],int crossFlag)
{
    if (crossFlag%2==0)
        printf("\nX turn\nEnter X Y (sample '1 2' or '3 1'):\n");
    else
        printf("\nO turn\nEnter X Y (sample '1 2' or '3 1'):\n");
    int x,y;
    do
    {
        scanf("%d%d",&x,&y);
        if (field[x-1][y-1]!=0)
            printf("\nIncorrect move. Please repeat again.\nEnter X Y (sample '1 2' or '3 1'):\n");
    }
    while (field[x-1][y-1]!=0);
    system("cls");
    if (crossFlag%2==0)
        field[x-1][y-1]=1;
    else
        field[x-1][y-1]=2;
    drawField(field);
    if (endGame(field)==1 && crossFlag%2==0)
        printf("\nX Win!\n");
    if (endGame(field)==1 && crossFlag%2!=0)
        printf("\nO Win!\n");
    if (endGame(field)==2)
        printf("\nDraw!\n");
}
