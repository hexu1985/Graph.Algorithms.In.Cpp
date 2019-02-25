#ifndef GRAPH_ALGO_BFS_HPP
#define GRAPH_ALGO_BFS_HPP

#include "SEARCH.hpp"
#include "QUEUE.hpp"

namespace graph_algo {

// Breadth First Search
template <class Graph> 
class BFS: public SEARCH<Graph> { 
    std::vector<int> st;

    void searchC(Edge e)
    { 
        QUEUE<Edge> Q;
        Q.put(e); this->ord[e.w] = this->cnt++; 
        while (!Q.empty())
        {
            e = Q.get(); st[e.w] = e.v;        
            typename Graph::adjIterator A(this->G, e.w);
            for (int t = A.beg(); !A.end(); t = A.nxt()) 
                if (this->ord[t] == -1) 
                { Q.put(Edge(e.w, t)); this->ord[t] = this->cnt++; }
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
