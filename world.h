//
//  world.h
//  testGame
//
//  Created by Nan Montaño on 04/abr/17.
//  Copyright © 2017 nancio. All rights reserved.
//

#ifndef world_h
#define world_h

#include "components.h"

#define ENTITY_COUNT 100

typedef struct {
    int mask[ENTITY_COUNT];
    Position position[ENTITY_COUNT];
    Velocity velocity[ENTITY_COUNT];
} World;

unsigned int new_entity(World *world);
void delete_entity(World *world, unsigned int entity);

#endif /* world_h */
