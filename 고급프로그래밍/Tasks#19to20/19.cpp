#include <iostream>

using namespace std;


int* allocArray(int);
void printArray(int *, int);
void freeArray(int *);

int main()
{
    int* arr;
    int size;
    
    cout<< "Enter the array size: ";
    cin >> size;
    arr = allocArray(size);

    for(int i = 0 ; i < size ; i ++)
    {
        cout<< "Put an array element: ";
        cin >> arr[i];
    }
    printArray(arr, size);
    freeArray(arr);
    return 0;
}

int* allocArray(int len){
    
    int size;
    int* arr = (int*)malloc(sizeof(int)*(size));
    return arr;
}

void printArray(int *arr, int size){
    for(int i = 0 ; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void freeArray(int *arr){
    free(arr);
}