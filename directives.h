/*handles data,string,struct,extern, entry directives*/
#ifndef DIRECTIVES_HANDLER_H_
#define DIRECTIVES_HANDLER_H_

#include "word12.h"

word12* get_data_bin(void);
void handle_directive(char* pos, char* label, int* DC);
void reset_data_bin(void);

#endif /* DIRECTIVES_HANDLER_H_ */
