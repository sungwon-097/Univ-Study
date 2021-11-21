#include "kvs.h"
#define MAX 100

char tmp;

int main()
{
	// 1. create KVS
	
	kvs_t* kvs = open();
	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}
	FILE* fp = fopen("student.dat", "r");
	
    while(!feof(fp)){
		char key[MAX], val[MAX];
		tmp = fscanf(fp, "%s %s\n", key, val);
		tmp = put(kvs, key, val);
	}
	get(kvs, kvs->db->key);
	close(kvs);
	return 0;
}
