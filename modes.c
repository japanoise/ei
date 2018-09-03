#include <stdlib.h>
#include "modes.h"

void Modelist_Del(mode * mode_list)
{
	while (mode_list != NULL) {
		mode *next = mode_list->next_mode;
		free(mode_list->mode_name);
		free(mode_list);
		mode_list = next;
	}
}
