#ifndef GRAPH_ALGO_EDGE_H
#define GRAPH_ALGO_EDGE_H

namespace Hx {

struct Edge {
	int v, w;
    Edge(int v = -1, int w = -1): v(v), w(w) { }
};

}	// namespace

#endif
