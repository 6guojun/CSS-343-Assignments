// ------------------- Graph M Implementation ------------------------------
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
#include <limits.h>
#include <iomanip>
#include "graphm.h"

// ---------------------- Default Constructor -------------------------------
// Description: This is the default constructor for the GraphM. It will loop
// through all values in the adjmatrix and set them to placement holders.
// Preconditions: NONE
// Postconditions: clears the location data in T and the adjMatrix of
// garbage values
// --------------------------------------------------------------------------
GraphM::GraphM() {
    for (int vert = 0; vert < MAXNODES; vert++) {   //loop through all edges
        for (int hori = 0; hori < MAXNODES; hori++) {
            adjMatrix[vert][hori] = INT_MAX;        //set to the largest int
            T[vert][hori].dist = INT_MAX;           //set to the largest int
            T[vert][hori].path = 0;                 //set the path to 0
            T[vert][hori].visited = false;          //set it visited to false
        }
    }
}

// ---------------------- buildGraph -------------------------------
// Description: This method will build GraphM edges from a text file. It
// uses a for loop to retrieve all the location names, and a while loop to
// retrieve all the values for the adjacent edges in the graph
// Preconditions: an instance of GraphM
// Postconditions: modifies the size, the data array, and adjMatrix with
// values
// --------------------------------------------------------------------------
void GraphM::buildGraph(ifstream &input) {
    input >> size;                      //get the first value of the text file
    for (int current = 0; current <= size; current++) { //loop for all names
        data[current].setData(input);   //set the data location names
    }
    int start = 0, end = 0, distance = 0;//placement holders for all values
                                         // being pulled
    input >> start >> end >> distance;  //put values into the placement
                                        // holders
    while (start != 0) {                //continue until exit case
        if (start == 0) {               //if the while loop allows in a 0
            break;                      //break out
        }
        adjMatrix[start][end] = distance;//add the weights from all edges
        input >> start >> end >> distance;//gets the next set of data
    }
}

// ---------------------- inserts edge --------------------------------------
// Description: This method will insert a value into the adjMatrix and redo
// the shortest path data in the T array.
// Preconditions: NONE
// Postconditions: modifies the adjMatrix and redoes the shortestPath data
// --------------------------------------------------------------------------
bool GraphM::insertEdge(int start, int end, int distance) {
    if ((start > 0 && end > 0) && (start <= size && end <= size)) {//if the
                                            // start and end locations exist
        if (distance > 0 && start != end) { //check the distance is not
                                            // negative and the locations
                                            // are not the same
            adjMatrix[start][end] = distance;//modify the adjmatrix with data
            findShortestPath();             //redo shortest path
            return true;                    //return true that it was inserted
        }
    }
    return false;                           //returns false
}

bool GraphM::removeEdge(int start, int end) {
    if ((start > 0 && end > 0) && (start <= size && end <= size)) {//checks
                                                // that the location is valid
        adjMatrix[start][end] = INT_MAX;//modify the adjmatrix with MAX data
        findShortestPath();             //redo shortest path
        return true;                    //sucessfully removed
    } else {
        return false;                   //not removed, bad data
    }
}

// ---------------------- findShortestPath ---------------------------------
// Description: This method will find the shortest path from all edges to
// all adjacent edges that it can reach. This is done by using loops to
// repeatedily go through the graph.
// Preconditions: an instance of GrpahM that has been built
// Postconditions: modifies the T array with data
// --------------------------------------------------------------------------
void GraphM::findShortestPath() {
    //set the paths and distances from the adjMatrix and using the source
    for (int source = 1; source <= size; source++) {//loop through all edges
        T[source][source].dist = 0;                 //starting distance is 0
        for (int otherEdge = 1; otherEdge <= size; otherEdge++) {//get
                                                // values of adjacent edges
            if (adjMatrix[source][otherEdge] != INT_MAX) {  //if there is
                                                            // an edge
                T[source][otherEdge].dist = adjMatrix[source][otherEdge];//set
                                                    // the T data
                                                    // with distance data
                T[source][otherEdge].path = source; //set the path to the
                                                    // current edge
            }
        }
        int smallestVertex = 0;             //the current smallest location
        do {
            int mini = INT_MAX;             //the smallest distance
            smallestVertex = 0;             //makse sure location is 0
            for (int i = 1; i <= size; i++) {//loop through all adj Edges
                if (!T[source][i].visited && //if edge is not visited
                        (adjMatrix[source][i] < mini)) {// and is smaller
                                                        // distance
                    mini = adjMatrix[source][i];//set new smallest distance
                    smallestVertex = i;         //new smallest location
                }
            }
            if (smallestVertex == 0) {      //case: not adj edges
                break;
            }

            T[source][smallestVertex].visited = true;//set the location as
                                                     // visited
            for (int curr = 1; curr <= size; ++curr) {
                if (T[source][curr].visited ||
                        adjMatrix[smallestVertex][curr] == INT_MAX ||
                        smallestVertex == curr) {//case: same location,
                                            // visited, or edge is not there
                    continue;               //go to next for loop iteration
                }

                if (T[source][curr].dist > T[source][smallestVertex].dist +
                                        adjMatrix[smallestVertex][curr]) {
                                        //case: distance is larger than new
                                        // distance
                    T[source][curr].dist = T[source][smallestVertex].dist +
                                        adjMatrix[smallestVertex][curr];
                                        //set to new shorter distance
                    T[source][curr].path = smallestVertex;//set path to this
                                                        // location
                }
            }
        } while (smallestVertex != 0);
    }
}

// ---------------------- displayAll --------------------------------------
// Description: This method will display all the paths from all the edges to
// every other edge. It will also display the weights of each path and the
// name of the starting location.
// Preconditions: NONE
// Postconditions: displays T data to the console, the weights of each path,
// and each path.
// --------------------------------------------------------------------------
void GraphM::displayAll() {
    cout << "Description" << setw(20) << "From node" << setw(10) << "To node"
         << setw(14) << "Dijkstra's" << setw(15) << "Path" << endl; //title

    for (int start = 1; start <= size; start++) {  //loop for all
        cout << data[start] << endl;     // print location name

        for (int endE = 1; endE <= size; endE++) {    //loop for second
            if (start != endE) {                   //if they are not the same
                                                // location
                cout << "                    "; //spacing for data line
                                                // after location line
                cout << setw(7) << start << setw(12) << endE;//print locations
                if ((start > size || endE < 0) || (start < 0 || endE > size)){
                    cout << setw(15) << "-----" << endl;//not valid locations
                    return;
                }
                if (T[start][endE].dist != INT_MAX) {  //location has edge
                    cout << setw(12) << T[start][endE].dist << setw(15);
                                                    //weight
                    toPath(start, endE);           //display path endE node
                    cout << endl;                   //end line
                } else {
                    cout << setw(15) << "-----" << endl;//location has no edge
                }
            }

        }
    }
}

// ---------------------- display -------------------------------------------
// Description: prints a single line from a start location to an end
// location. If the locations are invalid, prints the ----- else print the
//  data
// Preconditions: NONE
// Postconditions: displays a single T data location
// --------------------------------------------------------------------------
void GraphM::display(int start, int end) {
    if (start == end) {     //if they are the same location
        return;             //break oout of method
    }
    cout << setw(7) << start << setw(12) << end;    //print locations
    if ((start > size || end < 0) || (start < 0 || end > size)) {
        cout << setw(15) << "-----" << endl;        //if not valid, print ----
        return;                                     //break out
    }
    if (T[start][end].dist != INT_MAX) {            //if the edge has a weight
        cout << setw(12) << T[start][end].dist << setw(15);//print weight
        toPath(start, end);                         //print the path
        cout<<endl;                                 //next line
        toPathName(start, end);                     //location names in order
        cout << endl;                               //next line
    } else {
        cout << setw(15) << "-----" << endl;        //or no edge
    }
}

// ---------------------- toPath -------------------------------------------
// Description: This method takes in two integers that correspond to the end
// and start of a path to be built. If it does no exist, returns nothing.
// Else returns the path using recursion and the T data for the next edge
// Preconditions: NONE
// Postconditions: displays a path from a start to an end
// --------------------------------------------------------------------------
void GraphM::toPath(int start, int end) {
    if (T[start][end].dist == INT_MAX) {    //case: edge does not exist
        return;
    }

    if (start == end) {                     //case: the edges are the same
        cout << end << " ";  // print data

        return;
    }

    int pathData = end; // assign pathdata to the current end
    toPath(start, end = T[start][end].path);    //recurse with next edge

    cout << pathData << " ";   // print path    //print pathdata
}

// ---------------------- toPathName ---------------------------------------
// Description: This method takes in two integers that correspond to the end
// and start of a path to be built. If it does no exist, returns nothing.
// Else returns the path location names using recursion and the T data for
// the next edge
// Preconditions: NONE
// Postconditions: displays a path location names from a start to an end
// --------------------------------------------------------------------------
void GraphM::toPathName(int start, int end) {
    if (T[start][end].dist == INT_MAX) { //case: edge does not exist
        return;
    }

    if (start == end) {        //end of path, print data
        cout << data[end] << endl << endl;  // print data

        return;
    }

    int pathData = end; // assign to path to pathData
    toPathName(start, T[start][end].path);

    cout << data[pathData] << endl << endl;   // print data
}