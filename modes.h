#ifndef MODES_H
#define MODES_H
typedef struct mode {
	struct mode *next_mode;
	char *mode_name;
} mode;

void Modelist_Del(mode * mode_list);
#endif
