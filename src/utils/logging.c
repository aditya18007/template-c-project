//
// Created by aditya on 16/12/21.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <log.h>

void get_timestamp( char* buffer){
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer,16,"%G%m%d%H%M%S",timeinfo);
}

void make_log_directory(){
	struct stat st = {0};
	
	if (stat("../logs", &st) == -1) {
		mkdir("../logs", 0700);
	}
}

void get_file_name(char* filename){
	char timestamp[16];
	get_timestamp(timestamp);
	sprintf(filename , "../logs/%s.txt", timestamp );
}

FILE* get_log_file() {
	
	make_log_directory();
	char filename[30];
	get_file_name(filename);
	static FILE* logFile = NULL;
	if ( logFile == NULL){
		logFile = fopen(filename, "w");
	}
	return logFile;
}

void init_log(){
	log_set_quiet(0);
	FILE* logFile = get_log_file();
	int result = log_add_fp(logFile, 0);
	if( result == 0){
		log_info("Begin Logging");
		return;
	}
	perror("Failed to initialize Log File");
	exit(EXIT_FAILURE);
}