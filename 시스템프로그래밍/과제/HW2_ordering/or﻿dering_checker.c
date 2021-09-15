#include <stdio.h>
typedef unsigned char *pointer;

int show_bytes(pointer start, size_t len){
	size_t i;
	char addressArr[sizeof(int)]={1,1,0,0};
	for(i=0;i<len;i++){
		if(start[i]==!addressArr[i])
		return 0;
	}
	return 1;
}
int main(void){
	int a=257;
	if(show_bytes((pointer) &a, sizeof(int)))
		printf("Big Endian");
	else
		printf("Little Endian");
	return 0;
}