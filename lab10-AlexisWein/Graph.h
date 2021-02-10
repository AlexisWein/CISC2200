#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <list>

using std::cout;
using std::list;

namespace ds {

class Graph {
public:
  /**
   * @brief Default constructor
   */
  Graph() {}

  /**
   * @brief Create empty graph with V vertices
   *
   * @param V number of vertices
   */
  Graph(int V);

  /**
   * @brief Add an edge to graph
   *
   * @param v1 id of the one vertex
   * @param v2 id of the other vertex
   */
  virtual void addEdge(int v1, int v2) = 0;

  /**
   * @brief Remove an edge
   *
   * @param v1 id of the one vertex
   * @param v2 id of the other vertex
   */
  virtual void delEdge(int v1, int v2) = 0;

  /**
   * @brief Determine if an edge is in graph
   *
   * @param v1 id of the one vertex
   * @param v2 id of the other vertex
   * @return true if the edge is in the graph
   * @return false otherwise
   */
  virtual bool hasEdge(int v1, int v2) const = 0;

  /**
   * @param v node id
   * @return a list of nodes adjacent to v
   */
  virtual list<int> adj(int v) const = 0;

  /**
   * @return number of vertices
   */
  virtual int v() const = 0;

  /**
   * @return number of edges
   */
  virtual int e() const = 0;

  /**
   * @brief Print the graph to os
   *
   * @param os the output stream
   * @param g the graph
   * @return the updated output stream
   */
  friend std::ostream &operator<<(std::ostream &os, const Graph &g) {
    bool first = true;
    os << "[";
    for (int v = 1; v <= g.v(); v += 1) {
      //std::cout << "test\n";
      for (auto &w : g.adj(v)) {
        if (first) {
          first = false;
        } else {
          os << " ";
        }
        os << v << "-" << w;
      }
    }
    os << "]";
    return os;
  }
};

} // namespace ds

#endif // __GRAPH_H__