#include <cstdio>

int main()
{

    FILE *file=fopen("sample.txt","w");
    fprintf(file,"%d+%d=%d\n",3,5,3+5);
    fclose(file);
    return 0;
}
