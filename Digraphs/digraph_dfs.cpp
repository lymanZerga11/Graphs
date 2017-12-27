#include <iostream>
//#include "dense_graph.h"

template <typename Graph>
class DFS {

private:
  const Graph &G;
  int depth, count, count_p;
  std::vector<int> pre, post;

  void show(std::ostream& os, std::string s, Edge e) {
    for(int i=0; i<depth; i++) os << " ";
    os << e.v << "-" << e.w << s << std::endl;
  }

  void dfs(Edge e) {
    int w = e.w;
    show(std::cout, " tree ", e);
    pre[w] = count++; depth++;

    typename Graph::const_iterator it = G.begin(w);
    for(it; it!=G.end(w); it++) {
      int next_vertex = *it;
      Edge x(w, next_vertex);
      if (pre[next_vertex] == -1) dfs(x);
      else if (post[next_vertex] == -1) show(std::cout, " back ", x);
      else if (pre[next_vertex] > pre[w]) show(std::cout, " down ", x);
      else show(std::cout, " cross ", x);
    }
    post[w] = count_p++; depth--;
  }

public:
  DFS(const Graph& _G) : G(_G) {
    count=0; count_p=0; depth=0;
    pre = std::vector<int>(G.v_count(), -1);
    post = std::vector<int>(G.v_count(), -1);
    for (int v=0; v<G.v_count(); v++)
      if (pre[v] == -1) dfs(Edge(v,v));
  }
};
