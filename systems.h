//
//  systems.h
//  testGame
//
//  Created by Nan Montaño on 04/abr/17.
//  Copyright © 2017 nancio. All rights reserved.
//

#ifndef systems_h
#define systems_h

#include <SFML/Graphics.hpp>
#include "world.h"

void movement(World *world, sf::Time delta);
void draw(World *world, sf::RenderWindow *window, sf::Time delta);
void collision(World *world, sf::Time delta);
void updateSprites(World *world, sf::Time delta);

#endif /* systems_h */
