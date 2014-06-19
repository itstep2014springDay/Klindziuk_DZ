// Проценты
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s_nach,v_nach,pr,sl,kv,i,d,s,v;
    s_nach=1000;
    v_nach=1000;
    pr=6;
    sl=4;
    kv=3;
    d=100;
    s=s_nach*d;
    v=v_nach*d;
    i=0;
    int delay=3;
    int flag=0;     // флаг когда Вася стал богаче
    int f_time=0;   // время когда Вася стал богаче
    do
    {
        ++i;
        printf("Time %d kvart.\n",i);
        s=s+s_nach*pr;
        v=v+v/100*sl;
        printf("Sasha= $%d.%02d\nVasya= $%d.%02d\n\n",s/100,s%100,v/100,v%100);
        if (v>s)
        {
            flag=1;
            --delay;
        }
        if (v>s && f_time==0)
        {
            f_time=i;
        }
    }
    while (flag==0 || delay>=0);
    printf("Vasya stal bogache cherez %d kvart.\n",f_time);
    return 0;
}
