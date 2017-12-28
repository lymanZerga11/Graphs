#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
//#include "dense_graph.h"

template <typename Graph>
class SQTopologicalSort {

private:
  const Graph &G;
  int count, count_p;
  std::queue<int> sources;
  std::vector<int> in_counts;
  std::vector<int> order;

  void sort_helper() {
    for(int j=0; !sources.empty(); j++) {
      int current_vertex = sources.front();
      sources.pop();
      order.push_back(current_vertex);
      typename Graph::const_iterator it = G.begin(current_vertex);
      for (it; it!=G.end(current_vertex); it++) {
        if(--in_counts[*it] == 0)
          sources.push(*it);
      }
    }
  }

public:
  SQTopologicalSort(const Graph& _G) : G(_G), in_counts(std::vector<int>(G.v_count(), 0)) {
    for(int i=0; i<G.v_count(); i++) {
      typename Graph::const_iterator it = G.begin(i);
      for (it; it!=G.end(i); it++) {
        in_counts[*it]++;
      }
    }
    for(int i=0; i<G.v_count(); i++) {
      if(in_counts[i] == 0)
        sources.push(i);
    }
    sort_helper();
  }

  std::vector<int> get_reversed_order () {
    std::vector<int> reversed_order = order;
    std::reverse(reversed_order.begin(), reversed_order.end());
    return reversed_order;
  }

  std::vector<int> get_order () {
    return order;
  }

  bool has_cycle() {
    return order.size() != G.v_count();
  }
};
