#include <vector>
#include <iostream>
#include "edge.h"

class DenseGraph {
private:
  std::vector<std::vector<bool> > adjacency_matrix;
  bool directed;
public:
  DenseGraph(int v_count, bool _directed) : directed(_directed){
    adjacency_matrix = std::vector<std::vector<bool> >(v_count, std::vector<bool>(v_count, false));
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
  void add_edge(Edge e);
  void remove_edge(Edge e);
  bool is_directed () const;
  bool is_valid_edge (Edge e) const;
  bool is_edge (Edge e) const;
  void print_adj(std::ostream&) const;
  const_iterator begin(int) const;
  const_iterator end(int) const;
};

void DenseGraph::add_edge(Edge e){
  if(!is_valid_edge(e))
    return;
  adjacency_matrix[e.v][e.w] = true;
  if(!directed)
    adjacency_matrix[e.w][e.v] = true;
}

void DenseGraph::remove_edge(Edge e){
  if(!is_valid_edge(e))
    return;
  adjacency_matrix[e.v][e.w] = false;
  if(!directed)
    adjacency_matrix[e.w][e.v] = false;
}

void DenseGraph::print_adj(std::ostream &os) const {
  for(int i=0; i<adjacency_matrix.size(); i++) {
    for(int j=0; j<adjacency_matrix.size(); j++) {
      os << int(adjacency_matrix[i][j]) << " ";
    }
    os << std::endl;
  }
}

class DenseGraph::TestIterator {
private:
  const DenseGraph& G;
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
  int operator*() const {
    return adj_index;
  }
  int get_vertex() const {return vertex;}
  int get_index() const {return adj_index;}
};

int DenseGraph::v_count() const {return adjacency_matrix.size();}
bool DenseGraph::is_directed () const {return directed;}
bool DenseGraph::is_valid_edge (Edge e) const {return e.v < adjacency_matrix.size() && e.w < adjacency_matrix.size();}
bool DenseGraph::is_edge (Edge e) const {return adjacency_matrix[e.v][e.w];}
DenseGraph::TestIterator DenseGraph::begin (int _vertex) const {return DenseGraph::TestIterator(*this, _vertex, false);}
DenseGraph::TestIterator DenseGraph::end (int _vertex) const {return DenseGraph::TestIterator(*this, _vertex, true);}
