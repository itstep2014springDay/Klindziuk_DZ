// Стекплетрон
#include <stdio.h>
#include <stdlib.h>

const int n=100;

void memoryDump(int memory[],int accumulator,int instructionCounter,
                int instructionRegister,int operationCode,int operand,int bias,int top);

int main()
{
    int memory[n],accumulator=0,instructionCounter=0,instructionRegister=0,
                  operationCode=0,operand=0,bias=0,top=100;
    for (int i=0; i<n; ++i)
        memory[i]=0;
    printf("*** Stackpletron welcomes you! ***\n*** Enter your programm      ***\n");
    /*
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
            memoryDump(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand,bias,top);
            break;
        }
        printf("%02d? ",instructionCounter);
        scanf("%d",&instructionRegister);
    }
    */

    // программа рекурсивного расчёта факториала введённого числа
    memory[0]=+1009;
    memory[1]=+2600;
    memory[2]=+2009;
    memory[3]=+2600;
    memory[4]=+4411;
    memory[5]=+2700;
    memory[6]=+2110;
    memory[7]=+1110;
    memory[8]=+4300;

    memory[11]=+2400;
    memory[12]=+2600;
    memory[13]=+2200;
    memory[14]=+2500;
    memory[15]=+2002;
    memory[16]=+4231;
    memory[17]=+3401;
    memory[18]=+2600;
    memory[19]=+2600;
    memory[20]=+2002;
    memory[21]=-3101;
    memory[22]=+2600;
    memory[23]=+4411;
    memory[24]=+2700;
    memory[25]=+3302;
    memory[26]=+2103;
    memory[27]=+2700;
    memory[28]=+2700;
    memory[29]=+2500;
    memory[30]=+4501;
    memory[31]=+3401;
    memory[32]=+2103;
    memory[33]=+2700;
    memory[34]=+2500;
    memory[35]=+4501;

    //memoryDump(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand,bias,top);
    instructionCounter=0;
    do
    {
        instructionRegister=memory[instructionCounter];
        operationCode=abs(instructionRegister/100);
        operand=instructionRegister%100;
        switch (operationCode)
        {
        case 10: //READ
            scanf("%d",&memory[operand+bias]);
            ++instructionCounter;
            break;
        case 11: //WRITE
            printf("%d\n",memory[operand+bias]);
            ++instructionCounter;
            break;
        case 20: //LOAD
            accumulator=memory[operand+bias];
            ++instructionCounter;
            break;
        case 21: //STORE
            memory[operand+bias]=accumulator;
            ++instructionCounter;
            break;
        case 22: //LOADTOP
            accumulator=top;
            ++instructionCounter;
            break;
        case 23: //STORETOP
            top=accumulator;
            ++instructionCounter;
            break;
        case 24: //LOADBIAS
            accumulator=bias;
            ++instructionCounter;
            break;
        case 25: //STOREBIAS
            bias=accumulator;
            ++instructionCounter;
            break;
        case 26: //PUSH
            memory[--top]=accumulator;
            ++instructionCounter;
            break;
        case 27: //POP
            accumulator=memory[top++];
            ++instructionCounter;
            break;
        case 30: //ADD
            accumulator+=memory[operand+bias];
            ++instructionCounter;
            break;
        case 31: //SUBSTRACT
            accumulator-=memory[operand+bias];
            ++instructionCounter;
            break;
        case 32: //DIVIDE
            if (memory[operand+bias]!=0)
            {
                accumulator/=memory[operand+bias];
                ++instructionCounter;
            }
            else
            {
                printf("Error! Division by zero!\n");
                memoryDump(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand,bias,top);
                operationCode=43;
            }
            break;
        case 33: //MULTIPLY
            accumulator*=memory[operand+bias];
            ++instructionCounter;
            break;
        case 34: //LITERAL
            accumulator=operand;
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
            printf("\n*** Stackpletron finished work ***\n");
            memoryDump(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand,bias,top);
            break;
        case 44: //CALL
            memory[--top]=instructionCounter;
            instructionCounter=operand;
            break;
        case 45: //RETURN
            instructionCounter=memory[top++]+1;
            for (int i=0;i<abs(operand);++i)
                ++top;
            break;
        default:
            printf("Error! Incorrect command.\n");
            memoryDump(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand,bias,top);
            operationCode=43;
        }
    }
    while (operationCode!=43);
    return 0;
}

void memoryDump(int memory[],int accumulator,int instructionCounter,int instructionRegister,int operationCode,int operand,int bias,int top)
{
    printf("\nRegisters:\naccumulator\t\t%+05d\ninstructionCounter\t   %02d\ninstructionRegister\t%+05d\noperationCode\t\t   %02d\noperand\t\t\t   %02d\nbias\t\t\t   %02d\ntop\t\t\t   %02d\n",accumulator,instructionCounter,instructionRegister,operationCode,operand,bias,top);
    printf("\nMEMORY:\n");
    printf("       0     1     2     3     4     5     6     7     8     9\n");
    for(int i=0; i<n/10; ++i)
    {
        printf("%2d",i*10);
        for(int j=0; j<n/10; ++j)
            printf(" %+05d",memory[i*10+j]);
        printf("\n");
    }
    printf("\n");
}
