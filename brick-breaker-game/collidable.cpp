#include "collidable.h"
#include <cmath> 

collidable::collidable(point r_uprleft, int r_width, int r_height, game* r_pGame):
			drawable(r_uprleft, r_width, r_height,  r_pGame)
{
}

collisionInfo checkCollision(const collidable* obj1, const collidable* obj2) {
    collisionInfo details;

    // Calculate centers of the objects
    point center1 = { obj1->uprLft.x + obj1->width / 2.0, obj1->uprLft.y + obj1->height / 2.0 };
    point center2 = { obj2->uprLft.x + obj2->width / 2.0, obj2->uprLft.y + obj2->height / 2.0 };

    // Calculate half-widths and half-heights
    double halfWidth1 = obj1->width / 2.0;
    double halfHeight1 = obj1->height / 2.0;
    double halfWidth2 = obj2->width / 2.0;
    double halfHeight2 = obj2->height / 2.0;

    // Calculate the distance between centers
    double distanceX = std::abs(center2.x - center1.x);
    double distanceY = std::abs(center2.y - center1.y);

    // Calculate the minimum distance for collision
    double minDistanceX = halfWidth1 + halfWidth2;
    double minDistanceY = halfHeight1 + halfHeight2;

    // Check for collision
    if (distanceX <= minDistanceX && distanceY <= minDistanceY) {
        details.collided = true;

        // Calculate the midpoint of collision
        details.midpoint.x = (center1.x + center2.x) / 2.0;
        details.midpoint.y = (center1.y + center2.y) / 2.0;
    }
    else {
        details.collided = false;
    }
    return details;
}

//collisionInfo checkCollision(const collidable* obj1, const collidable* obj2) {
//    collisionInfo details;
//
//    point c1, c2;
//    c1 = obj1->uprLft;
//    c1.x += obj1->width / 2;
//    c1.y += obj1->height / 2;
//    c2 = obj2->uprLft;
//    c2.x += obj2->width / 2;
//    c2.y += obj2->height / 2;
//
//
//    int D1 = ((c2.x - c1.x));
//    int D2 = ((c2.y - c1.y));
//    // calculate the minimum distance for collision (considering half the widths)
//    double D1min = (obj1->width / 2) + (obj2->width / 2);
//    // calculate the minimum distance for collision (considering half the heights)
//    double D2min = (obj1->height / 2) + (obj2->height / 2);
//    // Check for collision
//    if (D1 <= D1min && D2 <= D2min) {
//        details.collided = true;
//        // Calculate the midpoint of collision
//        details.midpoint.x = (c1.x + c2.x) / 2;
//        details.midpoint.y = (c1.y + c2.y) / 2;
//    }
//    else {
//        details.collided = false;
//    }
//    return details;
//}
