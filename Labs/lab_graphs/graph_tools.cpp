/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"


/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph & graph, Vertex start, Vertex end)
{
	if(graph.getEdges().size()==0)return 0;
	
	vector<Vertex> vertices=graph.getVertices();
	vector<Edge> edges= graph.getEdges();
	for(int i=0;i<vertices.size();i++)
	graph.setVertexLabel(vertices[i],"UNEXPLORED");
		
	for(int j=0;j<edges.size();j++)
		graph.setEdgeLabel(edges[j].source,edges[j].dest,"UNEXPLORED");
		
	
	
	
	
	
	Vertex temp=start;	
	graph.setVertexLabel(temp,"VISITED");		
	queue<Vertex> q_graph;		
	q_graph.push(temp);
	
	unordered_map<Vertex,Vertex> tempgraph;
	//tempgraph.insert(make_pair(start,start));
	
	vector<Vertex> neighbors;
	bool flag=false;
		
	while(!q_graph.empty()&&!flag)
	{
		temp= q_graph.front();
		q_graph.pop();
		neighbors=graph.getAdjacent(temp);
		for(int i=0;i<neighbors.size() && !flag;i++)
		{
			if(neighbors[i]==end)
			flag=true;

			else if(graph.getVertexLabel(neighbors[i])=="UNEXPLORED")
			{
				graph.setEdgeLabel(temp,neighbors[i],"DISCOVERY");				
				graph.setVertexLabel(neighbors[i],"VISITED");
				
				q_graph.push(neighbors[i]);
				tempgraph[neighbors[i]]=temp;
			}
			
			else if(graph.getEdgeLabel(temp,neighbors[i])=="UNEXPLORED")
			{

				graph.setEdgeLabel(temp,neighbors[i],"CROSS");
			}


		}
	
	
		

	}		

	graph.setEdgeLabel(temp,end,"CROSS");
	graph.setEdgeLabel(temp,end,"MINPATH");
	
	int count=1;
	while(temp!=start)
	{
		Vertex hold=tempgraph[temp];
		graph.setEdgeLabel(temp,hold,"MINPATH");
		temp=hold;
		count ++;


	}
	return count;


}



	
	


/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph & graph)
{
	vector<Vertex> vertices=graph.getVertices();
	vector<Edge> edges= graph.getEdges();
	for(int i=0;i<vertices.size();i++)
	{
		graph.setVertexLabel(vertices[i],"UNEXPLORED");
		vector<Vertex> neighbors = graph.getAdjacent(vertices[i]);
		for(int j=0;j<neighbors.size();j++)
		graph.setEdgeLabel(vertices[i],neighbors[j],"UNEXPLORED");
	}

	stack<Vertex> vertices1;
	stack<Vertex> vertices2;
	
	
	minWeightHelper(graph,graph.getStartingVertex(),vertices1,vertices2);

	Vertex current1=vertices1.top();
	vertices1.pop();
	Vertex current2=vertices2.top();
	vertices2.pop();
	
	while(!vertices1.size()==0)
	{	
		if(graph.getEdgeWeight(vertices1.top(),vertices2.top())<graph.getEdgeWeight(current1,current2))
		{
			current1=vertices1.top();
			current2=vertices2.top();
		}
		vertices1.pop();
		vertices2.pop();
	}
	int weight=graph.getEdgeWeight(current1,current2);
	graph.setEdgeLabel(current1,current2,"MIN");
	return weight;
}
void GraphTools::minWeightHelper(Graph &graph,Vertex v,stack<Vertex>&vertices1,stack<Vertex>&vertices2)
{
	vector<Vertex> adjacent = graph.getAdjacent(v);
        for(int i=0;i<adjacent.size();i++)
        {
               	if (graph.getVertexLabel(adjacent[i]) == "UNEXPLORED")
                {
                        graph.setVertexLabel(adjacent[i],"VISITED");
                        graph.setEdgeLabel(v,adjacent[i],"DISCOVERY");
                       	 vertices1.push(v);
                       	 vertices2.push(adjacent[i]);
		                minWeightHelper(graph,adjacent[i],vertices1,vertices2);
		       }
                else if (graph.getEdgeLabel(v,adjacent[i]) == "UNEXPLORED")
                {
                        graph.setEdgeLabel(v,adjacent[i],"CROSS");
                       
			 vertices1.push(v);
                        
			vertices2.push(adjacent[i]);
                }
        }
        
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort (http://www.cplusplus.com/reference/algorithm/sort/)
 *  instead of creating a priority queue.
 */
void GraphTools::findMST(Graph & graph)
{

	int a,b;
	DisjointSets set;
	int size=graph.getVertices().size();
	set.addelements(size);
	vector<Edge> edges= graph.getEdges();
		sort(edges.begin(), edges.end());
        		for(int i = 0; i < edges.size(); i++)
				{
             			
            			   	a= set.find(edges[i].dest);
					b= set.find(edges[i].source);
          			    if(a!= b) 
					{
            		            	graph.setEdgeLabel(edges[i].source, edges[i].dest, "MST");
                       			 set.setunion(a,b);
                			}
			        }
       




}






