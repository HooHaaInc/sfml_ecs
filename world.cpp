//
//  world.c
//  testGame
//
//  Created by Nan Montaño on 04/abr/17.
//  Copyright © 2017 nancio. All rights reserved.
//

#include <stdio.h>
#include "world.h"

unsigned int new_entity(World *world){
    unsigned int entity;
    for(entity = 0; entity < ENTITY_COUNT; ++entity){
        if(world->mask[entity] == COMPONENT_NONE){
            return entity;
        }
    }
    
    printf("Error!  No more entities left!\n");
    return -1;
}

void delete_entity(World *world, unsigned int entity){
    world->mask[entity] = COMPONENT_NONE;
}
