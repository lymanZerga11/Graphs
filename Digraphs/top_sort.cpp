#include <iostream>
//#include "dense_graph.h"

template <typename Graph>
class TopologicalSort {

private:
  const Graph &G;
  int depth, count, count_p;
  std::vector<int> pre, post, post_ordered;

  void dfs(Edge e) {
    int w = e.w;
    pre[w] = count++;
    typename Graph::const_iterator it = G.begin(w);
    for(it; it!=G.end(w); it++) {
      int next_vertex = *it;
      Edge x(w, next_vertex);
      if (pre[next_vertex] == -1) dfs(x);
    }
    post[w] = count_p; post_ordered[count_p++] = w;
  }

public:
  TopologicalSort(const Graph& _G) : G(_G) {
    count=0; count_p=0; depth=0;
    pre = std::vector<int>(G.v_count(), -1);
    post = std::vector<int>(G.v_count(), -1);
    post_ordered = std::vector<int>(G.v_count(), -1);
    for (int v=0; v<G.v_count(); v++)
      if (pre[v] == -1) dfs(Edge(v,v));
  }

  std::vector<int> get_reversed_order () {return post_ordered;}
};
