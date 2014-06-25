// Процент денег в банке
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double zah,vad,vlad,proc,nach;
    nach=10000;
    zah=nach;
    vad=nach;
    proc=0.13;
    for (int i=1; i<=12; ++i)
    {
        zah=zah+zah*proc/12;
        vad=vad+vad*proc/12;
        if (i==12)
        {
            printf("Zahar=\t%.3f\t(12 month)\n",zah);
        }
        if (i==7)
        {
            printf("Vadim=\t%.3f\t(7 month)\n",vad);
        }
        if (i==5)
        {
            vlad=(zah+vad)*0.63;
            printf("Vlad=\t%.3f\t(5 month)\n",vlad);
        }
    }
    return 0;
}
