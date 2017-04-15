//
//  systems.c
//  testGame
//
//  Created by Nan Montaño on 04/abr/17.
//  Copyright © 2017 nancio. All rights reserved.
//

#include "systems.h"
#include "world.h"
#include "components.h"

bool _didCollide(Position *p1, Hitbox *h1, Position *p2, Hitbox *h2);
bool _willCollide(Position *p1, Velocity *v1, Hitbox *h1, Position *p2, Velocity *v2, Hitbox *h2);
void _stop(World *world, int entity);

void movement(World *world, sf::Time delta) {
    
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

void draw(World *world, sf::RenderWindow *window, sf::Time delta) {

    unsigned int entity;
    Position *pos;
    Drawable *dr;

    for (entity = 0; entity < ENTITY_COUNT; ++entity) {
        int hasPosition = world->mask[entity] & COMPONENT_POSITION;
        int hasDrawable = world->mask[entity] & COMPONENT_DRAWABLE;

        if (hasPosition && hasDrawable){

            pos = &world->position[entity];
            dr = &world->drawable[entity];

            dr->sp->setOrigin(pos->x, pos->y);

            window->draw(*dr->sp);
        }
    }
}

/**
 * Checa si donde se va a mover va a chocar, no donde se encuentra actualmente
 * @param world
 * @param delta
 */
void collision(World *world, sf::Time delta) {

    unsigned int entity;
    Position *pos, *pos2;
    Hitbox *hit, *hit2;
    Hurtbox *hurt, *hurt2;
    Velocity *vel, *vel2;

    for (entity = 0; entity < ENTITY_COUNT; ++entity) {
        int hasPosition = world->mask[entity] & COMPONENT_POSITION;
        int hasHitbox = world->mask[entity] & COMPONENT_HITBOX;
        int hasVelocity = world->mask[entity] & COMPONENT_VELOCITY;
        int hasHurtbox = world->mask[entity] & COMPONENT_HURTBOX;

        if (hasPosition && hasHitbox && hasVelocity) {

            pos = &world->position[entity];
            hit = &world->hitbox[entity];
            vel = &world->velocity[entity];
            hurt = hasHurtbox ? &world->hurtbox[entity] : NULL;

            // check for every other entity
            for (unsigned int entity2 = entity+1; entity2 < ENTITY_COUNT; ++entity2) {

                hasPosition = world->mask[entity2] & COMPONENT_POSITION;
                hasHitbox = world->mask[entity2] & COMPONENT_HITBOX;
                hasVelocity = world->mask[entity2] & COMPONENT_VELOCITY;
                hasHurtbox = world->mask[entity2] & COMPONENT_HURTBOX;

                if (hasPosition && hasHitbox){

                    pos2 = &world->position[entity2];
                    hit2 = &world->hitbox[entity2];
                    vel2 = hasVelocity ? &world->velocity[entity2] : NULL; // puede ser estatico
                    hurt2 = hasHurtbox ? &world->hurtbox[entity2] : NULL;

                    bool gotHurt = hurt && _willCollide(pos, vel, &hurt->box, pos2, vel2, hit2);
                    bool didHurt = hurt2 && _willCollide(pos, vel, hit, pos2, vel2, &hurt2->box);
                    bool hithit = _willCollide(pos, vel, hit, pos2, vel2, hit2);
                    if (gotHurt || didHurt || hithit){
                        // colision happened!

                        // default outcome: stop
                        _stop(world, entity);
                        _stop(world, entity2);
                    }
                }
            }
        }
    }
}

bool _willCollide(Position *p1, Velocity *v1, Hitbox *h1, Position *p2, Velocity *v2, Hitbox *h2){
    float l1 = p1->x + v1->x + h1->x, t1 = p1->y + v1->y + h1->y;
    float l2 = p2->x + v2->x + h2->x, t2 = p2->y + v2->y + h2->y;
    float r1 = l1 + h1->width, b1 = t1 + h1->height, r2 = l2 + h2->width, b2 = t2 + h2->height;

    bool _1isToTheLeftOf2 = r1 < l2;
    bool _1isToTheRightOf2 = l1 > r2;
    bool _1isAbove2 = b1 < t2;
    bool _1isBelow2 = t1 > b2;

    return !_1isToTheLeftOf2 && !_1isToTheRightOf2 && !_1isAbove2 && !_1isBelow2;
}

bool _didCollide(Position *p1, Hitbox *h1, Position *p2, Hitbox *h2){
    bool _1isToTheLeftOf2 = p1->x + h1->x + h1->width < p2->x + h2->x;
    bool _1isToTheRightOf2 = p1->x + h1->x > p2->x + h2->x + h2->width;
    bool _1isAbove2 = p1->y + h1->y + h1->height < p2->y + h2->y;
    bool _1isBelow2 = p1->y > p2->y + h2->y + h2->height;
    return !_1isToTheLeftOf2 && !_1isToTheRightOf2 && !_1isAbove2 && !_1isBelow2;
}

void _stop(World *world, int entity){

    Velocity *vel;
    int hasVelocity = world->mask[entity] & COMPONENT_VELOCITY;

    if (hasVelocity) {
        vel = &world->velocity[entity];
        vel->x = 0, vel->y = 0;
    }
}

void updateSprites(World *world, sf::Time delta) {

    unsigned int entity;
    Drawable *dr;
}
