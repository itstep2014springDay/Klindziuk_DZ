// Седловая точка матрицы
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int m=3,n=4;
    printf("Enter M and N:\n");
    scanf("%d%d",&m,&n);
    int **matrix=NULL;
    matrix=(int**)malloc(m*sizeof(int*));
    for (int i=0; i<m; ++i)
        matrix[i]=NULL;
    for (int i=0; i<m; ++i)
        matrix[i]=(int *)malloc(n*sizeof(int));

    srand(time(NULL));
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            matrix[i][j]=rand()%100;
    /*
         matrix[0][0]=5;
         matrix[0][1]=6;
         matrix[0][2]=4;
         matrix[0][3]=5;
         matrix[1][0]=-2;
         matrix[1][1]=5;
         matrix[1][2]=3;
         matrix[1][3]=7;
         matrix[2][0]=8;
         matrix[2][1]=7;
         matrix[2][2]=-2;
         matrix[2][3]=6;
         */
    // вывод матрицы
    for (int i=0; i<m; ++i)
    {
        for (int j=0; j<n; ++j)
            printf("%3d",matrix[i][j]);
        printf("\n");
    }
    int *minArray=NULL;
    minArray=(int *)malloc(20*sizeof(int));
    for (int i=0; i<m; ++i)
    {
        minArray[i]=matrix[i][0];
        for (int j=0; j<n; ++j)
            if (matrix[i][j]<minArray[i])
                minArray[i]=matrix[i][j];
    }
    // вывод массива минимумов
/*
    printf("\n");
    for (int i=0; i<m; ++i)
        printf("%3d\n",minArray[i]);
*/
    int max,flag=0,element;
    for (int j=0; j<n; ++j)
    {
        max=matrix[0][j];
        for (int i=0; i<m; ++i)
            if (matrix[i][j]>max)
                max=matrix[i][j];
        for (int k=0; k<m; ++k)
            if (max==minArray[k])
            {
                flag=1;
                element=max;
            }
    }
    if (flag)
        printf("Element= %d",element);
    else
        printf("Not found.");
    free(minArray);
    minArray=NULL;
    for (int i=0; i<m; ++i)
    {
        free(matrix[i]);
        matrix[i]=NULL;
    }
    free(matrix);
    matrix=NULL;
    return 0;
}
