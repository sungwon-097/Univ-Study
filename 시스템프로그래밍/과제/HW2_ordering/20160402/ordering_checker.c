#include <stdio.h>
int main(){
	int a=1;
	*(char*) & a==1?
	printf("Little Endian\n")
	:printf("Big Endian\n");
	return 0;
}