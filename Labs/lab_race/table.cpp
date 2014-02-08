/**
 * @file table.cpp
 */

#include "table.h"

/**
 * Find all products of an m x n multiplication table and prints
 *  them out.
 *  @param table - a 2D int array where the result is stored
 *  @param width - the width of the multiplication table
 *  @param height - the height of the multiplication table
 *  @param print - whether to print the table
 */
void MultTable::findProductsParallel(int** table, int width, int height, bool print)
{
    int i;

    #pragma omp parallel for
    for(i = 0; i < width; ++i)
    { 
      for(int j = 0; j< height; ++j)
        {
           table[i][j] = (i+1)*(j+1); 
        }
    }

    if(print)
    {
        // print out the results (only up to 20)
        for(int i = 0; i < width && i < 20; ++i)
        {
            for(int j = 0; j < height && j < 20; ++j)
            {
                cout << std::setw(4) << table[i][j];
            }
            cout << endl;
        }
    }
}

/**
 * Find all products of an m x n multiplication table and prints
 *  them out.
 *  @param table - a 2D int array where the result is stored
 *  @param width - the width of the multiplication table
 *  @param height - the height of the multiplication table
 *  @param print - whether to print the table
 */
void MultTable::findProductsSerial(int** table, int width, int height, bool print)
{
    int i, j;

    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
           table[i][j] = (i+1)*(j+1); 
        }
    }

    if(print)
    {
        // print out the results (only up to 20)
        for(int i = 0; i < width && i < 20; ++i)
        {
            for(int j = 0; j < height && j < 20; ++j)
            {
                cout << std::setw(4) << table[i][j];
            }
            cout << endl;
        }
    }
}

/**
 * Makes sure the multiplication table has the correct value in each cell.
 *  @param table - a 2D int array where the result is stored
 *  @param width - the width of the multiplication table
 *  @param height - the height of the multiplication table
 *  @return - whether the table is correct or not
 */
bool MultTable::checkTable(int** table, int width, int height)
{
    int i, j;
    for(i = 0; i < width && i < 20; ++i)
    {
        for(j = 0; j < height && j < 20; ++j)
        {
           if(table[i][j] != (i+1)*(j+1))
           {
                cout << "Incorrect: " << (i+1) << " * " << (j+1) << " != " << table[i][j] << endl;
                return false;
           }
        }
    }
    return true;
}
