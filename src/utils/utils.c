//
// Created by aditya on 16/12/21.
//
#include <stdlib.h>
#include "logging.h"
#include "memory.h"

void init_utils(){
	init_log();
	atexit(FREE_HEAP);
}
