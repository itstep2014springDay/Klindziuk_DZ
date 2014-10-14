#include <iostream>
#include <cstring>

using namespace std;

int myStrlen(char *str)
{
    int i=0;
    while (str[i]!='\0')
        ++i;
    return i;
}

char *myStrcpy(char *destination, char *source)
{
    int i=0;
    while (source[i]!='\0')
    {
        destination[i]=source[i];
        ++i;
    }
    destination[i]='\0';
    return destination;
}

char *myStrcat(char *destination, char *source)
{
    int i=0;
    while (destination[i]!='\0')
        ++i;
    int destinationLength=i;
    i=0;
    while (source[i]!='\0')
    {
        destination[destinationLength+i]=source[i];
        ++i;
    }
    destination[destinationLength+i]='\0';
    return destination;
}

int myStrcmp(char *str1, char *str2)
{
    int i=0,x=0;
    while (str1[i]!='\0' || str2[i]!='\0')
    {
        x=str1[i]-str2[i];
        if (x!=0)
            break;
        ++i;
    }
    return x;
}

int main()
{
    const int n=50;
    char str1[n]="En taro Adun!",str2[n]="For the Swarm!",str3[n];
    cout <<"str1\t\t"<<str1<<endl;
    cout <<"str2\t\t"<<str2<<endl<<endl;

    int length;
    length=strlen(str1);
    cout <<"strlen\t\t"<<length<<endl;
    length=myStrlen(str1);
    cout <<"myStrlen\t"<<length<<endl<<endl;

    strcpy(str3,str1);
    cout <<"strcpy\t\t"<<str3<<endl;
    myStrcpy(str3,str1);
    cout <<"mySrcpy\t\t"<<str3<<endl<<endl;

    strcpy(str3,str1);
    strcat(str3,str2);
    cout <<"strcat\t\t"<<str3<<endl;
    strcpy(str3,str1);
    myStrcat(str3,str2);
    cout <<"myStrcat\t"<<str3<<endl<<endl;

    int x;
    x=strcmp(str1,str2);
    cout <<"strcmp\t\t"<<x<<endl;
    x=myStrcmp(str1,str2);
    cout <<"myStrcmp\t"<<x<<endl;

    return 0;
}
