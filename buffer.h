#ifndef BUFFER_H
#define BUFFER_H
#include <stdbool.h>
#include <stdlib.h>
#include "defines.h"
#include "modes.h"

typedef struct buffer {
	struct buffer *next_chain_entry;
	char buffer_name[BUFFERNAMEMAX];

	location point;
	location mark;
	location num_chars;
	int num_lines;
	int cur_line;

	storage *contents;

	char file_name[FILENAMEMAX];
	bool modified;

	mode *mode_list;
} buffer;

buffer *Buffer_Create(char *buffer_name);
status Buffer_Clear(buffer * buf);
status Buffer_Delete(buffer * buf);
status Buffer_Set_Name(buffer * buf, char *buffer_name);
char *Buffer_Get_Name(buffer * buf);
status Point_Set(buffer * buf, location loc);
status Point_Move(buffer * buf, int count);
location Point_Get(buffer * buf);
int Point_Get_Line(buffer * buf);
void Get_File_Name(buffer * buf, char *strbuffer, size_t strbufsize);
status Set_File_Name(buffer * buf, char *file_name);
status Buffer_Read(buffer * buf);
status Buffer_Write(buffer * buf);
void Forward_Char(buffer * buf);
void Backward_Char(buffer * buf);
#endif
