#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

/**
 processes a single assembly source file. 
 Returns the result status.
 gets filename, without it's extension
 returns whether succeeded
 */

static bool process_file(char* filename);

int main(int argc, char* argv[]) {
	int i;
	/* To break line if needed */
	bool succeeded = TRUE;
	/* Process each file by arguments */
	for (i = 1; i < argc; ++i) {
		/* if last process failed and there's another file, break line: */
		if (!succeeded) puts("");
		/* for each file name, send it for full processing. */
		succeeded = process_file(argv[i]);
		/* Line break if failed */
	}
	return 0;
}


static bool process_file(char* filename) {
	/* Memory address counters */
	bool is_success = TRUE;
	FILE* file_des; /* Current assembly file descriptor to process */
	int temp_c;
	char* input_filename;

	/* Concat filename with .as extension */
	input_file = cat_str(filename, ".as");

	/* Open file. Skip if fails */
	file_dst = fopen(input_file, "r");
	if (file_dst == NULL) {
		/* if file couldn't be opened, write to stderr. */
		printf("Error: Can't access to \"%s.as\" . skipping it.\n", filename);
		free(input_file); /* The only allocated space is for the full file name */
		return FALSE;
	}
}

