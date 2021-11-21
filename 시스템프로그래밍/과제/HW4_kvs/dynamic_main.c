#include "kvs.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#define MAX 100

int main()
{

	void *handle;
	char *error;
	handle = dlopen("./libkvs.so", RTLD_LAZY);
	if(!handle){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	kvs_t* (*open)();
	open = (kvs_t* (*)())dlsym(handle, "open");
	if ((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	int (*close)(kvs_t *);
	close = (int(*)(kvs_t *))dlsym(handle, "close");
	if ((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	int (*put)(kvs_t *, const char *, const char *);
	put = (int(*)(kvs_t *, const char *, const char *))dlsym(handle, "put");
	if ((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	char* (*get)(kvs_t *, const char *);
	get = (char*(*)(kvs_t *, const char *))dlsym(handle, "get");
	if ((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	kvs_t* kvs = open();
	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}
	FILE* fp = fopen("student.dat", "r");
	char tmp;
    while(!feof(fp)){
		char key[MAX], val[MAX];
		tmp = fscanf(fp, "%s %s\n", key, val);
		tmp = put(kvs, key, val);
	}
	get(kvs, kvs->db->key);
	close(kvs);
	return 0;
}