#ifndef GRAPH_ALGO_EDGES_HPP
#define GRAPH_ALGO_EDGES_HPP

#include "Edge.hpp"

namespace graph_algo {

template <class Graph> 
std::vector<Edge> edges(Graph &G)
{ 
	int E = 0;
	std::vector<Edge> a(G.E()); 
	for (int v = 0; v < G.V(); v++) {
		typename Graph::adjIterator A(G, v);
		for (int w = A.beg(); !A.end(); w = A.nxt()) 
			if (G.directed() || v < w)
				a[E++] = Edge(v, w);
	}
	return a;
}

}	// namespace

#endif
