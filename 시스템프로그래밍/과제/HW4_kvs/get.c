#include "kvs.h"
#define MAX 100

char* get(kvs_t* kvs, const char* key)
{
	char* value = (char*)malloc(sizeof(char)*MAX);

	if(!value){
		printf("Failed to malloc\n");
		return NULL;
	}
	node_t* data = kvs -> db;
	while(data != NULL){
		printf("get: %s, %s\n", data->key, data->value);
		data = data->next;
	}
	return value;
}