#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int i,j,a,a2,k,z;
    for (i=1; i<=0x7fffffff; ++i)
    {
        k=1;
        a=i;
        while (a>0)
        {
            a=a/10;
            k=k*10;
        }
        a=i;
        a2=a*a;
        z=a2%k;
        if (a==z)
        {
            printf("%7lld=%7lld\n",a,a2);
        }
    }
    //j=(1<<31)-1;
    //printf("%lld",j);
    return 0;
}
