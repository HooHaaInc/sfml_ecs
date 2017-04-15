//
//  components.h
//  testGame
//
//  Created by Nan Montaño on 04/abr/17.
//  Copyright © 2017 nancio. All rights reserved.
//

#ifndef components_h
#define components_h

#include <SFML/Graphics.hpp>

typedef struct {
    float x, y;
} Position;

typedef struct {
    float x, y;
} Velocity;

typedef struct {
    sf::Sprite *sp;
} Drawable;

typedef struct {
    float x, y;
    float width, height;
} Hitbox;

typedef struct {
    Hitbox box;
    bool hitable;
} Hurtbox;

typedef struct {
    sf::Sprite **sprites; // array of sprite strips
    Hitbox **hitboxes; // hitbox for each frame in each strip
} AnimationStrip;

typedef enum {
    COMPONENT_NONE = 0,
    COMPONENT_POSITION = 1,
    COMPONENT_VELOCITY = 1 << 1,
    COMPONENT_DRAWABLE = 1 << 2,
    COMPONENT_HITBOX = 1 << 3,
    COMPONENT_HURTBOX = 1 << 4,
    COMPONENT_ANIMATIONSTRIP = 1 << 5
} Component;

#endif /* components_h */
