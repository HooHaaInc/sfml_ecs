//
//  world.c
//  testGame
//
//  Created by Nan Montaño on 04/abr/17.
//  Copyright © 2017 nancio. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include "world.h"

unsigned int new_entity(World *world){
    unsigned int entity;
    for(entity = 0; entity < ENTITY_COUNT; ++entity){
        if(world->mask[entity] == COMPONENT_NONE){
            return entity;
        }
    }
    
    printf("Error!  No more entities left!\n");
    return ENTITY_COUNT;
}

void delete_entity(World *world, unsigned int entity){
    if (world->mask[entity] & COMPONENT_DRAWABLE){
        free(world->drawable[entity].sp);
    }
    world->mask[entity] = COMPONENT_NONE;
}

void queue_event(World *world, GameEvent ev) {
    if (world->evlength == EVENT_BUFFER_SIZE){
        printf("! event buffer full");
        return;
    }
    int index = (world->ev0 + world->evlength)%EVENT_BUFFER_SIZE;
    world->eventBuffer[index] = ev;
    world->evlength++;
}

GameEvent unqueue_event(World *world){
    if (world->evlength == 0) throw "No events queued";
    GameEvent ev = world->eventBuffer[world->ev0];
    world->ev0 = (world->ev0+1)%EVENT_BUFFER_SIZE;
    world->evlength--;
    return ev;
}
