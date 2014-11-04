#include <cstdio>

using namespace std;

int main()
{
    char str[1000];
    gets(str);
    int i=0;
    while (str[i]!='\0')
        ++i;
    int n=i;
    i=0;
    while (str[i]!='\0')
    {
        if (str[i]=='a')
        {
            str[i]='b';
            for(int j=n+1;j>i+1;--j)
                str[j]=str[j-1];
            str[i+1]='b';
            ++n;
            str[n]='\0';
        }
        ++i;
    }
    printf("%s",str);
    return 0;
}
