#include "kvs.h"
#define MAX 100

char* get(kvs_t* kvs, const char* key)
{
	/* do program here */

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

// node_t* data = kvs->db;
// 	printf("get: %s, %s\n", data->key, data->value);
// 	printf("get: %s, %s\n", data->next->key, data->next->value);
// 	printf("get: %s, %s\n", data->next->next->key, data->next->next->value);
// 	printf("get: %s, %s\n", data->next->next->next->key, data->next->next->next->value);
