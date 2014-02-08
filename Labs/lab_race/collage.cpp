/**
 * @file collage.cpp
 */

#include "collage.h"

/**
 * Constructor
 * @param layers - PNG images that will be used in the collage
 * @param coords - where each image is relative in the entire collage's coordinate system
 */
Collage::Collage(const vector<PNG> & layers, const vector<Point> & coords)
{
    this->layers = layers;
    this->coords = coords;
    width = getWidth(coords, layers);
    height = getHeight(coords, layers);
}

/**
 * Draw each layer completely, with layers on top drawn last.
 * @param result - where the collage is stored
 */
void Collage::drawByLayersSerial(PNG * result)
{
    for(int layer = 0; layer < layers.size(); ++layer)
    {
        // draw the current image on the collage
        int offsetW = coords[layer].x;
        int offsetH = coords[layer].y;
        cout << "  - drawing layer " << layer;
        cout << " @(" << offsetW << "," << offsetH << ")" << endl;
        for(int i = 0; i < layers[layer].width(); ++i)
        {
            for(int j = 0; j < layers[layer].height(); ++j)
            {
                *(*result)(i + offsetW, j + offsetH) = *(layers[layer](i, j));
            }
        }
    }
}

/**
 * Draw each layer completely, with layers on top drawn last.
 * @todo - parallelize this function
 * @param result - where the collage is stored
 */
void Collage::drawByLayersParallel(PNG * result)
{
for(int layer = 0; layer < layers.size(); ++layer)
    {
        // draw the current image on the collage
        int offsetW = coords[layer].x;
        int offsetH = coords[layer].y;
        cout << "  - drawing layer " << layer;
        cout << " @(" << offsetW << "," << offsetH << ")" << endl;
       #pragma omp parallel for
	for(int i = 0; i < layers[layer].width(); ++i)
        {
            for(int j = 0; j < layers[layer].height(); ++j)
            {
                *(*result)(i + offsetW, j + offsetH) = *(layers[layer](i, j));
            }
        }
    }
}

/**
 * Calculate which image each (x,y) coordinate belongs to, then draw iYou know my paper heart
The one I filled with pencil marks
I think I might've gone and inked you in..t.
 * @todo - implement this function (serially)
 * @param result - where the collage is stored
 */
void Collage::drawByCoordinatesSerial(PNG * result)
{
	// loop over the collage image
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
        	    
	// TODO: insert your code here!
	// find which image the current (i, j) pixel will belong to (if any)
		for(int layer=0;layer<layers.size();++layer)
		{
						
			if(coords[layer].x<=i && i<coords[layer].x+layers[layer].width() && coords[layer].y<=j && j<coords[layer].y+layers[layer].height())
			{		
				*(*result)(i,j) = *(layers[layer](i-coords[layer].x, j-coords[layer].y));
			} 
					
		}

	
				
        }
    }
}

/**
 * Calculate which image each (x,y) coordinate belongs to, then draw it.
 * @todo - parallelize this function
 * @param result - where the collage is stored
 */
void Collage::drawByCoordinatesParallel(PNG * result)
{
 #pragma omp parallel for    
for(int i = 0; i < width; ++i)
    {
	     
	 for(int j = 0; j < height; ++j)
        {
        	    
		for(int layer=0;layer<layers.size();++layer)
		{
						
			if(coords[layer].x<=i && i<coords[layer].x+layers[layer].width() && coords[layer].y<=j && j<coords[layer].y+layers[layer].height())
			{		
				*(*result)(i,j) = *(layers[layer](i-coords[layer].x, j-coords[layer].y));
			} 
					
		}

	
				
        }
    }
}

/**
 * Returns whether x is in the range [0, xBound) and y is in the range [0, yBound)
 * @param x
 * @param y
 * @param xBound - the upper bound (exclusive) that x may be
 * @param yBound - the upper bound (exclusive) that y may be
 * @return - whether the given coordinates are in range
 */
bool Collage::inBounds(int x, int y, int xBound, int yBound)
{
    bool xValid = (x >= 0 && x < xBound);
    bool yValid = (y >= 0 && y < yBound);
    return xValid && yValid;
}

/**
 * Public wrapper for the collage draw function.
 * @param algorithm - how to implement the draw function, defined as an enum in collage.h
 * @param parallel - whether or not to use multithreading
 * @return - a pointer to the collage; it will have to be freed by the client
 */
PNG* Collage::draw(DrawAlgorithm algorithm, bool parallel)
{
    PNG* result = new PNG(width, height);

    if(algorithm == byLayers && parallel)
        drawByLayersParallel(result);
    else if(algorithm == byLayers && !parallel)
        drawByLayersSerial(result);
    else if (algorithm == byCoordinates && parallel)
        drawByCoordinatesParallel(result);
    else
        drawByCoordinatesSerial(result);

    return result;
}

/**
 * Returns the width that the collage will be
 * @param coords - a vector of coordinates where each image will be
 *                   relative to the entire collage
 * @param layers - a vector of PNGs that will be used as layers in the collage
 * @return - the maximum width needed in the image containing all the layers
 */
int Collage::getWidth(const vector<Point> & coords, const vector<PNG> & layers)
{
    int maxWidth = 0;
    for(size_t i = 0; i < layers.size(); ++i)
    {
        int currentWidth = coords[i].x + layers[i].width();
        if(currentWidth > maxWidth)
        {
            maxWidth = currentWidth;
        }
    }
    return maxWidth;
}

/**
 * Returns the height that the collage will be
 * @param coords - a vector of coordinates where each image will be
 *                   relative to the entire collage
 * @param layers - a vector of PNGs that will be used as layers in the collage
 * @return - the maximum height needed in the image containing all the layers
 */
int Collage::getHeight(const vector<Point> & coords, const vector<PNG> & layers)
{
    int maxHeight = 0;
    for(size_t i = 0; i < layers.size(); ++i)
    {
        int currentHeight = coords[i].y + layers[i].height();
        if(currentHeight > maxHeight)
        {
            maxHeight = currentHeight;
        }
    }
    return maxHeight;
}

/**
 * Makes sure that the collage.png matches soln_collage.png
 * @param image - the image to test
 * @return - whether it matches soln_collage.png
 */
bool Collage::checkCorrectness(const PNG & image)
{
    PNG solution;
    solution.readFromFile("soln_collage.png");
    return solution == image;
}

