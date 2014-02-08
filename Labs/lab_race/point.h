/**
 * @file point.h
 * This is a simple Point class that is used in the collage creation.
 * You do not need to edit these files.
 */

#ifndef _POINT_H_
#define _POINT_H_

/**
 * Simply represents a Point in 2D space.
 */
class Point
{
public:

    int x;
    int y;

    /**
     * Constructor.
     * @param x The x value to set
     * @param y The y value to set
     */
    Point(int x, int y);
    
    /**
     * Default, no argument constructor.
     */
    Point();
};

#endif
