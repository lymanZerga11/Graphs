template <typename Graph, typename Edge>
class PrimsMST {
private:
  const Graph &G;
  std::vector <double> min_weights;
  std::vector <Edge *> fringe, mst;
public:
  PrimsMST(const Graph &_G) : G(_G), fringe(G.v_count(), NULL), mst(G.v_count(), NULL), min_weights(G.v_count(), 1000){
    std::cout << "Beginning Prims MST Algorithm..." << std::endl;
    int min_vertex = -1;
    for (int v=0; min_vertex!=0; v=min_vertex) {
      //std::cout << "Vertex " << v << std::endl;
      min_vertex = 0;
      for (int w=1; w<G.v_count(); w++) {
        //std::cout << "Inner Vertex " << w << std::endl;
        if (!mst[w]) {
          Edge *e = G.get_edge(v, w);
          if (e) {
            double cur_weight = e->weight();
            if (cur_weight < min_weights[w]) {
              min_weights[w] = cur_weight;
              fringe[w] = e;
            }
          }
          if (min_weights[w] < min_weights[min_vertex]) min_vertex = w;
        }
      }
      if (min_vertex) mst[min_vertex] = fringe[min_vertex];
    }
    std::cout << "Exiting..." << std::endl;
  }

  void show(std::ostream& os) {
    double sum = 0;
    for(int i=0; i<mst.size(); i++) {
      if(!mst[i]) continue;
      sum += mst[i]->weight();
      os << mst[i]->v() << " - " << mst[i]->w() << std::endl;
    }
    os << "Total weight: " << sum <<std::endl;
  }
};
