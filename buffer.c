#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "modes.h"

/* Creates an empty buffer with the provided name. For now, a scratch buffer */
buffer *Buffer_Create(char *buffer_name)
{
	buffer *ret = calloc(1, sizeof(buffer));
	Buffer_Set_Name(ret, buffer_name);
	ret->modified = false;
	Buffer_Clear(ret);
	return ret;
}

status Buffer_Clear(buffer * buf)
{
	buf->cur_line = buf->num_chars = buf->num_lines = buf->point = 0;
	buf->mark = -1;
	if (buf->contents != NULL) {
		free(buf->contents->data);
		free(buf->contents);
	}
	if (buf->mode_list != NULL) {
		Modelist_Del(buf->mode_list);
	}
	buf->contents = calloc(1, sizeof(storage));
	buf->contents->data = calloc(10, 1);
	buf->contents->buffersize = 10;
	return STAT_OK;
}

status Buffer_Delete(buffer * buf)
{
	/* Take the buffer out of the chain */
	if (buf->next_chain_entry != NULL) {
		buffer *updated_ptr = NULL;
		buffer *cbuf = buf;
		while (updated_ptr != buf) {
			cbuf = cbuf->next_chain_entry;
			updated_ptr = cbuf->next_chain_entry;
		}
		cbuf->next_chain_entry = buf->next_chain_entry;
	}
	/* Free members, then the buffer proper */
	if (buf->contents != NULL) {
		free(buf->contents->data);
		free(buf->contents);
	}
	if (buf->mode_list != NULL) {
		Modelist_Del(buf->mode_list);
	}
	free(buf);
	return STAT_OK;
}

status Buffer_Set_Name(buffer * buf, char *buffer_name)
{
	buf->buffer_name[0] = '\0';
	strncat(buf->buffer_name, buffer_name, BUFFERNAMEMAX);
	return STAT_OK;
}

char *Buffer_Get_Name(buffer * buf)
{
	return buf->buffer_name;
}

#define BOUNDS_FIX(bf) if (bf->point < 0) bf->point=0; else if (bf->point>=bf->num_chars) bf->point=bf->num_chars-1

status Point_Set(buffer * buf, location loc)
{
	buf->point = loc;
	BOUNDS_FIX(buf);
	return STAT_OK;
}

status Point_Move(buffer * buf, int count)
{
	buf->point += count;
	BOUNDS_FIX(buf);
	return STAT_OK;
}

location Point_Get(buffer * buf)
{
	return buf->point;
}

int Point_Get_Line(buffer * buf)
{
	return buf->cur_line;
}

void Get_File_Name(buffer * buf, char *strbuffer, size_t strbufsize)
{
	strbuffer[0] = '\0';
	strncat(strbuffer, buf->file_name, strbufsize);
}

status Set_File_Name(buffer * buf, char *file_name)
{
	buf->file_name[0] = '\0';
	strncat(buf->file_name, file_name, BUFFERNAMEMAX);
	return STAT_OK;
}

status Buffer_Read(buffer * buf)
{
	status ret = STAT_OK;
	Buffer_Clear(buf);

	/* Actually open the happy chappy up */
	FILE *fi = fopen(buf->file_name, "r");
	if (fi == NULL)
		return STAT_FAIL;

	/* Go to eof */
	if (fseek(fi, 0L, SEEK_END)) {
		ret = STAT_FAIL;
		goto cleanup;
	}

	/* Get filesize */
	long bufsize = ftell(fi);
	if (bufsize == -1) {
		ret = STAT_FAIL;
		goto cleanup;
	}

	/* Expand the buffer as such */
	buf->contents->buffersize = bufsize + 11;
	buf->contents->data = realloc(buf->contents->data, buf->contents->buffersize);

	/* Go to bof */
	if (fseek(fi, 0L, SEEK_SET)) {
		ret = STAT_FAIL;
		goto cleanup;
	}

	/* Read the file into memory */
	buf->num_chars = fread(buf->contents->data, 1, bufsize, fi);

	/* Clean up and return */
	if (ferror(fi))
		ret = STAT_FAIL;
 cleanup:
	fclose(fi);
	return ret;
}

status Buffer_Write(buffer * buf)
{
	FILE *fi = fopen(buf->file_name, "w");
	if (fi == NULL)
		return STAT_FAIL;

	for (int i = 0; i < buf->num_chars; i++) {
		fputc(buf->contents->data[i], fi);
	}

	fclose(fi);
	return STAT_OK;
}

void Forward_Char(buffer * buf)
{
	Point_Move(buf, 1);
}

void Backward_Char(buffer * buf)
{
	Point_Move(buf, -1);
}
