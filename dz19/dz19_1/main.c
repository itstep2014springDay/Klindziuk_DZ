// Трёхмерные крестики-нолики
#include <stdio.h>
#include <stdlib.h>

const int n=4,winLength=4;

void drawField(int field[n][n][n]);
int endGame(int field[n][n][n]);
void nextTurn(int field[n][n][n],int crossFlag);
int checkLine(int field[n][n][n], int length, int i, int j, int k, int vi, int vj, int vk);

int main()
{
    int field[4][4][4]= {0},crossFlag=0;
    drawField(field);
    while (endGame(field)==0)
    {
        nextTurn(field, crossFlag);
        ++crossFlag;
    }
    return 0;
}

void drawField(int field[n][n][n])
{
    char symbols[3]= {' ','X','O'};
    for (int k=0; k<n; ++k)
    {
        printf("\nFloor %d\n",k+1);
        printf(" A-B-C-D\n");
        for (int i=0; i<2*n-1; ++i)
        {
            if (i%2==0)
                printf("%d",1+i/2);
            else
                printf("|");
            for (int j=0; j<2*n-1; ++j)
            {
                if (i%2==0 && j%2==0)
                    printf("%c",symbols[field[j/2][i/2][k]]);
                else
                    printf("#");
            }
            printf("\n");
        }
    }
}

int endGame(int field[n][n][n])
{
    int check;
    for (int j=0; j<n; ++j)
    {
        for(int k=0; k<n; ++k)
        {
            check=checkLine(field,n,0,j,k,1,0,0);
            if (check)
                return check;
        }
    }
    for (int i=0; i<n; ++i)
    {
        for(int k=0; k<n; ++k)
        {
            check=checkLine(field,n,i,0,k,0,1,0);
            if (check)
                return check;
        }
    }
    for (int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            check=checkLine(field,n,i,j,0,0,0,1);
            if (check)
                return check;
        }
    }
    for(int j=0; j<n; ++j)
    {
        check=checkLine(field,n,0,j,0,1,0,1);
        if (check)
            return check;
    }
    for(int j=0; j<n; ++j)
    {
        check=checkLine(field,n,3,j,0,-1,0,1);
        if (check)
            return check;
    }
    for(int i=0; i<n; ++i)
    {
        check=checkLine(field,n,i,0,0,0,1,1);
        if (check)
            return check;
    }
    for(int i=0; i<n; ++i)
    {
        check=checkLine(field,n,i,3,0,0,-1,1);
        if (check)
            return check;
    }
    for(int k=0; k<n; ++k)
    {
        check=checkLine(field,n,0,0,k,1,1,0);
        if (check)
            return check;
    }
    for(int k=0; k<n; ++k)
    {
        check=checkLine(field,n,3,0,k,-1,1,0);
        if (check)
            return check;
    }
    check=checkLine(field,n,0,0,0,1,1,1);
    if (check)
        return check;
    check=checkLine(field,n,3,0,0,-1,1,1);
    if (check)
        return check;
    check=checkLine(field,n,3,3,0,-1,-1,1);
    if (check)
        return check;
    check=checkLine(field,n,0,3,0,1,-1,1);
    if (check)
        return check;
    int zeroCellsCounter=0;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            for(int k=0; k<n; ++k)
                if (field[i][j][k]==0)
                    ++zeroCellsCounter;
        }
    }
    if (zeroCellsCounter==0)
        return 3; // ничя
    return 0; //продолжение игры
}

void nextTurn(int field[n][n][n],int crossFlag)
{
    if (crossFlag%2==0)
        printf("\nX turn\nEnter X Y Z(sample '1 2 2' or '3 1 2'):\n");
    else
        printf("\nO turn\nEnter X Y Z(sample '1 2 2' or '3 1 2'):\n");
    int x,y,z;
    do
    {
        scanf("%d%d%d",&x,&y,&z);
        if (field[x-1][y-1][z-1]!=0)
            printf("\nIncorrect move. Please repeat again.\nEnter X Y (sample '1 2 2' or '3 1 2'):\n");
    }
    while (field[x-1][y-1][z-1]!=0);
    system("cls");
    if (crossFlag%2==0)
        field[x-1][y-1][z-1]=1;
    else
        field[x-1][y-1][z-1]=2;
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

int checkLine(int field[n][n][n], int length, int i, int j, int k, int vi, int vj, int vk)
{
    int firstCell=field[i][j][k];
    if (firstCell==0)
        return 0;
    for (int t=0; t<length; ++t)
    {
        if (firstCell!=field[i+t*vi][j+t*vj][k+t*vk])
            return 0;
    }
    return firstCell;
}
