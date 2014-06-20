// Изгнание мух
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,exorcismSpeed,failigueTime,flyReturnSpeed,t,t_old;
    printf("Kolichestvo myh (N) - ");
    scanf("%d",&n);
    printf("Skorost izgnaniya myh (exorcismSpeed) - ");
    scanf("%d",&exorcismSpeed);
    printf("Vremya ystavaniya (failigueTime) - ");
    scanf("%d",&failigueTime);
    printf("Kolichestvo novih myh (flyReturnSpeed) - ");
    scanf("%d",&flyReturnSpeed);
    /*
    n=10;
    exorcismSpeed=5;
    failigueTime=100;
    flyReturnSpeed=1;
    */
    t=0;
    int n_nach=n;
    int flag=0;
    while (1)
    {
        ++t;
        if (t<failigueTime)
        {
            n=n-exorcismSpeed;
        }
        else
        {
            n=n-exorcismSpeed*0.2;
        }
        if (n<=0)
        {
            break;
        }
        n=n+flyReturnSpeed;
        if (n_nach<n)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("\nVremya (T) - %d\n",t);
    }
    else
    {
        printf("\nVignat myx nelzya\n");
    }
    return 0;
}
