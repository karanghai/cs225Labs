/**
 * @file main.cpp
 * This is the code that will test your functions.
 * @author Sean Massung
 * @date Spring 2012
 */

#include <iostream>
#include <omp.h>
#include <string>
#include "image_tools.h"
#include "png.h"

using std::cout;
using std::endl;
using std::string;

/**
 * Simply parses the command line args and runs the appropriate functions.
 */
int main(int argc, char* argv[]){

    if(argc != 5)
    {
        cerr << endl;
        cerr << "Please run as " << argv[0] << " numThreads operation imageName saveFile" << endl;
        cerr << "    numThreads    number of threads to use (if #pragma omp... is encountered)" << endl;
        cerr << "    operation     \"flip\" or \"remove\"" << endl;
        cerr << "    imageName     for example, \"images/01_8182x4096.png\"" << endl;
        cerr << "    saveFile      \"yes\" (if you want to save output), \"no\" otherwise" << endl;
        cerr << endl;
        return 1;
    }

    // set the number of thread for the program to use (the first argument)
    omp_set_num_threads(atoi(argv[1]));
    
    // read the parameter PNG from file
    string filename(argv[3]);
    PNG img(filename);
    PNG output;

    cout << "Performing operation..." << endl;
    double start = omp_get_wtime();
    double end;
    if(argv[2][0] == 'f')
    {
        output = ImageTools::verticalFlip(img);
        end = omp_get_wtime();
        if(argv[4][0] == 'y')
        {
            cout << "Saving image..." << endl;
            output.writeToFile("flipped.png");
        }
    }
    else
    {
        Color color = GREEN;
        output = ImageTools::removeColor(img, color);
        end = omp_get_wtime();
        if(argv[4][0] == 'y')
        {
            cout << "Saving image..." << endl;
            output.writeToFile("removed.png");
        }
    }

    cout << "Total processed pixels: " << img.height() * img.width() << endl;
    cout << "Time: " << end - start << " seconds" << endl;
    return 0;
}
