#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,max,min,i;
    printf("n=");
    scanf("%d",&n);
    printf("a[1]=");
    scanf("%d",&a);
    min=a;
    max=a;
    if (n>1) {
        for (i=2;i<=n;++i){
            printf("a[%d]=",i);
            scanf("%d",&a);
            if (a<min) {min=a;}
            if (a>max) {max=a;}
        }
    }
    printf("min=%d max=%d",min,max);
    return 0;
}
