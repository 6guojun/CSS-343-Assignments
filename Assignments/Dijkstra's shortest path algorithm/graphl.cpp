// ------------------- Graph L Implementation File -------------------------
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
#include <iomanip>
#include "graphl.h"

// ----------------------  default constructor ------------------------------
// Description: the constructor will build all the edges making sure there
// is no garbage values being place into the data. It will walk through each
// edgeNode and set the data.
// Preconditions: NONE
// Postconditions: clears garbage values from data
// --------------------------------------------------------------------------
GraphL::GraphL() {
    for (int current = 0; current < MAXNODES_L; current++) {
        edgeNodes[current].edgeHead = NULL;
        edgeNodes[current].data = NULL;
        edgeNodes[current].visited = false;
    }
}

// ---------------------- deconstructor ---------------------------------
// Description: This method will destroy all edgenodes created and relase
// any memory that was being held. it calls a method called makeEmpty
// Preconditions: NONE
// Postconditions: deallocates the memory
// --------------------------------------------------------------------------
GraphL::~GraphL() {
    makeEmpty();
}

// ---------------------- makeEmpty -------------------------------------------
// Description: This method will deallocate all memory being used by an
// instance of a graph. It does this by walking through all edgeNodes and
// deleting them.
// Preconditions: NONE
// Postconditions: deallocates the memory
// --------------------------------------------------------------------------
void GraphL::makeEmpty() {
    for (int current = 0; current < MAXNODES_L; current++) {
        edgeNodes[current].visited = false; //set location as not visited
        delete edgeNodes[current].data;  // delete location names
        edgeNodes[current].data = NULL;  // set location name to NULL
        if (edgeNodes[current].edgeHead != NULL) {  //if the endnode is not
            // empty
            EdgeNode *deleter =
                    edgeNodes[current].edgeHead;    //create a pointer to
            // this edgenode
            while (edgeNodes[current].edgeHead
                   != NULL) {                       //case: this edgenode is
                // not null
                edgeNodes[current].edgeHead =
                        edgeNodes[current]
                                .edgeHead->nextEdge;       //set this head
                                                             // edgenode
                // to the next edge
                delete deleter;                     //delete the temp
                deleter = NULL;                     //set delter to null
                deleter = edgeNodes[current].edgeHead;//set to current head
            }
        }
    }
}

// ---------------------- buildGraph -------------------------------------
// Description: This method will construct a graph by reading a text file.
// It will take the input from that file and create edgenodes that contain
// data names and the next edge if there was already one in the list.
// Preconditions: NONE
// Postconditions: creates the list of edgenodes and the graph
// --------------------------------------------------------------------------
void GraphL::buildGraph(ifstream &input) {
    input >> size;              //get the size from the file
    NodeData *temp = nullptr;   //create a new pointer for new location
    // Nodedata
    for (int current = 0;
         current <= size; current++) {  //loop through location names in file
        temp = new NodeData();          //create new node
        temp->setData(input);           //get the name and set it
        edgeNodes[current].data = temp; //set the data in the edgenode data
    }

    int from = 0, to = 0;           //placeholders for data
    while (input >> from >> to) {   //get data from file
        if (from == 0) {            //if data is the end
            break;                  //break
        }
        EdgeNode *node = new EdgeNode;  //create a new edgeNode
        if (edgeNodes[from].edgeHead == NULL) { //if head is empty
            node->adjGraphNode = to;            //set node next int value
            edgeNodes[from].edgeHead = node;    //set head to new node
            edgeNodes[from].edgeHead->nextEdge = NULL;  //set next edge to
            // null
        } else {                                //there is a head node
            node->adjGraphNode = to;            //set the node data
            node->nextEdge =
                    edgeNodes[from].edgeHead;   //set the next node to the
            // current head
            edgeNodes[from].edgeHead = node;    //set the head to the new
            // node
        }

    }

}

// ---------------------- displayGraph --------------------------------------
// Description: This method is responsible for display all the edges from
// one edge to the others that were in the file. If uses two for loops to
// loop through all the nodes and checking if they have data
// Preconditions: NONE
// Postconditions: prints to console
// --------------------------------------------------------------------------
void GraphL::displayGraph() {
    cout << "Graph:" << endl;       //title
    for (int current = 1;
         current <= size; current++) {  //loop through head nodes
        cout << "Node " << current
             << "        "
             << *edgeNodes[current].data
             << endl << endl;           //prints the location name
        if (edgeNodes[current].edgeHead != NULL) {  //if head is not null
            EdgeNode *currentEdge =
                    edgeNodes[current].edgeHead; //create a pointer to the
            // head
            while (currentEdge != NULL) {   //while the edge is not null
                cout << "  edge " << current << " "
                     << currentEdge->adjGraphNode << endl;  //print the edge
                currentEdge = currentEdge->nextEdge;    //walk the pointer
            }
        }
    }
}

// ---------------------- depthFirsSearch -----------------------------------
// Description: This method will simulate a depth first scenario in which it
// walks down the nodes and will print the edges. Then it loops through each
// list of edges going from the heads in the graphnodes
// Preconditions: NONE
// Postconditions: order printed to the console
// --------------------------------------------------------------------------
void GraphL::depthFirstSearch() {
    for (int i = 0; i < size; i++) {
        edgeNodes[i].visited = false;   //set all node to not visited
    }
    cout << "Depth First Order: ";      //title
    for (int i = 1; i < size; i++) {     //for all edgenode heads
        if (!edgeNodes[i].visited) {     //if not visited
            dfs(i);                     //do recursion
        }
    }
    cout << endl;                       //end of order
}

// ---------------------- dfs  -------------------------------------------
// Description: this method does the actual recursion of looping through the
// edges and printing the respected location number.
// Preconditions: NONE
// Postconditions: prints to the console
// --------------------------------------------------------------------------
void GraphL::dfs(int n) {
    edgeNodes[n].visited = true;    //set edge to visited
    cout << n << " ";  // output current edge

    EdgeNode *current = edgeNodes[n].edgeHead;  //set a pointer to the head
                                                // of each list
    while (current != NULL) {//if node is not null
        if (!edgeNodes[current->adjGraphNode].visited) {  //and not visited
            dfs(current->adjGraphNode);                 //repeat recursion
        }
        current = current->nextEdge;                    //set current to
                                                        // next edge
    }
}
