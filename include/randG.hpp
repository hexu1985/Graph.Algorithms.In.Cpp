#ifndef GRAPH_ALGO_RANDG_HPP
#define GRAPH_ALGO_RANDG_HPP

#include <stdlib.h>
#include "Edge.hpp"

namespace graph_algo {

template <class Graph>
static void randG(Graph &G, int E)
{
	double p = 2.0*E/G.V()/(G.V()-1); 
	for (int i = 0; i < G.V(); i++) 
		for (int j = 0; j < i; j++)
			if (rand() < p*RAND_MAX)
				G.insert(Edge(i, j));
}

}	// namespace 

#endif
