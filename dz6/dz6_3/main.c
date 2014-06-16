#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w,h,i,j;
    printf("w=");
    scanf("%d",&w);
    printf("h=");
    scanf("%d",&h);
    for (i=1;i<=h;++i){
        for (j=1;j<=w;++j){
            if (i==1 || i==h) {
                printf("#");}
            else
            if (j==1 || j==w) {
                printf("#");}
            else {
                printf(" ");}

        }
        printf("\n");
    }
    return 0;
}
