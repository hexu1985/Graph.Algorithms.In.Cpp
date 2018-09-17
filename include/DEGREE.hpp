#ifndef GRAPH_ALGO_EDGES_HPP
#define GRAPH_ALGO_EDGES_HPP

#include <vector>

namespace graph_algo {

template <class Graph> 
class DEGREE { 
public:
	const Graph &G;
	std::vector<int> degree; 

public:
	DEGREE(const Graph &G) : G(G), degree(G.V(), 0) 
	{ 
		for (int v = 0; v < G.V(); v++) { 
			typename Graph::adjIterator A(G, v);
			for (int w = A.beg(); !A.end(); w = A.nxt()) 
				degree[v]++;
		}
	}

	int operator[](int v) const { return degree[v]; }
};

}	// namespace

#endif
