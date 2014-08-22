#ifndef ARRAYEXT_H_INCLUDED
#define ARRAYEXT_H_INCLUDED

void inputArray(int array[],int size);
void outputArray(int array[],int size);
int searchInArray(const int array[],int size,int number);
void generateArray(int array[],int size, int min, int max);
int searchMinInArray(int array[],int size);
int searchMaxInArray(int array[],int size);
void sortSelectionArray(int array[],int size);
void sortBubbleArray(int array[],int size);
void sortInsertionArray(int array[],int size);
void sortMergeArray(int array[],int sizeArray);
void sortHeapArray(int array[],int sizeArray);
void sortQuickArray(int array[],int sizeArray);
void copyArrayAinB(int arrayA[],int arrayB[], int sizeArray);

#endif // ARRAYEXT_H_INCLUDED
