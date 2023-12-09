#pragma once
#include "drawable.h"

///////////////////////////////////////   collidable classes   /////////////////////////////////
//Base class for all collidable (objects that may collide with other objects)
struct collisionInfo {
    bool collisionstate = true; // checks if a collision occurred
    point midpoint; // point of collition
};
class collidable :public drawable
{
public:
    collidable(point r_uprleft, int r_width, int r_height, game* r_pGame);
    friend collisionInfo checkCollision(const collidable* obj1, const collidable* obj2);
    virtual void collisionAction() = 0;    //action that should be performed upon collision

};
collisionInfo checkCollision(const collidable* obj1, const collidable* obj2) {
    collisionInfo details;

    point c1, c2;
    c1 = obj1->uprLft;
    c1.x += obj1->width / 2;
    c1.y += obj1->height / 2;
    c2 = obj2->uprLft;
    c2.x += obj2->width / 2;
    c2.y += obj2->height / 2;


    int D1 = ((c2.x - c1.x));
    int D2 = ((c2.y - c1.y));
    // calculate the minimum distance for collision (considering half the widths)
    double D1min = (obj1->width / 2) + (obj2->width / 2);
    // calculate the minimum distance for collision (considering half the heights)
    double D2min = (obj1->height / 2) + (obj2->height / 2);
    // Check for collision
    if (D1 <= D1min && D2 <= D2min) {
        details.collisionstate = true;
        // Calculate the midpoint of collision
        details.midpoint.x = (c1.x + c2.x) / 2;
        details.midpoint.y = (c1.y + c2.y) / 2;
    }
    else {
        details.collisionstate = false;
    }
    return details;
}