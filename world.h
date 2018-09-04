#ifndef WORLD_H
#define WORLD_H
#include "buffer.h"
typedef struct world {
	buffer *curbuf;
} world;

world * World_Create(buffer * curbuf);
void World_Destroy(world * w);
#endif
