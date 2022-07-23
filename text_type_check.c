#include "text_type_check.h"
#include "utils.h"
# define MAX_LABEL_LENGTH 30

char* directives[5] = { "data\0","string\0","struct\0","entry\0","extern\0" };
char* orders[16] = { "mov\0","cmp\0","add\0","sub\0","not\0","clr\0","lea\0","inc\0","dec\0","jmp\0","bne\0","get\0","prn\0","jsr\0","rts\0","hlt\0" };


struct instruction_name_value {
	char* name;
	char value;
};

typedef enum { DATA_LABEL, INSTRUCTION_LABEL, EXTERNAL_LABEL } lbltype;


static struct instruction_name_value
instruction_table[] = {
{"string", STR},
{"data",   DATA},
{"entry",  ENTRY},
{"struct",  STRUCT},
{"extern", EXTERN},
{NULL, NO}
};


typedef enum instruction {
	"data", "string", "struct", "entry", "extern", NULL
} instruction;


bool check_if_label(char* text) {
    /* Check if the first char is alpha, length less than 30, all the others are alphanumeric, and that the label doesnt already exsits*/
	bool bool_val;
	bool is_alphnumeric = true;
	int i;
		/*check each char in the string if it is non alphanumeric char*/
		for (i = 0; string[text+1]; i++) {
			if (!isalpha(string[i]) && !isdigit(string[i])) {
				is_alphnumeric = false;
				break;
			}
		}
    bool_val = text[0] && strlen(text) <= MAX_LABEL_LENGTH && isalpha(text[0]) && is_alphanumeric &&
        !is_reserved_word(text);
     return bool_val; 
}

bool check_if_instruction(char* text) {

}

