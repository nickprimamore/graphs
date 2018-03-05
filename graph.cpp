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
};

/* Make an empty graph with n vertices (empty means all edges either set to INFINITY or NULL,
 depending on representation), using either adjacency matrix
 or adjacency lists depending on whether rep==MATRIX or rep==LIST.
 if n <1, return NULL
 if rep is not MATRIX or LIST, return NULL
 */
Graph :: Graph(int n, int rep){
    if(n < 1 || rep != MATRIX || rep!= LIST){
        //not sure what to do b/c can't return anything in constructor
    }
    else if(rep == LIST){
        numVertices = n;
        type = LIST;
        Graph::Node** listArray = new Graph::Node*[numVertices];
        list = listArray;
        for(int index = 0; index < numVertices; index++){
            (*(list + index))->edgeWeight = INFINITY;
        }
    }
    else{
        numVertices = n;
        type = MATRIX;
        float* matrixArray = new float[numVertices * numVertices]; // 1D array implementation
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

/* make a DEEP copy of g, but using the representation
 specified by rep (which is assumed to be MATRIX or LIST)
 Everything should be copied over, not just references
 I.E. a change in the first graph should not change the second graph
 If rep is not MATRIX or LIST, return NULL
 */
void Graph* cloneGraph(int rep){
    //unsure of the return for this method
    if(type == rep){
        return; //unsure of what to return
    }else if(rep == MATRIX){
        
    }else if(rep == LIST){
        
    }else{
        return; //idk what to return
    }
}

/* return number of vertices.
 Note that this is needed since the property numVerts is private*/
int Graph :: numVerts(){
    return numVertices;
}

/* add edge from source to target with weight w, and return
 true, if source and target are valid vertex numbers and
 there was no edge from source to target initially.
 Otherwise if source or target are invalid, or the edge already exists,
 make no change and return false. If the edge already exists, DO NOT UPDATE IT! Just return false
 if w is INFINITY or negative, do nothing, and return false.
 */
bool addEdge( int source, int target, float w){
    if(w == INFINITY || w < 0){
        return false;   
    }
}

/* delete edge from source to target, and return
 true, if there was an edge from source to target, and both source and target are valid vertex numbers.
 Otherwise, make no change and return false.
 */
bool delEdge( int source, int target){
    
}

/* return weight of the edge from source to target,
 if there is one; otherwise return INFINITY. (part of the math.h library)
 Return -1.0 if source or target are not valid vertex numbers.
 */
float edge( int source, int target){
    
}
