#ifndef MATHEXT_H_INCLUDED
#define MATHEXT_H_INCLUDED

int gcd(int a, int b);
int lcm(int a, int b);
void convert36(int x, int b);
void drawDice(int x);
int myRandWiki(int x0);
int myRandOther(int x0);
int primeNumber(int x); //bool
void inputArray(int array[],int size);
void outputArray(int array[],int size);
int searchInArray(const int array[],int size,int number);
void generateArray(int array[],int size, int min, int max);
int searchMinInArray(int array[],int size);
int searchMaxInArray(int array[],int size);

#endif // MATHEXT_H_INCLUDED
