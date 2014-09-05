// Крестики-нолики на большом поле
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 20

const int winLength=5;

void drawField(int field[N][N]);
int endGame(int field[N][N]);
void nextTurn(int field[N][N],int crossFlag);
int checkLine(int field[N][N], int length, int i, int j, int vi, int vj);

int main()
{
    int field[N][N]= {0},crossFlag=0;
    drawField(field);
    while (endGame(field)==0)
    {
        nextTurn(field, crossFlag);
        ++crossFlag;
    }
    return 0;
}

void drawField(int field[N][N])
{
    char symbols[3]= {' ','X','O'};
    printf(" ");
    for (int i=1; i<=N; ++i)
    {
        int abscissa=i/10;
        if (abscissa!=0)
            printf(" %d",i/10);
        else
            printf("  ");
    }
    printf("\n");
    printf(" ");
    for (int i=1; i<=N; ++i)
        printf(" %d",i%10);
    printf("\n");
    for (int i=0; i<2*N-1; ++i)
    {
        if (i%2==0)
            printf("%2d",1+i/2);
        else
            printf("  ");
        for (int j=0; j<2*N-1; ++j)
        {
            if (i%2==0 && j%2==0)
                printf("%c",symbols[field[j/2][i/2]]);
            else
                printf("#");
        }
        printf("\n");
    }
}

int endGame(int field[N][N])
{
    int check;
    for (int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            check=checkLine(field,winLength,i,j,0,1);
            if (check)
                return check;
        }
    }
    for (int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            check=checkLine(field,winLength,i,j,1,1);
            if (check)
                return check;
        }
    }
    for (int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            check=checkLine(field,winLength,i,j,1,0);
            if (check)
                return check;
        }
    }
    for (int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            check=checkLine(field,winLength,i,j,-1,1);
            if (check)
                return check;
        }
    }
    int zeroCellsCounter=0;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if (field[i][j]==0)
                ++zeroCellsCounter;
        }
    }
    if (zeroCellsCounter==0)
        return 3; // ничя
    return 0; //продолжение игры
}

void nextTurn(int field[N][N],int crossFlag)
{
    if (crossFlag%2==0)
        printf("\nX turn\nEnter X Y (sample '1 2' or '3 1'):\n");
    else
        printf("\nO turn\nEnter X Y (sample '1 2' or '3 1'):\n");
    int x,y,z;
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
    switch (endGame(field))
    {
    case 1:
        printf("\nX Win!\n");
        break;
    case 2:
        printf("\nO Win!\n");
        break;
    case 3:
        printf("\nDraw!\n");
        break;
    }
}

int checkLine(int field[N][N], int length, int i, int j, int vi, int vj)
{
    int firstCell=field[i][j];
    if (firstCell==0)
        return 0;
    for (int t=0; t<length; ++t)
    {
        if (i+t*vi<0 || i+t*vi>=N || j+t*vj<0 || j+t*vj>=N || firstCell!=field[i+t*vi][j+t*vj])
            return 0;
    }
    return firstCell;
}
