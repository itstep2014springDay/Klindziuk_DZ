#include <cstring>
#include <cstdio>
#include <cstdlib>

#define STRLENGTH 1024

using namespace std;

struct Node
{
    char str[STRLENGTH];
    Node *yeslink;
    Node *nolink;
};

void clearTree(Node *&node)
{
    if(node)
    {
        clearTree(node->yeslink);
        clearTree(node->nolink);
        delete node;
        node = nullptr;
    }
}

bool answer()
{
    char q;
    while (true)
    {
        printf("Type 'y'- Yes, or 'n' - No\n");
        q=fgetc(stdin);
        if(q=='\n')
            q=fgetc(stdin);
        if (q=='y')
            return true;
        if (q=='n')
            return false;
    }
}

void createNode(Node *&node)
{
    node=new Node;
    node->nolink=nullptr;
    node->yeslink=nullptr;
}

void addAnimal(Node *node)
{
    char strAnimal[STRLENGTH],strAnswer[STRLENGTH],strTemp[STRLENGTH];
    printf("Sdaus, kto je eto bil?\n");
    scanf("%s",strAnimal);
    fgetc(stdin);
    printf("Chem ono otlichaetsa?\n");
    fgets(strAnswer,1024*sizeof(char),stdin);
    strAnswer[strlen(strAnswer)-1]='\0';
    printf("Enter true answer for %s.\n", strAnimal);
    bool trueAnswer = answer();
    strcpy(strTemp,node->str);
    strcpy(node->str,strAnswer);

    Node *pYes=nullptr,*pNo=nullptr;
    createNode(pYes);
    createNode(pNo);

    if(trueAnswer)
    {
        strcpy(pYes->str,strAnimal);
        strcpy(pNo->str,strTemp);
    }
    else
    {
        strcpy(pYes->str,strTemp);
        strcpy(pNo->str,strAnimal);
    }
    node->yeslink=pYes;
    node->nolink=pNo;
}

bool isLeaf(Node *p)
{
    return p->yeslink==nullptr && p->nolink==nullptr;
}

void process(Node *root)
{
    Node *p=root;
    while(!isLeaf(p))
    {
        printf("%s\n",p->str);
        if (answer())
            p=p->yeslink;
        else
            p=p->nolink;
    }

    printf("This is %s?\n",p->str);
    if (answer())
        printf("Ok, I have won!\n");
    else
        addAnimal(p);
}

void writeFile(Node *p,FILE *myFile)
{
    if (p)
    {
        if (isLeaf(p))
            fprintf(myFile,"a: %s\n",p->str);
        else
            fprintf(myFile,"q: %s\n",p->str);
        writeFile(p->nolink,myFile);
        writeFile(p->yeslink,myFile);
    }
}

Node *readFile(FILE *myFile)
{
    char symbol = fgetc(myFile);
    Node *p=nullptr;
    if(symbol == EOF)
        return p;
    fgetc(myFile);//:
    fgetc(myFile);//space
    createNode(p);
    char strAnswer[STRLENGTH];
    fgets(strAnswer,STRLENGTH*sizeof(char),myFile);
    strAnswer[strlen(strAnswer)-1]='\0';
    strcpy(p->str, strAnswer);
    if (symbol=='q')
    {
        p->nolink=readFile(myFile);
        p->yeslink=readFile(myFile);
    }
    return p;
}

int main()
{

    Node *root = nullptr;

    FILE *myFile;
    myFile=fopen("myFile.txt","r");

    if (myFile)
    {
       root=readFile(myFile);
       fclose(myFile);
    }
    else
    {
        createNode(root);
        strcpy(root->str,"cat");
    }

    do
    {
        printf("Think for animal\n\n");
        system("sleep 1");
        process(root);
        printf("Want you play one more time?\n\n");
    }
    while(answer());

    myFile = fopen("myFile.txt", "w");
    writeFile(root,myFile);
    fclose(myFile);

    clearTree(root);

    return 0;
}
