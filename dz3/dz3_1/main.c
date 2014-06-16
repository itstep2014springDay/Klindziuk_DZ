#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    printf("%d + %d = %d\n",a,b,a+b);
    printf("%d - %d = %d\n",a,b,a-b);
    printf("%d * %d = %d\n",a,b,a*b);
    printf("%d / %d = %d\n",a,b,a/b);
    printf("%d %% %d = %d\n",a,b,a%b);
    return 0;
}
