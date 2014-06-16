#include <stdio.h>
#include <stdlib.h>

int main()
{
    double r,h,l,s,v;
    printf("r=");
    scanf("%lf",&r);
    printf("h=");
    scanf("%lf",&h);
    v=1.0/3*3.14*r*r*h;
    l=sqrt(r*r+h*h);
    s=3.14*r*(r+l);
    printf("V=%.2f\n",v);
    printf("S=%.2f\n",s);
    return 0;
}
