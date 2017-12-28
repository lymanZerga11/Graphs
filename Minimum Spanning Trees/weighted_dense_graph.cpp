#include <vector>
#include <iostream>

template <typename Edge>
class DenseGraph {
private:
  std::vector<std::vector<Edge *> > adjacency_matrix;
  bool directed;
public:
  DenseGraph(int v_count, bool _directed) : directed(_directed){
    adjacency_matrix = std::vector<std::vector<Edge *> >(v_count, std::vector<Edge *>(v_count, NULL));
  };
  DenseGraph(const DenseGraph& G) : adjacency_matrix(G.adjacency_matrix), directed(G.directed){}
  DenseGraph operator=(const DenseGraph& G) {
    adjacency_matrix = G.adjacency_matrix;
    return *this;
  }

  class TestIterator;
  friend class TestIterator;

  typedef TestIterator iterator;
  typedef TestIterator const_iterator;

  int v_count () const;
  void add_edge(Edge *e);
  void remove_edge(Edge *e);
  bool is_directed () const;
  bool is_valid_edge (Edge *e) const;
  bool is_edge (Edge *e) const;
  Edge* get_edge (int v, int w) const;
  void print_adj(std::ostream&) const;
  const_iterator begin(int) const;
  const_iterator end(int) const;
};

template <typename Edge>
void DenseGraph<Edge>::add_edge(Edge *e){
  if(!is_valid_edge(e))
    return;
  adjacency_matrix[e->v()][e->w()] = e;
  if(!directed)
    adjacency_matrix[e->w()][e->v()] = e;
}

template <typename Edge>
void DenseGraph<Edge>::remove_edge(Edge *e){
  if(!is_valid_edge(e))
    return;
  adjacency_matrix[e->v()][e->w()] = NULL;
  if(!directed)
    adjacency_matrix[e->w()][e->v()] = NULL;
}

template <typename Edge>
void DenseGraph<Edge>::print_adj(std::ostream &os) const {
  for(int i=0; i<adjacency_matrix.size(); i++) {
    for(int j=0; j<adjacency_matrix.size(); j++) {
      if(adjacency_matrix[i][j])
        os << adjacency_matrix[i][j]->v() << " - " << adjacency_matrix[i][j]->w() << " : " << adjacency_matrix[i][j]->weight() << std::endl;
    }
  }
}

template <typename Edge>
class DenseGraph<Edge>::TestIterator {
private:
  const DenseGraph<Edge>& G;
  int adj_index;
  int vertex;
public:
  TestIterator(const DenseGraph& _G, int _vertex, bool end) : G(_G), vertex(_vertex), adj_index(-1) {
    adj_index++;
    while(adj_index < G.adjacency_matrix.size() && !G.adjacency_matrix[vertex][adj_index]) adj_index++;
    if (end) {
      adj_index = G.adjacency_matrix.size();
    }
  }
  TestIterator()=delete;
  void operator++(int) {
    adj_index++;
    while(adj_index < G.adjacency_matrix.size() && !G.adjacency_matrix[vertex][adj_index]) adj_index++;
  }
  bool operator!=(const TestIterator& ti) const{
    return ti.get_vertex() != get_vertex() || ti.get_index() != get_index();
  }
  bool operator==(const TestIterator& ti) const{
    return ti.get_vertex() == get_vertex() && ti.get_index() == get_index();
  }
  Edge* operator*() const {
    return adjacency_matrix[vertex][adj_index];
  }
  int get_vertex() const {return vertex;}
  int get_index() const {return adj_index;}
};

template <typename Edge>
int DenseGraph<Edge>::v_count() const {return adjacency_matrix.size();}
template <typename Edge>
bool DenseGraph<Edge>::is_directed () const {return directed;}
template <typename Edge>
bool DenseGraph<Edge>::is_valid_edge (Edge *e) const {return e->v() < adjacency_matrix.size() && e->w() < adjacency_matrix.size();}
template <typename Edge>
bool DenseGraph<Edge>::is_edge (Edge *e) const {return adjacency_matrix[e->v()][e->w()] != NULL;}
template <typename Edge>
Edge* DenseGraph<Edge>::get_edge (int v, int w) const {return adjacency_matrix[v][w];}
template <typename Edge>
typename DenseGraph<Edge>::TestIterator DenseGraph<Edge>::begin (int _vertex) const {return DenseGraph<Edge>::TestIterator(*this, _vertex, false);}
template <typename Edge>
typename DenseGraph<Edge>::TestIterator DenseGraph<Edge>::end (int _vertex) const {return DenseGraph<Edge>::TestIterator(*this, _vertex, true);}
