#ifndef GRAPH_ALGO_IO_HPP
#define GRAPH_ALGO_IO_HPP

#include <iostream>

namespace graph_algo {

template <class Graph> 
class IO {
public:
	static void show(const Graph &);
	static void scanEZ(Graph &);
	static void scan(Graph &);
};

template <class Graph> 
void IO<Graph>::show(const Graph &G)
{ 
	for (int s = 0; s < G.V(); s++) 
	{
		std::cout.width(2); std::cout << s << ":";
		typename Graph::adjIterator A(G, s);
		for (int t = A.beg(); !A.end(); t = A.nxt()) 
		{ std::cout.width(2); std::cout << t << " "; }
		std::cout << std::endl;
	}
}

template <class Graph>
void IO<Graph>::scanEZ(Graph &G)
{
	int v, w;
	while (std::cin >> v >> w)
		if (v < G.V() && w < G.V())
			G.insert(Edge(v, w));
}

}	// namespace 

#endif
