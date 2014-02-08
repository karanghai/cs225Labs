/**
 * @file collage.h
 * This is a simple class that holds the Collage implementation code. It is your
 *  job to write the draw function.  
 * You should only have to edit collage.cpp. 
 */

#ifndef _COLLAGE_H_
#define _COLLAGE_H_

#include <iostream>
#include <vector>
#include <string>
#include "png.h"
#include "point.h"

using std::cout;
using std::endl;
using std::vector;

/**
 * Distinguishes between the two ways of drawing a Collage.
 */
enum DrawAlgorithm { byLayers, byCoordinates };

/**
 * Represents a collection of images at predetermined (x,y) coordinates. 
 */
class Collage
{
    public:
        /**
         * Constructor
         * @param layers - PNG images that will be used in the collage
         * @param coords - where each image is relative in the entire collage's
         *   coordinate system
         */
        Collage(const vector<PNG> & layers, const vector<Point> & coords);

        /**
         * Public wrapper for the collage draw function.
         * @param algorithm - how to implement the draw function, defined as an
         *   enum in collage.h
         * @param parallel - whether or not to use multithreading
         * @return - a pointer to the collage; it will have to be freed by
         *   the client
         */
        PNG* draw(DrawAlgorithm algorithm, bool parallel);

        /**
         * Makes sure that the collage.png matches soln_collage.png
         * @param image - the image to test
         * @return - whether it matches soln_collage.png
         */
        bool checkCorrectness(const PNG & image);

    private:

        int width;
        int height;

        vector<Point> coords;
        vector<PNG> layers;

        /**
         * Draw each layer completely, with layers on top drawn last.
         * @param result - where the collage is stored
         */
        void drawByLayersSerial(PNG * result);
        
        /**
         * Draw each layer completely, with layers on top drawn last.
         */
        void drawByLayersParallel(PNG * result);

        /**
         * Calculate which image each (x,y) coordinate belongs to, then draw it.
         */
        void drawByCoordinatesSerial(PNG * result);

        /**
         * Calculate which image each (x,y) coordinate belongs to, then draw it.
         */
        void drawByCoordinatesParallel(PNG * result);

        /**
         * Returns whether x is in the range [0, xBound) and y is in the
         *   range [0, yBound)
         * @param x
         * @param y
         * @param xBound - the upper bound (exclusive) that x may be
         * @param yBound - the upper bound (exclusive) that y may be
         * @return - whether the given coordinates are in range
         */
        bool inBounds(int x, int y, int xBound, int yBound);

        /**
         * Returns the width that the collage will be
         * @param coords - a vector of coordinates where each image will be
         *   relative to the entire collage
         * @param layers - a vector of PNGs that will be used as layers in the
         *   collage
         * @return - the maximum width needed in the image containing all the
         *   layers
         */
        int getWidth(const vector<Point> & coords, const vector<PNG> & layers);

        /**
         * Returns the height that the collage will be
         * @param coords - a vector of coordinates where each image will be
         *   relative to the entire collage
         * @param layers - a vector of PNGs that will be used as layers in the
         *   collage
         * @return - the maximum height needed in the image containing all the
         *   layers
         */
        int getHeight(const vector<Point> & coords, const vector<PNG> & layers);
};

#endif
