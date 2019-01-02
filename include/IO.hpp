#ifndef GRAPH_ALGO_IO_HPP
#define GRAPH_ALGO_IO_HPP

#include <iostream>

namespace graph_algo {

template <class Graph> 
class IO {
public:
	static void show(std::ostream &, const Graph &);
	static void show(const Graph &);
	static void showAdjMatrix(std::ostream &, const Graph &);
	static void showAdjMatrix(const Graph &);
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
void IO<Graph>::showAdjMatrix(std::ostream &out, const Graph &G)
{
    out << "  |";
    for (int t = 0; t < G.V(); t++) {
        out.width(2); out << t << " ";
    }
    out << "\n";

    out << "---";
    for (int t = 0; t < G.V(); t++) {
        out << "---";
    }
    out << "\n";

    for (int v = 0; v < G.V(); v++) {
        out.width(2); out << v << "|";
        for (int w = 0; w < G.V(); w++) {
            out.width(2); out << static_cast<int>(G.edge(v,w)) << " ";
        }
        out << "\n";
    }
}

template <class Graph> 
void IO<Graph>::showAdjMatrix(const Graph &G)
{ 
	showAdjMatrix(std::cout, G);
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
