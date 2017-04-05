//
//  systems.c
//  testGame
//
//  Created by Nan Montaño on 04/abr/17.
//  Copyright © 2017 nancio. All rights reserved.
//

#include "systems.h"

void movement(World *world){
    
    unsigned int entity;
    Position *pos;
    Velocity *vel;
    
    for (entity=0; entity < ENTITY_COUNT; ++entity) {
        int hasPosition = world->mask[entity] & COMPONENT_POSITION;
        int hasVelocity = world->mask[entity] & COMPONENT_VELOCITY;
        
        if (hasPosition && hasVelocity){
            pos = &world->position[entity];
            vel = &world->velocity[entity];
            
            pos->x += vel->x;
            pos->y += vel->y;
        }
    }
}
