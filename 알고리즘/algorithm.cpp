//  > g++ -o run.exe algorithm.cpp
//  > ./run.exe

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ASIZE 10
#define bucket_number 10
using namespace std;

void insertionSort (int arr[], int N); // 삽입정렬

void bubbleSort(int l[], int N);       // 거품정렬

void selectionSort(int l[], int N);     // 선택정렬

void quickSort(int arr[], int l, int r);  // 퀵정렬
int partition(int arr[], int l, int r, int x); //퀵정렬에서 devide
void swap(int *x, int *y);  // bitwise swap

void mergeSort(vector<int> arr, int l, int r); // 병합정렬
void merge(vector<int> arr, int l, int m, int r); // 병합정렬에서 devide된 배열을 병함

int select(int arr[], int l, int r, int k); // Linear-Time Selection : k번쨰로 적은 수 선택

void countingSort(int array[], int n); // 계수정렬

static void bucketsort(int Array[], int n, int k); //버킷정렬

void radixsort(int array[], int size); // 기수정렬
int getMax(int arr[], int size); //array의 최대값 반환
void countingSortforRadix(int array[], int size, int place); 

int main (void)
{
    int intarr[ASIZE]={9,8,6,6,4,5,3,2,1,0};
    vector<int> vecarr={9,8,6,6,4,5,3,2,1,0};

    // fill in the function ::

    for(int i=0; i<ASIZE ; i++)
        cout << intarr[i] << " ";
    
    for(int i:vecarr)
        cout << i << " ";

    return 0;
}

void insertionSort (int arr[], int N) 
{
    for (int i=1; i<N; i++) // key까지의 배열을 한 칸씩 늘려가며 정렬함. 정렬된 리스트의 크기가 
    {
        int key = arr[i]; // 비교할 key, 정렬된 배열 바로 다음 위치
        int j = i-1;
        while (j >= 0 && arr[j] > key)  // key바로 앞 위치부터 인덱스 0까지 key의 위치를 찾음
        {
            arr[j+1] = arr[j];  // key위치를 찾을 떄까지 값을 오른쪽으로 민다
            j--;
        }
        arr[j+1] = key; // key를 삽입
    }
}
void bubbleSort(int l[], int N){

    for(int i = 1 ; i < N ; i++){

        for(int j = 0 ; j < N ; j++){

            if(l[j]>l[i])
                swap(l[j], l[i]); // 인접한 원소를 조건에 맞게 변경
        }
    }
}
void selectionSort(int l[], int N){ // i+1번째로 작은 값을 찾아서 교체. 앞에서부터 정렬

    for(int i = 0; i < N - 1 ; i ++ ){
        int minidx=i;
        for(int j = i + 1 ; j < N; j ++ ){

            if(l[j] < l[minidx])
                minidx=j;
        }
        swap(l[minidx], l[i]);
    }
}

void swap(int *x, int *y){ // 메모리 bit연산으로 swap
    *x=*x^*y;
    *y=*x^*y;
    *x=*x^*y;
}

int partition(int arr[], int l, int r, int pivot) 
{ 
    int i; 
    for (i = l ; i < r ; i++) 
        if (arr[i] == pivot) 
            break; 
    swap(arr[i], arr[r]); 

    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            swap(arr[i], arr[j]); 
            i++; 
        } 
    } 
    swap(arr[i], arr[r]); 
    return i; 
}

void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int pivot = arr[r];
        int pos = partition(arr, l, r, pivot);
        quickSort(arr, l, pos - 1);
        quickSort(arr, pos + 1, r);
    }
}
void mergeSort(vector<int> arr, int l, int r) 
{ 
    if (l < r) {
        int m = (l+r)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    }
}

void merge(vector<int> arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    vector<int> L(n1), R(n2); 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 

    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 

    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

int select(int arr[], int l, int r, int k)
{
    if (k >= 0 && k < r - l + 1)
    {
        int n = r-l+1; // Number of elements in arr[l..r] 
        int pivot = arr[l + rand() % n]; 
        int pos = partition(arr, l, r, pivot); 
// If position is same as k 
        if (pos-l == k) 
            return arr[pos]; 
        if (pos-l > k) // If position is more, recur for left 
            return select(arr, l, pos-1, k); 
        else // Else recur for right subarray 
            return select(arr, pos+1, r, k-pos+l-1); 
    }
}

void countingSort(int array[], int n) {
    int count [ASIZE+1]; /* k is a MACRO constant */
    for (int i=0; i<ASIZE+1; i++) 
        count[i] = 0;

    for (int i=0; i<n; i++)
        count[array[i]]++;

    for (int i=0, j=0; i<=ASIZE; i++) 
    { 
        while(count[i]>0)
        {
            array[j] = i;
            j++;
            count[i]--;
        }
    } 
}

static void bucketsort(int Array[], int n, int k) 
{
//creating empty buckets. Suppose that bucket_number is a macro constant
    vector<int> bucket[bucket_number];
//transfer elements of array into respective bucket
    for (int i = 0; i < n; i++)
    {
        int b = Array[i] / ceil (k / bucket_number); 
        bucket[b].push_back(Array[i]);
    }
//sort all elements of each bucket
    if (bucket_number < k)
    {
        for (int i = 0; i < bucket_number; i++)
        sort(bucket[i].begin(), bucket[i].end());
    }
//combine all buckets to create sorted list
    int m = 0;
    for (int i = 0; i < bucket_number; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        { 
            Array[m] = bucket[i][j]; 
            m++;
        }
    }
}
int getMax(int arr[], int size){
    int max=0;
    for(int i=0; i<size; i++)
        if(arr[i]>max)
            max=arr[i];
    return max;
}
void radixsort(int array[], int size) {
// Get maximum element
    int max = getMax(array, size);
// Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        countingSortforRadix(array, size, place);
}

void countingSortforRadix(int array[], int size, int place) {
    const int max = 10;
    int* output = new int[size];
    int* count = new int[max];
    int key = 0;
    for (int i = 0; i < max; ++i)
        count[i] = 0;
// Calculate count of elements
    for (int i = 0; i < size; i++){ 
        key = (array[i] / place) % 10;
        count[key]++; 
    }
// Calculate cummulative count
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];
// Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--) {
        key = (array[i] / place) % 10;
        output[count[key] - 1] = array[i];
        count[key]--;
    }
for (int i = 0; i < size; i++)
array[i] = output[i];
}