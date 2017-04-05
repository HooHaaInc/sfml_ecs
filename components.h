//
//  components.h
//  testGame
//
//  Created by Nan Montaño on 04/abr/17.
//  Copyright © 2017 nancio. All rights reserved.
//

#ifndef components_h
#define components_h

typedef struct {
    float x, y;
} Position;

typedef struct {
    float x, y;
} Velocity;

typedef enum {
    COMPONENT_NONE = 0,
    COMPONENT_POSITION = 1,
    COMPONENT_VELOCITY = 2
} Component;

#endif /* components_h */
