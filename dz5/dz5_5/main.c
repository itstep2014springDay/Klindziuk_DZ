#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a,b,s;
    printf("n=");
    scanf("%d",&n);
    if (n==0) {printf("---");}
    if (n==1) {printf("1");}
    if (n==2) {printf("1 1");}
    if (n>=3) {
        a=1;
        b=1;
        printf("1 1");
        for (i=3;i<=n;++i){
            s=a+b;
            printf(" %d",s);
            a=b;
            b=s;
        }
    }
    return 0;
}
