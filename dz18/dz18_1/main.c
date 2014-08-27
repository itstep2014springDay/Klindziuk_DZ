// Симплетрон
#include <stdio.h>
#include <stdlib.h>

const int n=100;

void memoryDump(int memory[],int accumulator,int instructionCounter,
                int instructionRegister,int operationCode,int operand);

int main()
{
    int memory[n],accumulator=0,instructionCounter=0,instructionRegister=0,
                  operationCode=0,operand=0;
    for (int i=0; i<n; ++i)
        memory[i]=0;
    printf("*** Simpletron welcomes you! ***\n*** Enter your programm      ***\n");
    printf("%02d? ",instructionCounter);
    scanf("%d",&instructionRegister);
    while (instructionRegister!=99999)
    {
        if (instructionRegister>9999 || instructionRegister<-9999)
        {
            printf("Input error!\n%02d? ",instructionCounter);
            scanf("%d",&instructionRegister);
        }
        memory[instructionCounter]=instructionRegister;
        ++instructionCounter;
        if (instructionCounter>=n)
        {
            printf("Memory is over!");
            memoryDump(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand);
            break;
        }
        printf("%02d? ",instructionCounter);
        scanf("%d",&instructionRegister);
    }
    //memoryDump(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand);
    instructionCounter=0;
    do
    {
        instructionRegister=memory[instructionCounter];
        operationCode=instructionRegister/100;
        operand=instructionRegister%100;
        switch (operationCode)
        {
        case 10: //READ
            scanf("%d",&memory[operand]);
            ++instructionCounter;
            break;
        case 11: //WRITE
            printf("%d\n",memory[operand]);
            ++instructionCounter;
            break;
        case 20: //LOAD
            accumulator=memory[operand];
            ++instructionCounter;
            break;
        case 21: //STORE
            memory[operand]=accumulator;
            ++instructionCounter;
            break;
        case 30: //ADD
            accumulator+=memory[operand];
            ++instructionCounter;
            break;
        case 31: //SUBSTRACT
            accumulator-=memory[operand];
            ++instructionCounter;
            break;
        case 32: //DIVIDE
            if (memory[operand]!=0)
            {
                accumulator/=memory[operand];
                ++instructionCounter;
            }
            else
            {
                printf("Error! Division by zero!\n");
                memoryDump(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand);
                operationCode=43; // правильный ли тут выход из цикла? (можно ли использовать break?)
            }
            break;
        case 33: //MULTIPLY
            accumulator*=memory[operand];
            ++instructionCounter;
            break;
        case 40: //BRANCH
            instructionCounter=operand;
            break;
        case 41: //BRANCHNEG
            if (accumulator<0)
                instructionCounter=operand;
            else
                ++instructionCounter;
            break;
            break;
        case 42: //BRANCHZERO
            if (accumulator==0)
                instructionCounter=operand;
            else
                ++instructionCounter;
            break;
        case 43: //HALT
            printf("\n*** Simpletron finished work ***\n");
            memoryDump(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand);
            break;
        default:
            printf("Error! Incorrect command.\n");
            memoryDump(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand);
            operationCode=43;
        }
    }
    while (operationCode!=43);
    return 0;
}

void memoryDump(int memory[],int accumulator,int instructionCounter,int instructionRegister,int operationCode,int operand)
{
    printf("\nRegisters:\naccumulator\t\t%+05d\ninstructionCounter\t   %02d\ninstructionRegister\t%+05d\noperationCode\t\t   %02d\noperand\t\t\t   %02d\n",accumulator,instructionCounter,instructionRegister,operationCode,operand);
    printf("\nMEMORY:\n");
    printf("       0     1     2     3     4     5     6     7     8     9\n");
    for(int i=0; i<n/10; ++i)
    {
        printf("%2d",i*10);
        for(int j=0; j<n/10; ++j)
            printf(" %+05d",memory[i*10+j]);
        printf("\n");
    }
}
