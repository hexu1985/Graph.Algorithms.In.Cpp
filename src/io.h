#ifndef GRAPH_ALGO_IO_H
#define GRAPH_ALGO_IO_H

namespace Hx {

template <class Graph> 
class IO {
public:
	static void show(const Graph &);
	static void scanEZ(Graph &);
	static void scan(Graph &);
};

}	// namespace

#endif
