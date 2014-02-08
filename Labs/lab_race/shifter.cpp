/**
 * @file shifter.cpp
 */

#include <sstream>
#include "shifter.h"

/**
 * Makes an animation of an image shifting to the left
 * @param toShift - the image to be shifted
 * @return - an animation of the image being shifted
 */
animation Shifter::shiftSerial(const PNG & toShift)
{
    PNG image = toShift;
    animation anim;
    int width = image.width();
    int height = image.height();
    int shiftAmount = 32;

	// shift image to the left by 32 pixels each iteration
 
for(int destCol = 0; destCol < width; destCol += 32)
    {
        for(int x = 0; x < width - 32; ++x)
        {
            for(int y = 0; y < height; ++y)
            {
             	PNG temp=image;
		   *temp(x, y) = *temp(x + 32, y);
            }
        }
        if(destCol % shiftAmount == 0)
        {
            anim.addFrame(image);
        }
    }
    return anim;
}

/**
 * Makes an animation of an image shifting to the left
 * @param toShift - the image to be shifted
 * @return - an animation of the image being shifted
 */
animation Shifter::shiftParallel(const PNG & toShift)
{
    
 PNG image = toShift;
    animation anim;
    int width = image.width();
    int height = image.height();
    int shiftAmount = 32;

	  // shift image to the left by 32 pixels each iteration
  
	
  for(int destCol = 0; destCol < width; destCol += 32)
    {
        for(int x = 0; x < width - 32; ++x)
        {
	#pragma omp parallel for 
            for(int y = 0; y < height; ++y)
            {
                *image(x, y) = *image(x + 32, y);
            }
        }
        if(destCol % shiftAmount == 0)
        {
            anim.addFrame(image);
        }
    }
    

    return anim;
}

/**
 * Makes sure that the shifted.gif matches soln_shifted.gif
 * @return - whether all the frames match
 */
bool Shifter::checkCorrectness()
{
    size_t numFrames = 32; 
    for(size_t imgNum = 0; imgNum < numFrames; ++imgNum)
    {
        std::stringstream ss;
        ss << imgNum;
        string num = ss.str();
        if(num.size() == 1)
            num = "0" + num;
        PNG soln_img("soln_frames/shifted" + num + ".png");
        PNG img("frames/shifted" + num + ".png");
        if(soln_img != img)
        {
            cerr << "Frame " << num << " does not match" << endl;
            return false;
        }
    }
    return true;
}
