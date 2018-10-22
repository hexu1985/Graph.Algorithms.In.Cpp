#ifndef GRAPH_ALGO_DFS_HPP
#define GRAPH_ALGO_DFS_HPP

#include "SEARCH.hpp"

namespace graph_algo {

template <class Graph> 
class DFS: public SEARCH<Graph> { 
    std::vector<int> st;

    void searchC(Edge e)
    { 
        int w = e.w; 
        this->ord[w] = this->cnt++; st[e.w] = e.v;
        typename Graph::adjIterator A(this->G, w);
        for (int t = A.beg(); !A.end(); t = A.nxt()) 
            if (this->ord[t] == -1) searchC(Edge(w, t));
    }

public:
    DFS(const Graph &G): SEARCH<Graph>(G), st(G.V(), -1) 
    { this->search(); } 

    int ST(int v) const { return st[v]; }
    const std::vector<int> &ST_array() const { return st; }
};

}	// namespace

#endif
