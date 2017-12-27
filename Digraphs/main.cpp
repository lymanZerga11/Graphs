#include "dense_graph.cpp"
#include "digraph_dfs.cpp"
#include <iostream>

int main() {
  DenseGraph G(13, true);
  G.add_edge(Edge(4, 2));
  G.add_edge(Edge(2, 3));
  G.add_edge(Edge(3, 2));
  G.add_edge(Edge(0, 6));
  G.add_edge(Edge(0, 1));
  G.add_edge(Edge(2, 0));
  G.add_edge(Edge(11, 12));
  G.add_edge(Edge(12, 9));
  G.add_edge(Edge(9, 10));
  G.add_edge(Edge(9, 11));
  G.add_edge(Edge(8, 9));
  G.add_edge(Edge(10, 12));
  G.add_edge(Edge(4, 11));
  G.add_edge(Edge(4, 3));
  G.add_edge(Edge(3, 5));
  G.add_edge(Edge(7, 8));
  G.add_edge(Edge(8, 7));
  G.add_edge(Edge(5, 4));
  G.add_edge(Edge(0, 5));
  G.add_edge(Edge(6, 4));
  G.add_edge(Edge(6, 9));
  G.add_edge(Edge(7, 6));
  //G.print_adj(std::cout);
  DFS<DenseGraph> test(G);
  return 0;
}
