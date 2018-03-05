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
 if n <1, set numVertices to 1
 if rep is not MATRIX or LIST, defaults to MATRIX
 */
Graph :: Graph(int n, int rep){
    if(n < 1){
        numVertices = 1;
    }
    else{
        numVertices = n;
    }
    if(rep == LIST){
        type = LIST;
        Graph::Node** listArray = new Graph::Node*[numVertices];
        list = listArray;
        for(int index = 0; index < numVertices; index++){
            (*(list + index)) = NULL;
        }
        matrix = NULL;
    }
    else{
        type = MATRIX;
        float* matrixArray = new float[numVertices * numVertices]; // 1D array implementation
        matrix = matrixArray;
        for(int index = 0; index < (numVertices * numVertices); index++){
            (*(matrix + index)) = INFINITY;
        }
        list = NULL;
    }
}

/* free the graph object and ALL its resources.
 */
Graph :: ~Graph(){
    //for list travel through eaxch node in lists, then delete array
    //for matrix just delete the array
    if(type == MATRIX && matrix != NULL){
        delete matrix;
    }
    else{
        if(list != NULL){
            for(int index = 0; index < numVertices; index++){
                while(*(list + index) != NULL){
                    Graph::Node * temp = *(list + index);
                    *(list + index) = (*(list + index))->next;
                    delete temp;
                }
            }
            delete list;
        }
    }
}

/* make a DEEP copy of g, but using the representation
 specified by rep (which is assumed to be MATRIX or LIST)
 Everything should be copied over, not just references
 I.E. a change in the first graph should not change the second graph
 If rep is not MATRIX or LIST, return NULL
 */
Graph* Graph :: cloneGraph(int rep){
    //unsure of the return for this method
    if(type == rep){
        return; //unsure of what to return
    }else if(rep == MATRIX){
        
    }else if(rep == LIST){
        
    }else{
        return NULL;
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
bool Graph :: addEdge( int source, int target, float w){
    //invalid cases:
    if(w == INFINITY || w < 0) return false;
    if(source < 0 || source > numVerts - 1) return false;
    if(target < 0 || target > numVerts - 1) return false;
    
    //FOR ADJACENCY LIST:
    //think of each slot in the array as "head" pointers, they are all NULL at first
    //check if NULL first before checking values and traversing list
    //if edge doesnt exist, dont care about NULL
    if(type == LIST && list != NULL){
            
    }
    else{ //it's a matrix
        if(matrix != NULL){
            float val = (*(matrix + (numVertices*source+target)));
            //edge already exists
            if(val != INFINITY ){
                return false;
            }
            else{
                (*(matrix + (numVertices*source+target))) = w;
                return true;
            }
        }
    }
}


/* delete edge from source to target, and return
 true, if there was an edge from source to target, and both source and target are valid vertex numbers.
 Otherwise, make no change and return false.
 */
bool Graph :: delEdge(int source, int target){
    //invalid vertices:
    if(source < 0 || source > numVerts - 1) return false;
    if(target < 0 || target > numVerts - 1) return false;
    
    if(type == LIST && list != NULL){
        
    }
    else{ //it's a matrix
        if(matrix != NULL){
            float val = (*(matrix + (numVertices*source+target)));
            if(val != INFINITY){
                (*(matrix + (numVertices*source+target))) = INFINITY;
                return true;
            }
            else{
                return false;
            }
        }
    }
}

/* return weight of the edge from source to target,
 if there is one; otherwise return INFINITY. (part of the math.h library)
 Return -1.0 if source or target are not valid vertex numbers.
 */
float Graph :: edge( int source, int target){
    //invalid vertices:
    if(source < 0 || source > numVerts - 1) return -1.0;
    if(target < 0 || target > numVerts - 1) return -1.0;
    
    if(type == LIST && list != NULL){
        
    }
    else{ //it's a matrix
        if(matrix != NULL){
            float val = (*(matrix + (numVertices*source+target)));
            if(val == INFINITY){
                return INFINITY;
            }
            else{
                return val;
            }
        }
    }
}
