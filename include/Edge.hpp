#ifndef GRAPH_ALGO_EDGE_HPP
#define GRAPH_ALGO_EDGE_HPP

namespace graph_algo {

struct Edge {
	int v, w;
	Edge(int v = -1, int w = -1): v(v), w(w) { }
};

}	// namespace

#endif
