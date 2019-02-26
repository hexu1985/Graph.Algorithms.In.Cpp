#ifndef GRAPH_ALGO_BFS_HPP
#define GRAPH_ALGO_BFS_HPP

#include "SEARCH.hpp"
#include "QUEUE.hpp"

namespace graph_algo {

// Breadth-first search
// prog18.8
template <class Graph> 
class BFS: public SEARCH<Graph> { 
    std::vector<int> st;

    void searchC(Edge e)
    { 
        QUEUE<Edge> Q;  
        Q.put(e);
        while (!Q.empty())
            if (this->ord[(e = Q.get()).w] == -1) 
            { 
                int v = e.v, w = e.w;
                this->ord[w] = this->cnt++; st[w] = v;        
                typename Graph::adjIterator A(this->G, w);
                for (int t = A.beg(); !A.end(); t = A.nxt()) 
                    if (this->ord[t] == -1) Q.put(Edge(w, t));
            }
    }

public:
    BFS(Graph &G) : SEARCH<Graph>(G), st(G.V(), -1) 
    { this->search(); }

    int ST(int v) const { return st[v]; }

    template <class T>
    friend const std::vector<int> &get_st(const T &t);
};

}	// namespace

#endif
