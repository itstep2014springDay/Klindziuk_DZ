// Седловая точка матрицы
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int m=3,n=4;
    printf("Enter M and N:\n");
    scanf("%d%d",&m,&n);
    int *matrix=NULL;
    matrix=(int*)malloc(m*n*sizeof(int));
    srand(time(NULL));
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            matrix[i*n+j]=rand()%100;
   /*
    matrix[0*n+0]=5;
    matrix[0*n+1]=6;
    matrix[0*n+2]=4;
    matrix[0*n+3]=5;
    matrix[1*n+0]=-2;
    matrix[1*n+1]=5;
    matrix[1*n+2]=3;
    matrix[1*n+3]=7;
    matrix[2*n+0]=8;
    matrix[2*n+1]=7;
    matrix[2*n+2]=-2;
    matrix[2*n+3]=6;
    */
    // вывод матрицы
    for (int i=0; i<m; ++i)
    {
        for (int j=0; j<n; ++j)
            printf("%3d",matrix[i*n+j]);
        printf("\n");
    }
    int *minArray=NULL;
    minArray=(int *)malloc(20*sizeof(int));
    for (int i=0; i<m; ++i)
    {
        minArray[i]=matrix[i*n+0];
        for (int j=0; j<n; ++j)
            if (matrix[i*n+j]<minArray[i])
                minArray[i]=matrix[i*n+j];
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
        max=matrix[j];
        for (int i=0; i<m; ++i)
            if (matrix[i*n+j]>max)
                max=matrix[i*n+j];
        for (int k=0; k<m; ++k)
            if (max==minArray[k])
            {
                flag=1;
                element=max;
            }
    }
    if (!flag)
        printf("Not found.");
    else
        printf("Element= %d",element);
    free(minArray);
    minArray=NULL;
    free(matrix);
    matrix=NULL;
    return 0;
}
