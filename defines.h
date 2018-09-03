#ifndef DEFINES_H
#define DEFINES_H
#include <limits.h>
#include <stdint.h>
#define FILENAMEMAX NAME_MAX + 1
#define BUFFERNAMEMAX 17
typedef struct {
	char *data;
	int buffersize;
} storage;

typedef int64_t location;

typedef enum {
	STAT_OK,
	STAT_FAIL
} status;
#endif
