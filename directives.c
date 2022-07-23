#include "directives.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Handles string directive, 'begin' points to the first character*/
void string_handler(line_details line, char* begin, int* DC, long* data_image) {
	/* Checks if the string argument has leading quotation marks */
	if (*begin++ != '"') {
		printf_line_error(line, "String directive should start with quotation marks");
		return;
	}


	/*insert data to the data list*/
	while (*begin && *begin != '"') {
		data_image[*DC] = *begin;
		begin++;
		(*DC)++;
	}

	/* add \0 to the end of string in data image */
	data_image[*DC] = '\0';
	(*DC)++;

	if (!*begin++) {
		printf_line_error(line, "String should be encapsulated with quotation marks");
		return;
	}
	while (isspace(*begin)) { begin++; } /* checks for extra chracters after string directive */
	if (*begin) {
		printf_line_error(line, "Extra characters after end of directive");
	}

