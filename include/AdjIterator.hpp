#ifndef GRAPH_ALGO_ADJTERATOR_HPP
#define GRAPH_ALGO_ADJTERATOR_HPP

namespace graph_algo {

template <class Graph> 
class AdjIterator {
private:
	typename Graph::adjIterator A;
	bool has_next = false;
	int t = -1;

public:
	AdjIterator(const Graph &G, int v): A(G, v) {
		t = A.beg();
		if (t == -1)
			has_next = false;
		else
			has_next = true;
	}

	bool hasNext() {
		return has_next;
	}

	int next() {
		if (!hasNext()) {
			return -1;
		}

		int v = t;
		t = A.nxt();
		if (A.end()) {
			has_next = false;
		}

		return v;
	}
};

}	// namespace

#endif
