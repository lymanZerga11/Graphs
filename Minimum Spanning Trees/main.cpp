#include <iostream>

#include "weighted_dense_graph.cpp"
#include "weighted_edge.h"
#include "prims_mst.cpp"

void test_prims_mst(DenseGraph<WeightedEdge>& G) {
  PrimsMST<DenseGraph<WeightedEdge>, WeightedEdge> test(G);
  test.show(std::cout);
}

int main() {
  DenseGraph<WeightedEdge> G(8, false);
  WeightedEdge w0 = WeightedEdge(0, 6, 0.39);
  WeightedEdge w1 = WeightedEdge(0, 1, 0.08);
  WeightedEdge w2 = WeightedEdge(0, 2, 0.99);
  WeightedEdge w3 = WeightedEdge(4, 3, 0.65);
  WeightedEdge w4 = WeightedEdge(5, 3, 0.37);
  WeightedEdge w5 = WeightedEdge(7, 4, 0.12);
  WeightedEdge w6 = WeightedEdge(5, 4, 0.78);
  WeightedEdge w7 = WeightedEdge(0, 5, 0.65);
  WeightedEdge w8 = WeightedEdge(6, 4, 0.01);
  WeightedEdge w9 = WeightedEdge(7, 0, 0.49);
  WeightedEdge w10 = WeightedEdge(7, 6, 0.65);
  WeightedEdge w11 = WeightedEdge(7, 1, 0.28);

  G.add_edge(&w0);
  G.add_edge(&w1);
  G.add_edge(&w2);
  G.add_edge(&w3);
  G.add_edge(&w4);
  G.add_edge(&w5);
  G.add_edge(&w6);
  G.add_edge(&w7);
  G.add_edge(&w8);
  G.add_edge(&w9);
  G.add_edge(&w10);
  G.add_edge(&w11);

  //G.print_adj(std::cout);
  test_prims_mst(G);

  return 0;
}
