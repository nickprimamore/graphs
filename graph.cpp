//  graph.cpp
//
//  "I pledge my honor that I've abided by the Stevens Honor System."
//
//  Nicholas Primamore and Matthew Monaco
//

#include <stdio.h>
#include "graph.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//implementing Node defined in graph.h for adjacency list
struct Graph :: Node{
    int value;
    float edgeWeight;
    Node* next;
}

/* Make an empty graph with n vertices (empty means all edges either set to INFINITY or NULL,
 depending on representation), using either adjacency matrix
 or adjacency lists depending on whether rep==MATRIX or rep==LIST.
 if n <1, return NULL
 if rep is not MATRIX or LIST, return NULL
 */
Graph :: Graph(int n, int rep){
    if(n < 1 || rep != MATRIX || rep!= LIST) return NULL;
    
    if(rep == LIST){
        numVertices = n;
        type = LIST;
        Graph::Node* listArray[numVertices];
        list = listArray;
        for(int index = 0; index < numVertices; index++){
            (*(list + index))->edgeWeight = INFINITY;
        }
    }
    else{
        numVertices = n;
        type = MATRIX;
        float matrixArray[numVertices * numVertices]; // 1D arrray implementation
        matrix = matrixArray;
        for(int index = 0; index < (numVertices * numVertices); index++){
            *(matrix + index) = INFINITY;
        }
    }
}

/* free the graph object and ALL its resources.
 */
Graph :: ~Graph(){
    
}

/* return number of vertices.
 Note that this is needed since the property numVerts is private*/
int Graph :: numVerts(){
    return numVertices;
}
