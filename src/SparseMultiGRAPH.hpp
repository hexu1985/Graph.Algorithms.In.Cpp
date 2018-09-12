#ifndef GRAPH_ALGO_SPARSEMULTIGRAPH_HPP
#define GRAPH_ALGO_SPARSEMULTIGRAPH_HPP

#include <vector>
#include "Edge.hpp"

namespace graph_algo {

class SparseMultiGRAPH { 
private:
	struct node { 
		int v; node *next;
		node(int x, node *t) { v = x; next = t; }
	};

	typedef node *link;

	std::vector<link> adj;
	int Vcnt, Ecnt; 
	bool digraph;

	static link remove_from_list(link &head, int v)
	{
		if (head == nullptr)	// list is empty
			return nullptr;
		link x = head;
		if (x->v == v) {	// found at head
			head = x->next;
			return x;
		}

		link y = x;
		for (x = x->next; x != nullptr && x->v != v; x = x->next, y = y->next)	// traverse list
			;
		if (x == nullptr) return nullptr;	// nofound
		y->next = x->next;
		return x;
	}

	static link find_from_list(link head, int v)
	{
		link x = nullptr;
		for (x = head; x != nullptr && x->v != v; x = x->next)
			;
		return x;
	}

public:
	SparseMultiGRAPH(int V, bool digraph = false) :
		adj(V), Vcnt(V), Ecnt(0), digraph(digraph) 
	{ 
		adj.assign(V, 0); 
	}

	int V() const { return Vcnt; }
	int E() const { return Ecnt; }
	bool directed() const { return digraph; }

	void insert(Edge e)
	{ 
		int v = e.v, w = e.w;
		adj[v] = new node(w, adj[v]);
		if (!digraph) adj[w] = new node(v, adj[w]); 
		Ecnt++;
	} 

	void remove(Edge e)
	{ 
		int v = e.v, w = e.w;
		link x = remove_from_list(adj[v], w);
		if (x == nullptr)
			return;
		delete x;
		Ecnt--;

		if (digraph) return; 
		x = remove_from_list(adj[w], v);
		if (x == nullptr)
			return;
		delete x;
	} 

	bool edge(int v, int w) const
	{
		link x = find_from_list(adj[v], w);
		return (x != nullptr);
	}

	class adjIterator;
	friend class adjIterator;
};

class SparseMultiGRAPH::adjIterator { 
private:
	const SparseMultiGRAPH &G;
	int v;
	link t;

public:
	adjIterator(const SparseMultiGRAPH &G, int v) : 
		G(G), v(v) { t = 0; }

	int beg() { t = G.adj[v]; return t ? t->v : -1; }
	int nxt() { if (t) t = t->next; return t ? t->v : -1; }
	bool end() { return t == 0; }
};

}	// namespace

#endif
