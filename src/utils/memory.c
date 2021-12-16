//
// Created by aditya on 16/12/21.
//

#include <sys/types.h>
#include <stdlib.h>
#include <log.h>
#include "memory.h"

struct Node* Head;
struct Node* Curr;

void * my_malloc(size_t __size){
	void* data = malloc(__size);
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->malloc_ptr = data;
	temp->next = NULL;

	if( Head == NULL ){
		Head = temp;
		Curr = Head;
	} else {
		Curr->next = temp;
		Curr = temp;
	}
	return data;
}

void FREE_HEAP(){
	
	struct Node* curr = Head;
	while(curr != NULL){
		struct Node* temp = curr;
		curr = curr->next;
		free(temp->malloc_ptr);
		free(temp);
	}
	log_debug("Freed  all heap Memory");
}