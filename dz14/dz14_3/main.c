// Игра в кости с компьютером
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../mylib/mathext.h"

int main()
{
    int human, computer, sumHuman,sumComputer,n=2;
    srand(time(NULL));
    printf("Your turn!\n");
    getch();
    sumHuman=0;
    for (int i=1; i<=n; ++i)
    {
        human=rand()%6+1;
        drawDice(human);
        sumHuman+=human;
    }
    printf("Computer turn!\n");
    getch();
    sumComputer=0;
    for (int i=1; i<=n; ++i)
    {
        computer=rand()%6+1;
        drawDice(computer);
        sumComputer+=computer;
    }
    if (sumHuman>sumComputer)
        printf("You win!\n");
    else if (sumHuman<sumComputer)
        printf("You loss!\n");
    else
        printf("Draw!\n");
    return 0;
}
