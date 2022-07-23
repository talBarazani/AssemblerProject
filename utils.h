#define MAX_LINE_LENGTH 80


struct line_details {
	int line_number;
	char *file_name;
};

char* cat_str(char* str0, char* str1);

void* check_malloc(long size);

bool is_reserved_word(char* name);

/*moves the index to the next place where the is no tab of white space*/
int move_white_space(int index, char* string);