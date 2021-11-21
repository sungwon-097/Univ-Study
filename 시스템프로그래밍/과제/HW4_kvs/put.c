#include "kvs.h"

int put(kvs_t* kvs, const char* key, const char* value)
{
	printf("put: %s, %s\n", key, value);

	node_t* data = (node_t *)malloc(sizeof(node_t));
	node_t* temp = (node_t *)malloc(sizeof(node_t));
	data->value = (char*)malloc(sizeof(value));

	strcpy(data -> key, key);
	strcpy(data -> value, value);
	data -> next = NULL;

	if(kvs -> db == NULL)
		kvs -> db = data;
	else{
		temp = kvs -> db;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next=data;
	}
	kvs -> items ++;
	
	return 0;
}
