#include <iostream>

template <typename Graph>
class TransitiveClosure {
private:
  Graph T;
public:
  TransitiveClosure(const Graph &G) : T(G) {
    for (int s = 0; s < T.v_count(); s++) {
      T.add_edge(Edge(s, s));
    }
    //T.print_adj(std::cout);
    for (int i = 0; i < T.v_count(); i++) {
      for (int s = 0; s < T.v_count(); s++) {
        if(T.is_edge(Edge(s, i))){
          for (int t = 0; t < T.v_count(); t++) {
            if(T.is_edge(Edge(i, t))){
              T.add_edge(Edge(s, t));
            }
          }
        }
      }
    }
  }

  bool is_reachable (int s, int t) {
    return T.is_edge(Edge(s, t));
  }
};
