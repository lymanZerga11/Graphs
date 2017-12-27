#pragma once

#include <vector>
#include "edge.h"

class DenseGraph {
private:
  std::vector<std::vector<bool> > adjacency_matrix;
public:
  DenseGraph()=delete;
  DenseGraph(int, bool);
  DenseGraph(const DenseGraph&);
  DenseGraph operator=(const DenseGraph&);

  typedef std::vector<bool>::iterator iterator;
  typedef std::vector<bool>::const_iterator const_iterator;

  int v_count () const;
  void add_edge(Edge e);
  void remove_edge(Edge e);
  bool is_directed () const;
  bool is_valid_edge (Edge e) const;
  bool is_edge (Edge e) const;
  const_iterator begin(int) const;
  const_iterator end(int) const;
};
