/**
 * @file premade_graphs.cpp
 *
 * This file contains the implementation of the premade graphs.
 * Updated by Sean Massung for Spring 2012
 *
 * @author Sean Massung
 * @date Spring 2011
 */

#include "premade_graphs.h"

/**
 * Returns a starting vertex for a path algorithm.
 * @param mapType - determines which map to get a starting vertex
 *  from. Possible values are "us", "europe", and "japan"
 * @return the starting vertex for a particular graph
 */
Vertex PremadeGraphs::getStartVertex(string mapType)
{
    if(mapType == "us")
        return 4;
    if(mapType == "europe")
        return 3; 
    return 4;
}

/**
 * Returns a ending vertex for a path algorithm.
 * @param mapType - determines which map to get a ending vertex
 *  from. Possible values are "us", "europe", and "japan"
 * @return the ending vertex for a particular graph
 */
Vertex PremadeGraphs::getEndVertex(string mapType)
{
    if(mapType == "us")
        return 0;
    if(mapType == "europe")
        return 7;
    return 0;
}

/**
 * Creates a map of some US cities.
 * @param isWeighted - whether to show distance between
 *  cities in miles.
 * @return the graph of a few cities in the United States
 */
Graph PremadeGraphs::createUSMap(bool isWeighted)
{
    Graph g(isWeighted);
    size_t numCities = 8;

    string labels[] = { "WashingtonDC", "Champaign", "Chicago", "Cincinnati",
            "KansasCity", "Nashville", "Pittsburgh", "StLouis" };

    Vertex vertices[numCities];
    for(size_t i = 0; i < numCities; ++i)
    {
        vertices[i] = g.insertVertex(labels[i]);
        g.setVertexName(i, labels[i]);
    }
        
    g.insertEdge(vertices[4], vertices[2]);
    g.insertEdge(vertices[4], vertices[1]);
    g.insertEdge(vertices[2], vertices[1]);
    g.insertEdge(vertices[6], vertices[0]);
    g.insertEdge(vertices[2], vertices[3]);
    g.insertEdge(vertices[3], vertices[6]);
    g.insertEdge(vertices[1], vertices[3]);
    g.insertEdge(vertices[3], vertices[0]);
    g.insertEdge(vertices[3], vertices[5]);
    g.insertEdge(vertices[5], vertices[0]);
    g.insertEdge(vertices[4], vertices[7]);
    g.insertEdge(vertices[1], vertices[7]);
    g.insertEdge(vertices[3], vertices[7]);
    
    if(isWeighted)
    {
        g.setEdgeWeight(vertices[4], vertices[2], 315);
        g.setEdgeWeight(vertices[4], vertices[1], 347);
        g.setEdgeWeight(vertices[2], vertices[1], 126);
        g.setEdgeWeight(vertices[6], vertices[0], 190);
        g.setEdgeWeight(vertices[2], vertices[3], 406);
        g.setEdgeWeight(vertices[3], vertices[6], 257);
        g.setEdgeWeight(vertices[1], vertices[3], 210);
        g.setEdgeWeight(vertices[3], vertices[0], 405);
        g.setEdgeWeight(vertices[3], vertices[5], 235);
        g.setEdgeWeight(vertices[5], vertices[0], 570);
        g.setEdgeWeight(vertices[4], vertices[7], 353);
        g.setEdgeWeight(vertices[1], vertices[7], 148);
        g.setEdgeWeight(vertices[3], vertices[7], 310);
    }

    return g;
}

/**
 * Creates a map of some European cities.
 * @param isWeighted - whether to show distance between
 *  cities in miles.
 * @return the graph of a few cities in Europe
 */
Graph PremadeGraphs::createEuropeMap(bool isWeighted)
{
    Graph g(isWeighted);
    size_t numCities = 10;
 
    string labels[] = { "Barcelona", "Berlin", "Helsinki", "London", "Madrid",
            "Milan", "Paris", "Prague", "Stockholm", "Warsaw" };
            
    Vertex vertices[numCities];
    for(size_t i = 0; i < numCities; ++i)
    {
        vertices[i] = g.insertVertex(labels[i]);
        g.setVertexName(i, labels[i]);
    }
        
    g.insertEdge(vertices[4], vertices[3]);
    g.insertEdge(vertices[4], vertices[0]);
    g.insertEdge(vertices[0], vertices[3]);
    g.insertEdge(vertices[0], vertices[5]);
    g.insertEdge(vertices[0], vertices[6]);
    g.insertEdge(vertices[3], vertices[6]);
    g.insertEdge(vertices[6], vertices[5]);
    g.insertEdge(vertices[3], vertices[8]);
    g.insertEdge(vertices[3], vertices[1]);
    g.insertEdge(vertices[6], vertices[1]);
    g.insertEdge(vertices[5], vertices[1]);
    g.insertEdge(vertices[5], vertices[7]);
    g.insertEdge(vertices[8], vertices[1]);
    g.insertEdge(vertices[1], vertices[7]);
    g.insertEdge(vertices[1], vertices[9]);
    g.insertEdge(vertices[8], vertices[2]);
    g.insertEdge(vertices[1], vertices[2]);
    g.insertEdge(vertices[2], vertices[9]);
    
    if(isWeighted)
    {
        g.setEdgeWeight(vertices[4], vertices[3], 785);
        g.setEdgeWeight(vertices[4], vertices[0], 314);
        g.setEdgeWeight(vertices[0], vertices[3], 707);
        g.setEdgeWeight(vertices[0], vertices[5], 451);
        g.setEdgeWeight(vertices[0], vertices[6], 515);
        g.setEdgeWeight(vertices[3], vertices[6], 213);
        g.setEdgeWeight(vertices[6], vertices[5], 398);
        g.setEdgeWeight(vertices[3], vertices[8], 892);
        g.setEdgeWeight(vertices[3], vertices[1], 580);
        g.setEdgeWeight(vertices[6], vertices[1], 546);
        g.setEdgeWeight(vertices[5], vertices[1], 524);
        g.setEdgeWeight(vertices[5], vertices[7], 398);
        g.setEdgeWeight(vertices[8], vertices[1], 504);
        g.setEdgeWeight(vertices[1], vertices[7], 174);
        g.setEdgeWeight(vertices[1], vertices[9], 321);
        g.setEdgeWeight(vertices[8], vertices[2], 246);
        g.setEdgeWeight(vertices[1], vertices[2], 687);
        g.setEdgeWeight(vertices[2], vertices[9], 570);
    }

    return g;
}

/**
 * Creates a map of some Japanese cities.
 * @param isWeighted - whether to show distance between
 *  cities in miles.
 * @return the graph of a few cities in Japan
 */
Graph PremadeGraphs::createJapanMap(bool isWeighted)
{
    Graph g(isWeighted);
    size_t numCities = 9;
    
    string labels[] = { "Hitachinaka", "Komoro", "Kyoto", "Nagano",
        "Nagoya", "Ome", "Omiya", "Osaka", "Tokyo" };
        
    Vertex vertices[numCities];
    for(size_t i = 0; i < numCities; ++i)
    {
        vertices[i] = g.insertVertex(labels[i]);
        g.setVertexName(i, labels[i]);
    }
        
    g.insertEdge(vertices[4], vertices[3]);
    g.insertEdge(vertices[3], vertices[5]);
    g.insertEdge(vertices[5], vertices[8]);
    g.insertEdge(vertices[3], vertices[1]);
    g.insertEdge(vertices[5], vertices[1]);
    g.insertEdge(vertices[5], vertices[6]);
    g.insertEdge(vertices[1], vertices[6]);
    g.insertEdge(vertices[6], vertices[8]);
    g.insertEdge(vertices[6], vertices[0]);
    g.insertEdge(vertices[8], vertices[0]);
    g.insertEdge(vertices[7], vertices[2]);
    g.insertEdge(vertices[2], vertices[4]);
    g.insertEdge(vertices[2], vertices[8]);
    g.insertEdge(vertices[4], vertices[8]);
    g.insertEdge(vertices[4], vertices[5]);
    
    if(isWeighted)
    {
        g.setEdgeWeight(vertices[4], vertices[3], 124);
        g.setEdgeWeight(vertices[3], vertices[5], 85);
        g.setEdgeWeight(vertices[5], vertices[8], 24);
        g.setEdgeWeight(vertices[3], vertices[1], 26);
        g.setEdgeWeight(vertices[5], vertices[1], 62);
        g.setEdgeWeight(vertices[5], vertices[6], 21);
        g.setEdgeWeight(vertices[1], vertices[6], 73);
        g.setEdgeWeight(vertices[6], vertices[8], 15);
        g.setEdgeWeight(vertices[6], vertices[0], 60);
        g.setEdgeWeight(vertices[8], vertices[0], 63);
        g.setEdgeWeight(vertices[7], vertices[2], 27);
        g.setEdgeWeight(vertices[2], vertices[4], 65);
        g.setEdgeWeight(vertices[2], vertices[8], 226);
        g.setEdgeWeight(vertices[4], vertices[8], 160);
        g.setEdgeWeight(vertices[4], vertices[5], 140);
    }
    
    return g;
}
