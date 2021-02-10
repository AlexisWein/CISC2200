#include "GraphAdjList.h"

/*
I went to a tutor for help with this lab. A lot of what I had already was correct,
but they helped me most with the hasEdge function and with debugging my code to fix crashes.
*/

namespace ds {

GraphAdjList::GraphAdjList(int V) {
  // TODO: initialize adjList
  adjList = new list<int>[V];
  mark = new bool[V];
  numNodes = V;
  numEdges = 0;
  //std::cout << "Constructor test" << std::endl;         //debugging statement
}

GraphAdjList::~GraphAdjList() {
  // TODO: destroy adjList
  delete [] mark;
  delete [] adjList;
}

/*
  A tutor helped me with the conditions for unexpected cases
*/
void GraphAdjList::addEdge(int v1, int v2) {
  // TODO: record edge v1-v2 in adjList
  
  //std::cout << "addEdge test" << std::endl;                  //debugging statement
  //std::cout << "adjList[v1] test: " << v1 << std::endl;      //debugging statement
  if(v1 > numNodes  ||  v2 > numNodes)      //accounts for the case where the array is not large enough to hold another edge
    return;
  if(hasEdge(v1, v2))                       //accounts for the case where the edge is already in the graph
    return;
  adjList[v1-1].push_back(v2);              //adds v1 to v2; accounts for index starting at 1 instead of 0
  adjList[v2-1].push_back(v1);              //adds v2 to v1; accounts for index starting at 1 instead of 0
  numEdges++;                               //increments the count of edges in the graph

}

void GraphAdjList::delEdge(int v1, int v2) {
  // TODO: delete edge v1-v2 from graph
  if(numEdges == 0)                          //accounts for the case where there are no edges in the graph (this is new, you might have to delete it)
    return;
  if(v1 > numNodes  ||  v2 > numNodes)       //A tutor helped me with this condition for unexpected cases
    return;
  if(hasEdge(v1, v2))
  {
    adjList[v1-1].remove(v2);                //removes v2 from v1; accounts for index starting at 1 instead of 0
    adjList[v2-1].remove(v1);                //removes v1 from v2; accounts for index starting at 1 instead of 0
    numEdges--;                              //decrements numEdges
  }
}

bool GraphAdjList::hasEdge(int v1, int v2) const {
  // TODO: return true if edge v1-v2 is in the graph
  
  if(v1 > numNodes  ||  v2 > numNodes)        //prevents a segfault
    return false;
  for (std::list<int>::iterator it=adjList[v1-1].begin(); it != adjList[v1-1].end(); ++it)      // A tutor helped me with this, and I used the information at https://www.cplusplus.com/reference/list/list/begin/
  {
    if(*it == v2)
    {
      return true;
    }
  }
  return false;
}

list<int> GraphAdjList::adj(int v) const {
  // TODO: return the list of adjcent nodes of v
  list<int> tempList;                          //I attended office hours for help with this if statement to account for unexpected cases
  if(v < 1  ||  v > numNodes)
    return tempList;
  return adjList[v-1];                         //returns the list at the given index; accounts for index starting at 1 instead of 0
}

int GraphAdjList::v() const {
  // TODO: return number of nodes
  return numNodes;                             //returns the number of nodes (held in a variable)
}

int GraphAdjList::e() const {
  // TODO: return number of edges
  //std::cout << numEdges << std::endl;        //debugging statement
  return numEdges;                             //returns the number of edges (held in a variable)
}

bool GraphAdjList::hasCycle() const {
  // TODO: return true if the graph contains cycles; return false if the graph
  // is acyclic
  return false;
}

} // namespace ds