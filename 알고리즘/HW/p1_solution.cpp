#include "iostream"

void printArr(int arr[], int len)	// 배열을 출력하기 위한 함수
{ 
	for(int i=0;i<len;i++)
		printf("%d ", *(arr+i));
	printf("\n");
}


void swap(int *x, int *y) // bubble sort에서 값 변경을 위해 bit swap을 실행함
{ 
	*x = *x ^ *y ; 
	*y = *x ^ *y ; 
	*x = *x ^ *y ;
}

void insertion_sort (int arr[], int len)
{
	printf("Insertion\n");
	for (int i = 1 ; i < len ; i ++)// size가 2인 배열부터 시작해 부분집합을 늘려감
	{ 
		int key = arr[i]; // arr[i]보다 앞에 있는 값들은 정렬이 완료됐다고 간주, key값의 insertion을 수행
		int j = i - 1;

		for ( ; j>=0 && arr[j] < key ; j --)// arr[j] > key 이면 오름차순 정렬이 실행됨
		{ 
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
		printArr(arr, len);
	}
}

void bubble_sort (int arr[], int len){
	printf("\nBubble\n");
	for(int i = 0 ; i < len - 1 ; i ++)
	{
		bool sortCheck = false; // 조건문을 실행하지 않을 때(정렬이 끝나있을 때)를 확인하기 위한 변수
		
		for (int j = 0 ; j < len - 1 ; j ++)
		{
			if(arr[j] < arr[j + 1])// arr[j] > arr[j+1] 이면 오름차순 정렬이 실행됨
			{ 
				sortCheck = true;
				swap(arr+j, arr+j+1); // bit swap 방식으로 값을 변경
			}
		}
		if(sortCheck==false) // 정렬이 끝나있다고 간주, 루프 종료
			break;
		printArr(arr, len);
	}
}