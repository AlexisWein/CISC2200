#ifndef __GRAPH_ADJ_LIST_H__
#define __GRAPH_ADJ_LIST_H__

#include "Graph.h"
#include <list>

using std::list;

namespace ds {

class GraphAdjList : public Graph {
private:
  // TODO: define more data members here if necessary
  list<int> *adjList; // Array of lists indexed by vertex id
  int numNodes;       //similar to implementation in textbook
  int numEdges;       //similar to implementation in textbook
  bool *mark;

public:
  GraphAdjList(int _V);
  ~GraphAdjList();
  void Init(int n);
  void addEdge(int v1, int v2);
  void delEdge(int v1, int v2);
  bool hasEdge(int v1, int v2) const;
  list<int> adj(int v) const;
  int v() const;
  int e() const;
  bool hasCycle() const;
};

} // namespace ds

#endif // __GRAPH_ADJ_LIST_H__