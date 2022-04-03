#include <iostream>
#define ARRAY_SIZE 5

using namespace std;

void fillArray(int array[], int len){
    cout << "Put array elements : ";
    for(int i = 0 ; i < len ; i++)
        cin >> array[i];
}

void printArray(int array[], int len){
    cout << "Array elements are : ";
    for(int i = 0 ; i < len ; i++)
        cout << array[i] << " ";
}

int main(){
    int arr[ARRAY_SIZE];
    fillArray(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE);
    return 0;
}