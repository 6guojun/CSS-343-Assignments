// ------------------- Graph L Header File ----------------------------------
// Cameron Padua CSS343 C
// Feb 1, 2017
// Feb 14, 2017
// --------------------------------------------------------------------------
// Purpose - The purpose of this class is to store edge nodes in a linked
// list that can produce a depth first search algorithm effect.
// --------------------------------------------------------------------------
// Specification: This program has two different types of struct data types.
// The first is GraphNode. This struct stores an edgenode pointer, data name
// location, and a boolean for vistied. The Edgenode struct contains and int
// of the edge it represents and the next edge node in the series. Ideally,
// the graphNode will contain all the heads of each list of edgenodes
// This program contains methods  print, build, and create the a depthFirst
// Search path.
//  Special Algorithms: N/A
//  Assumptions: No bad lines of input will be inserted.
//  The program will be run on c++11
//  no more than 100 edges per graph
// --------------------------------------------------------------------------

#ifndef ASS3_GRAPHL_H
#define ASS3_GRAPHL_H

#include "nodedata.h"

int const MAXNODES_L = 101; //max number of edges in a graph, only 1 - 100
                            // are used
class GraphL {
public:
    GraphL();   //default constructor
    ~GraphL();  //deconstuctor

    void buildGraph(ifstream &);    //build the graph edgeNodes
    void displayGraph();            //print the edgesnodes for each graphnode
    void depthFirstSearch();        //prints a depth first order

private:
    int size = 0;         //number of edges in the graph
    struct EdgeNode;      // forward reference for the compiler
    struct GraphNode {    // structs used for simplicity, use classes if
                            // desired
        EdgeNode *edgeHead; // head of the list of edges
        NodeData *data;     // data information about each node
        bool visited;       //if the edge has been visited
    };

    GraphNode edgeNodes[MAXNODES_L];    //the head of each edgenodes

    struct EdgeNode {
        int adjGraphNode;  // subscript of the adjacent graph node
        EdgeNode *nextEdge;//the next edge
    };

    void makeEmpty();   //deconstructor
    void dfs(int);      //helper method for recursion

};
#endif //ASS3_GRAPHL_H
