#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for (i=0;i<128;++i){
        if (i%8==0) {printf("\n");}
        switch (i) {
        case 8:
            printf("%6d= BS",i);
            break;
        case 9:
            printf("%5d= TAB",i);
            break;
        case 10:
            printf("%4d= LF",i);
            break;
        case 11:
            printf("%5d= VTAB",i);
            break;
        case 12:
            printf("%3d= FF",i);
            break;
        case 13:
            printf("%5d= CR ",i);
            break;
        case 14:
            printf("%4d=%2c",i,i);
            break;
        default: printf("%6d=%2c",i,i);
        }
    }
    printf("\n");
    return 0;
}
