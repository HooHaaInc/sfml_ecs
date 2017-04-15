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
#define EVENT_BUFFER_SIZE 10

typedef enum {
    EVENT_NULL
} GameEventType;

typedef struct {
    GameEventType type;
    // events args, description, etc.
} GameEvent;

typedef struct {
    int mask[ENTITY_COUNT];
    Position position[ENTITY_COUNT];
    Velocity velocity[ENTITY_COUNT];
    Drawable drawable[ENTITY_COUNT];
    Hitbox hitbox[ENTITY_COUNT];
    Hurtbox hurtbox[ENTITY_COUNT];
    AnimationStrip animationStrip[ENTITY_COUNT];

    GameEvent eventBuffer[EVENT_BUFFER_SIZE];
    int ev0, evlength;
} World;




unsigned int new_entity(World *world);
void delete_entity(World *world, unsigned int entity);
void queue_event(World *world, GameEvent ev);
GameEvent unqueue_event(World *world);

#endif /* world_h */
