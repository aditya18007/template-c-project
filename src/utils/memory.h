//
// Created by aditya on 16/12/21.
//

#ifndef DISPERSION_TOOL_MEMORY_H
#define DISPERSION_TOOL_MEMORY_H

#include <sys/types.h>

struct Node{
	void * malloc_ptr;
	struct Node* next;
};

void * my_malloc(size_t __size);
void FREE_HEAP();


#endif //DISPERSION_TOOL_MEMORY_H
