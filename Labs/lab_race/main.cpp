/**
 * @file main.cpp
 * @date Spring 2012
 * @author Sean Massung 
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <omp.h>

#include "png.h"
#include "collage.h"
#include "table.h"
#include "flipper.h"
#include "animation.h"
#include "shifter.h"

#define NUM_COLLAGE_FILES 12

using std::vector;
using std::cout;
using std::endl;

/**
 * Turns a string green!
 * @param str - the string to change
 * @return the changed string
 */
inline string makeGreen(string str)
{
    return "\033[1;32m" + str + "\033[0m";
}

/**
 * Turns a string red to indicate you done wrong
 * @param str - the string to change
 * @return the angry string
 */
inline string makeRed(string str)
{
    return "\033[1;31m" + str + "\033[0m";
}

/**
 * Initializes the vector of PNGs for the collage constructor.
 * @return - a vector of PNGs representing layers in the collage
 */
vector<PNG> setupImages()
{
    vector<PNG> layers;
    string filenames[NUM_COLLAGE_FILES] = { "01_8182x4096.png", "02_5000x3750.png",
        "03_2560x1680.png", "04_1920x1200.png", "05_1680x1050.png",
        "06_1440x900.png", "07_1280x1024.png", "08_1024x768.png",
        "09_600x400.png", "10_300x200.png", "11_150x100.png", "12_50x50.png" };
    for(int i = 0; i < NUM_COLLAGE_FILES; ++i)
    {
        cout << "  - loading image " << i << endl;
        PNG png;
        png.readFromFile("images/" + filenames[i]);
        layers.push_back(png);
    }
    return layers;
}

/**
 * Initializes the vector of Points for the collage constructor.
 * @return - a vector of Points where each image will be relative in the collage
 */
vector<Point> setupPoints()
{
    int coords[NUM_COLLAGE_FILES][2] = { {0, 0}, {100, 100}, {200, 200}, {300, 500}, {800, 1000}, {0, 2000},
        {3000, 1000}, {4000, 300}, {300, 700}, {700, 300}, {0, 0}, {8000, 4000} };
    vector<Point> points;
    for(int i = 0; i < NUM_COLLAGE_FILES; ++i)
    {
        Point p(coords[i][0], coords[i][1]);
        points.push_back(p);
    }
    return points;
}

/**
 * Tests the multiplication table code.
 */
void testTable()
{
    int width = 9001;
    int height = 9001;
    int** table = new int*[width];
    cout << "Testing multiplication table:" << endl;
    for(int i = 0; i < width; ++i)
        table[i] = new int[height];

    // initially set all memory to zero
    for(int i = 0; i < width; ++i)
        for(int j = 0; j < height; ++j)
            table[i][j] = 0;

    // run serial version
    double startTime = omp_get_wtime();
    MultTable::findProductsSerial(table, width, height, false);
    double endTime = omp_get_wtime();
    double serialTime = endTime - startTime;

    cout << "  - calculating products" << endl;
    startTime = omp_get_wtime();
    MultTable::findProductsParallel(table, width, height, true);
    endTime = omp_get_wtime();
    double parallelTime = endTime - startTime;

    cout << "Checking correctness: ";
    bool correct = MultTable::checkTable(table, width, height);
    cout << (correct ? makeGreen("PASS") : makeRed("FAIL")) << endl;

    cout << "Elapsed table creation time: " << parallelTime << endl;
    cout << "Speedup: " << serialTime / parallelTime << endl;

    for(int i = 0; i < width; ++i)
        delete table[i];
    delete [] table;
}

/**
 * Tests the collage code with the appropriate algorithm.
 */
void testCollage(DrawAlgorithm algorithm)
{
    cout << "Testing collage:" << endl;
    vector<PNG> layers = setupImages();
    vector<Point> coords = setupPoints();
    Collage collage(layers, coords);

    double startTime = omp_get_wtime();
    PNG* result = collage.draw(algorithm, true);
    double endTime = omp_get_wtime();
    double parallelTime = endTime - startTime;

    cout << "  - saving image" << endl;
    result->writeToFile("collage.png");    
    cout << "Elapsed collage time: " << parallelTime << endl;

    cout << "Checking correctness: ";
    bool correct = collage.checkCorrectness(*result);
    cout << (correct ? makeGreen("PASS") : makeRed("FAIL") + " (the images are different)") << endl;
    delete result;

    startTime = omp_get_wtime();
    result = collage.draw(algorithm, false);
    endTime = omp_get_wtime();
    cout << "Speedup: " << (endTime - startTime) / parallelTime << endl;
    delete result;
}

/**
 * Tests the serial collage code.
 */
void testCollageCoordsSerial()
{
    cout << "Testing collage by coordinates in serial:" << endl;
    vector<PNG> layers = setupImages();
    vector<Point> coords = setupPoints();
    Collage collage(layers, coords);
    DrawAlgorithm algorithm = byCoordinates;

    double startTime = omp_get_wtime();
    PNG* result = collage.draw(algorithm, false);
    double endTime = omp_get_wtime();

    cout << "  - saving image" << endl;
    result->writeToFile("collage.png");    
    cout << "Elapsed collage time: " << endTime - startTime << endl;

    cout << "Checking correctness: ";
    bool correct = collage.checkCorrectness(*result);
    cout << (correct ? makeGreen("PASS") : makeRed("FAIL") + " (the images are different)") << endl;
    delete result;
}

/**
 * Tests the collage code with the layers algorithm.
 */
void testCollageLayers()
{
    DrawAlgorithm algorithm = byLayers;
    testCollage(algorithm);
}

/**
 * Tests the collage code with the coordinates algorithm.
 */
void testCollageCoords()
{
    DrawAlgorithm algorithm = byCoordinates;
    testCollage(algorithm);
}
/**
 * Tests the image flipping code.
 */
void testFlip()
{
    PNG image;
    cout << "Testing in-place image flipper:" << endl;
    image.readFromFile("images/03_2560x1680.png");

    cout << "  - flipping image" << endl;
    double startTime = omp_get_wtime();
    Flipper::flipParallel(image);
    double endTime = omp_get_wtime();
    double parallelTime = endTime - startTime;

    cout << "  - saving image" << endl;
    image.writeToFile("flipped.png");
    cout << "Elapsed flip time: " << parallelTime << endl;

    cout << "Checking correctness: ";
    bool correct = Flipper::checkCorrectness(image);
    cout << (correct ? makeGreen("PASS") : makeRed("FAIL") + " (the images are different)") << endl;

    startTime = omp_get_wtime();
    Flipper::flipSerial(image);
    endTime = omp_get_wtime();
    cout << "Speedup: " << (endTime - startTime) / parallelTime << endl;
}

/**
 * Tests the image shifting code
 */
void testShift()
{
    // remove old frames
    system("rm -rf frames 2> /dev/null");

    PNG image;
    cout << "Testing image shifter:" << endl;
    image.readFromFile("images/08_1024x768.png");

    cout << "  - shifting image" << endl;
    double startTime = omp_get_wtime();
    animation anim = Shifter::shiftParallel(image);
    double endTime = omp_get_wtime();
    double parallelTime = endTime - startTime;

    cout << "  - saving image" << endl;
    anim.write("shifted.gif");
    cout << "Elapsed shifting time: " << parallelTime << endl;

    cout << "Checking correctness: ";
    bool correct = Shifter::checkCorrectness();
    cout << (correct ? makeGreen("PASS") : makeRed("FAIL") + " (the images are different)") << endl;

    // remove old frames
    system("rm -rf frames 2> /dev/null");

    // calculate speedup
    startTime = omp_get_wtime();
    anim = Shifter::shiftSerial(image);
    endTime = omp_get_wtime();

    cout << "Speedup: " << (endTime - startTime) / parallelTime << endl;
}

/**
 * Show how to use the program's command line arguments.
 */
void printUsage(string programName)
{
    cout << "Usage: " << programName << " test [test [test [...] ] ] where test is" << endl;
    cout << "    table          - test multiplication table; this will print the table to stdout" << endl;
    cout << "    flip           - test image flipper; the image is saved as flipped.png" << endl;
    cout << "    shift          - test image shifter; the image is saved as shifted.gif" << endl;
    cout << "    collage-layers - test collage drawn by layers; the collage is saved as collage.png" << endl;
    cout << "    collage-coords-serial - test collage drawn by coordinates; the collage is saved as collage.png" << endl;
    cout << "    collage-coords - test collage drawn by coordinates; the collage is saved as collage.png" << endl;
    cout << "    all            - run all tests" << endl;
    cout << "Example: " << programName << " flip table" << endl;
}

/**
 * Parse command line arguments and run tests accordingly.
 */
int main(int argc, char* argv[])
{
    omp_set_num_threads(8);
    vector<string> args(argv + 1, argv + argc);

    if(args.size() == 0)
    {
        printUsage(argv[0]);
        return 1;
    }

    bool all = (find(args.begin(), args.end(), "all")  != args.end());
    bool ranOne = false;
    
    if(all || find(args.begin(), args.end(), "table") != args.end())
    {
        testTable();
        ranOne = true;
    }
    if(all || find(args.begin(), args.end(), "flip") != args.end())
    {
        testFlip();
        ranOne = true;
    }
    if(all || find(args.begin(), args.end(), "shift") != args.end())
    {
        testShift();
        ranOne = true;
    }
    if(all || find(args.begin(), args.end(), "collage-layers") != args.end())
    {
        testCollageLayers();
        ranOne = true;
    }
    if(all || find(args.begin(), args.end(), "collage-coords") != args.end())
    {
        testCollageCoords();
        ranOne = true;
    }
    if(all || find(args.begin(), args.end(), "collage-coords-serial") != args.end())
    {
        testCollageCoordsSerial();
        ranOne = true;
    }
    if(!ranOne)
    {
        printUsage(argv[0]);
        return 1;
    }
    return 0;
}
