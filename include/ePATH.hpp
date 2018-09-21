#ifndef GRAPH_ALGO_EPATH_HPP
#define GRAPH_ALGO_EPATH_HPP

#include <iostream>
#include "STACK.hpp"
#include "DEGREE.hpp"
#include "Edge.hpp"

namespace graph_algo {

template <class Graph> 
class ePATH { 
private:
	Graph G;
	int v, w;
	bool found;
	STACK<int> S;
	int tour(int v);

public:
	ePATH(const Graph &G, int v, int w): 
		G(G), v(v), w(w)
	{ 
		DEGREE<Graph> deg(G);
		int t = deg[v] + deg[w];
		if ((t % 2) != 0) { found = false; return; }
		for (t = 0; t < G.V(); t++)
			if ((t != v) && (t != w))
				if ((deg[t] % 2) != 0) 
				{ found = false; return; }
		found = true;
	}

	bool exists() const 
	{ return found; }

	void show();
};

template <class Graph>
int ePATH<Graph>::tour(int v)
{ 
	while (true) { 
		typename Graph::adjIterator A(G, v);
		int w = A.beg(); if (A.end()) break;
		S.push(v);
		G.remove(Edge(v, w));
		v = w;
	}
	return v;
}

template <class Graph>
void ePATH<Graph>::show()
{ 
	if (!found) return;
	while (tour(v) == v && !S.empty()) { 
		v = S.pop(); std::cout << "-" << v; 
	}
	std::cout << std::endl;    
}

}	// namespace

#endif

