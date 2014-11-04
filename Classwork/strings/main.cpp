#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str[200]="mama mila ramy";
    //gets(str);
    printf("%s\n",strtok(str," "));
    printf("%s\n",strtok(NULL," "));
    printf("%s\n",strtok(NULL," "));
    printf("%s\n",strtok(NULL," "));
    return 0;
}
