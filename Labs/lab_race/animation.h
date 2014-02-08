/**
 * @file animation.h
 * This is the same gif creation library that we use in MP4. It is used to
 * create the shifting animation. You do not need to edit these files.
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <vector>
#include "png.h"

using namespace std;

/**
 * Creates an animation out of PNG objects.
 */
class animation {
  public:

    /**
     * Adds a frame to the animation.
     * @param img - the image to add to the animation
     */
    void addFrame(PNG const & img);

    /**
     * Saves the animation as a .gif.
     * @param filename - the filename to save the animation as.
     */
    void write(std::string filename);

  private:
    std::vector<PNG> frames;

	template <typename T>
	string to_string(const T & value);
	string getString(int i, int padToSameLengthAs);
	bool exists(const string & path);
};

#endif
