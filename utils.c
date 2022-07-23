#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "utils.h"


#define ERROR_FILE stderr

/*Writes an error to the stderr*/
int printf_line_error(line_details line, char* error_message, ...) { 
	int result;
	va_list ap; 
	/*prints to ERROR_FILE the relevant line number, file name.*/
	fprintf(ERROR_FILE, "Error in %s line %ld: ", line.file_name, line.line_number);
	/*prints the wanted error*/
	va_start(ap, error_message);
	result = vfprintf(ERROR_FILE, error_message, ap);
	va_end(ap);
	fprintf(ERROR_FILE, "\n");
	return result;
}


char* cat_str(char* str0, char* str1) {
	char* str = (char*)check_malloc(strlen(s0) + strlen(s1) + 1);
	strcpy(str, str0);
	strcat(str, str1);
	return str;
}


void* check_malloc(long size) {
	void* ptr = malloc(size);
	if (ptr == NULL) {
		printf("Error: Fatal: Memory allocation failed.");
		exit(1);
	}
	return ptr;
}

int move_white_space(int index, char* string) {
	for (; (string[(index)] == '\t' || string[(index)] == ' ') && (string[(index)]); (++(index)));
	return index;
}