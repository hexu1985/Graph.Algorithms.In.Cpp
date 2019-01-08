#ifndef GRAPH_ALGO_SPARSEMULTIGRAPH_HPP
#define GRAPH_ALGO_SPARSEMULTIGRAPH_HPP

#include <vector>
#include <forward_list>
#include <algorithm>
#include "Edge.hpp"

namespace graph_algo {

class SparseMultiGRAPH { 
private:
	std::vector< std::forward_list<int> > adj;
	int Vcnt, Ecnt; 
	bool digraph;

    static bool found_in_list(const std::forward_list<int> &lst, int v)
    {
        return std::find(lst.begin(), lst.end(), v) != lst.end();
    }

public:
	SparseMultiGRAPH(int V, bool digraph = false) :
		adj(V), Vcnt(V), Ecnt(0), digraph(digraph) 
	{ 
	}

	int V() const { return Vcnt; }
	int E() const { return Ecnt; }
	bool directed() const { return digraph; }

	void insert(Edge e)
	{ 
		if (edge(e.v, e.w)) return;

		int v = e.v, w = e.w;
		adj[v].push_front(w);
		if (!digraph) adj[w].push_front(v);
		Ecnt++;
	} 

	void remove(Edge e)
	{ 
		int v = e.v, w = e.w;
        if (!found_in_list(adj[v], w))
            return;
        adj[v].remove(w);
		Ecnt--;

		if (digraph) return; 
        adj[w].remove(v);
	} 

	bool edge(int v, int w) const
	{
        return found_in_list(adj[v], w);
	}

	class adjIterator;
	friend class adjIterator;
};

class SparseMultiGRAPH::adjIterator { 
private:
	const SparseMultiGRAPH &G;
	int v;
    std::forward_list<int>::const_iterator iter;

public:
	adjIterator(const SparseMultiGRAPH &G, int v) : 
		G(G), v(v) { }

	int beg() { iter = G.adj[v].begin(); return iter != G.adj[v].end() ? *iter : -1; }
	int nxt() { if (iter != G.adj[v].end()) ++iter; return iter != G.adj[v].end() ? *iter : -1; }
	bool end() { return iter == G.adj[v].end(); }
};

}	// namespace

#endif
