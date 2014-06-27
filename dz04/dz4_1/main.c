#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,p;
    printf("N=");
    scanf("%d",&n);
    p=1;
    for (int i=1;i<=n;++i){
        printf("A[%d]=",i);
        scanf("%d",&a);
        p=p*a;
    }
    printf("P=%d",p);
    return 0;
}
