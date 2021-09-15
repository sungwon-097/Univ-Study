#include <stdio.h>

int main(){
	printf("%lubit archtecture\n",sizeof(long)==8?64:32);
	return 0;
}