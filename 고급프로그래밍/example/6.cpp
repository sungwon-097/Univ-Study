#include <iostream>

using namespace std;

void fillArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        cin >> arr[i];
}
void printArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[5];
    fillArray(arr, 5);
    printArray(arr, 5);
}