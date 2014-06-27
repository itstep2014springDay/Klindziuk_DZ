// Шахматная доска
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i,j,f_str,f_kl;
    printf("m=");
    scanf("%d",&m);
    printf("n=");
    scanf("%d",&n);
    f_str=1;                    // флаг строки
    printf("    ");
    for (j=65;j<n+65;++j) printf("%c",j);
    printf("\n");
    printf("   %c",218);
    for (j=1;j<=n;++j) printf("%c",196);
    printf("%c\n",191);
    for (i=1;i<=m;++i)
    {
        printf("%3d%c",i,179);
        if (f_str%2==0)
        {
            f_kl=1;             // флаг клетки
        }
        else
        {
            f_kl=0;             // флаг клетки
        }
        for (j=1;j<=n;++j)
        {
            if (f_kl%2==0)
            {
                printf("%c",177);
                ++f_kl;
            }
            else
            {
                printf(" ");
                ++f_kl;
            }
        }
        ++f_str;
        printf("%c\n",179);
    }
    printf("   %c",192);
    for (j=1;j<=n;++j) printf("%c",196);
    printf("%c",217);
    return 0;
}
