// ------------------- Graph M Header File ----------------------------------
// Cameron Padua CSS343 C
// Feb 1, 2017
// Feb 14, 2017
// --------------------------------------------------------------------------
// Purpose - The Purpose of this graph is to store data regrading paths to
// certain locations and Dijkstras shortest path to find a path from a start
// location to an end location. In addition to this, the program show be
// able to build a graph of edges and display them to the console in both a
// cluster and single line with location titles.
// --------------------------------------------------------------------------
// Specification: This program uses a variety of arrays (1D and 2D) to store
// edge data and their names. Due to the program specfications, it was
// designed to take no more than 100 edges of data for any one graph. This
// program implements Dijkstras shortest path.
// This program contains methods to insert, remove, print, build, and create
// the shortest path.
//  Special Algorithms: N/A
//  Assumptions: No bad lines of input will be inserted.
//  The program will be run on c++11
//  no more than 100 edges per graph
// --------------------------------------------------------------------------

#ifndef ASS3_GRAPHM_H
#define ASS3_GRAPHM_H

#include "nodedata.h"

using namespace std;

int const MAXNODES = 101;           //max edges in any graph used in the
                                    // arrays
class GraphM {
public:
    GraphM();                       //default constructor, clears the memory
                                    // of garbage values
    void buildGraph(ifstream &);    //builds all edges in the graph

    bool insertEdge(int, int, int); //inserts an edge into the adjMatrix and
                                    // redoes the shortest path
    bool removeEdge(int, int);      //removes an edge from the adjMatrix and
                                    // redoes the shortest path
    void findShortestPath();        //finds the shortest paths between all
                                    // edges
    void displayAll();              //displays all the shortest paths
                                    // between all edges
    void display(int, int);         //displat the shortest path for one path

private:
    struct TableType {              //location data for each location to
        bool visited;               // to measure if the location has been
        int dist;                   // visited, the path edge, and the weight
        int path;
    };

    void toPath(int, int);          //builds the path of two locations, if
                                    // no path, returns ----
    void toPathName(int, int);      //returns a path as the names of the
                                    // location
    NodeData data[MAXNODES];        //Names of the locations, stored in
                                    // array locations 1-100
    int adjMatrix[MAXNODES][MAXNODES];//Keeps track of all the adjacent edges
                                      // 100 x 100
    int size;                       // the number of edges in the graph

    TableType T[MAXNODES][MAXNODES];// a table of all the location data
};

#endif //ASS3_GRAPHM_H
