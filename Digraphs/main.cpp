#include <iostream>

#include "dense_graph.cpp"
#include "digraph_dfs.cpp"
#include "transitive_closure.cpp"
#include "dfs_top_sort.cpp"
#include "sq_top_sort.cpp"

void test_digraph_dfs(DenseGraph& G) {
  DFS<DenseGraph> test(G);
}

void test_transitive_closure(DenseGraph& G) {
  TransitiveClosure<DenseGraph> test(G);
  std::cout << test.is_reachable(0, 11) << std::endl;
  std::cout << test.is_reachable(12, 8) << std::endl;
  std::cout << test.is_reachable(8, 12) << std::endl;
}

void test_topological_sort(DenseGraph& G) {
  DFSTopologicalSort<DenseGraph> test_dfs(G);
  std::vector<int> rev_topological_sort = test_dfs.get_reversed_order();
  for(auto i:rev_topological_sort)
    std::cout << i << " ";
  std::cout << std::endl;

  SQTopologicalSort<DenseGraph> test_sq(G);
  rev_topological_sort = test_sq.get_reversed_order();
  for(auto i:rev_topological_sort)
    std::cout << i << " ";
  std::cout << std::endl;
}

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

  test_digraph_dfs(G);
  test_transitive_closure(G);

  DenseGraph H(13, true);
  H.add_edge(Edge(0, 1));
  H.add_edge(Edge(0, 2));
  H.add_edge(Edge(0, 3));
  H.add_edge(Edge(0, 5));
  H.add_edge(Edge(0, 6));
  H.add_edge(Edge(2, 3));
  H.add_edge(Edge(3, 4));
  H.add_edge(Edge(3, 5));
  H.add_edge(Edge(6, 4));
  H.add_edge(Edge(6, 9));
  H.add_edge(Edge(8, 7));
  H.add_edge(Edge(7, 6));
  H.add_edge(Edge(4, 9));
  H.add_edge(Edge(9, 10));
  H.add_edge(Edge(9, 11));
  H.add_edge(Edge(9, 12));
  H.add_edge(Edge(11, 12));

  test_topological_sort(H);

  return 0;
}
