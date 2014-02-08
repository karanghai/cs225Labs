#include <cstdlib>
#include "png.h"
#include <iostream>//added statements for the use of cout
using namespace std;
// sets up the output image
PNG * setupOutput(int w, int h);

// Returns my favorite color
RGBAPixel * myFavoriteColor(int intensity);

int main()
{
	// Load in.png
	PNG * original;
	cout << "Reached line 14" << endl;//added line
	original=new PNG;	
	original->readFromFile("in.png");
	int width  = original->width();
	int height = original->height();
	cout << "Reached line 18" << endl;//added line
	// Create out.png
	PNG * output;
	output=setupOutput(width, height);//output= edit	

	// Loud our favorite color to color the outline
	RGBAPixel * myPixel = myFavoriteColor(192);

	// Go over the whole image, and if a pixel differs from that to its upper
	// left, color it my favorite color in the output
	for (int y = 1; (0 < y) && (y < height); y++)//changed 0<y<height
	{
		for (int x = 1; (0 < x) && (x < width); x++)//changed 0<x<width
		{	
			// Calculate the pixel difference
			RGBAPixel * prev = (*original)(x-1, y-1);
			RGBAPixel * curr = (*original)(x  , y  );
			int diff = abs(curr->red   - prev->red  ) +
					   abs(curr->green - prev->green) +
					   abs(curr->blue  - prev->blue );
			
			// If the pixel is an edge pixel,
			// color the output pixel with my favorite color
			RGBAPixel * currOutPixel = (*output)(x,y);
			if (diff > 100)
				*currOutPixel = *myPixel;
		}
	}
	
	// Save the output file
	output->writeToFile("out.png");

	// Clean up memory
	delete myPixel;
	delete output;
	delete original;
	return 0;
}


// sets up the output image
PNG * setupOutput(int w, int h)
{
	PNG * image = new PNG(w, h);
	return image;
}


// Returns my favorite color
RGBAPixel * myFavoriteColor(int intensity)
{
	RGBAPixel *color= new RGBAPixel;
	color->red   = 0;
	color->green = intensity/2;
	color->blue  = intensity;
	return color;
	
}

