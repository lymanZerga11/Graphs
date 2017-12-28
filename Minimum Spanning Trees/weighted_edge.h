#pragma once

struct WeightedEdge {
  int _v, _w;
  double _weight;
  WeightedEdge (int _v, int _w, double _weight) : _v(_v), _w(_w), _weight(_weight) {}
  int v() {return _v;}
  int w() {return _w;}
  double weight() {return _weight;}
};
