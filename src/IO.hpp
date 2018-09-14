#ifndef GRAPH_ALGO_IO_HPP
#define GRAPH_ALGO_IO_HPP

#include <iostream>

namespace graph_algo {

template <class Graph> 
class IO {
public:
	static void show(std::ostream &, const Graph &);
	static void show(const Graph &);
	static void scanEZ(std::istream &, Graph &);
	static void scanEZ(Graph &);
	static void scan(Graph &);
};

template <class Graph> 
void IO<Graph>::show(std::ostream &out,const Graph &G)
{ 
	for (int s = 0; s < G.V(); s++) {
		out.width(2); out << s << ":";
		typename Graph::adjIterator A(G, s);
		for (int t = A.beg(); !A.end(); t = A.nxt()) { 
			out.width(2); out << t << " "; 
		}
		out << std::endl;
	}
}

template <class Graph> 
void IO<Graph>::show(const Graph &G)
{ 
	show(std::cout, G);
}

template <class Graph>
void IO<Graph>::scanEZ(std::istream &in, Graph &G)
{
	int v, w;
	while (in >> v >> w)
		if (v < G.V() && w < G.V())
			G.insert(Edge(v, w));
}

template <class Graph>
void IO<Graph>::scanEZ(Graph &G)
{
	scanEZ(std::cin, G);
}

}	// namespace 

#endif
