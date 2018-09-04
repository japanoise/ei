#include "buffer.h"
typedef struct world {
	buffer *curbuf;
} world;

world *World_Create(buffer * curbuf) {
	world * ret = malloc(sizeof(world));
	ret->curbuf = curbuf;
	return ret;
}

void World_Destroy(world * w) {
	buffer *firstbuf = w->curbuf;
	do {
		buffer *next = w->curbuf->next_chain_entry;
		if (w->curbuf->contents != NULL) {
			free(w->curbuf->contents->data);
			free(w->curbuf->contents);
		}
		if (w->curbuf->mode_list != NULL) {
			Modelist_Del(w->curbuf->mode_list);
		}
		free(w->curbuf);
		w->curbuf = next;
	} while(w->curbuf != NULL && w->curbuf!=firstbuf);

	free(w);
}
