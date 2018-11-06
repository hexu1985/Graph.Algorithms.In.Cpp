#ifndef GRAPH_ALGO_EC_HPP
#define GRAPH_ALGO_EC_HPP

#include "SEARCH.hpp"

namespace graph_algo {

template <class Graph> 
class EC: public SEARCH<Graph> { 
    int bcnt;
    std::vector<int> low; 

    void searchC(Edge e)
    { 
        int w = e.w;
        this->ord[w] = this->cnt++; low[w] = this->ord[w];
        typename Graph::adjIterator A(this->G, w);
        for (int t = A.beg(); !A.end(); t = A.nxt()) 
            if (this->ord[t] == -1) 
            {
                searchC(Edge(w, t));
                if (low[w] > low[t]) low[w] = low[t];
                if (low[t] == this->ord[t]) 
                    bcnt++; // w-t is a bridge
            }
            else if (t != e.v)
                if (low[w] > this->ord[t]) low[w] = this->ord[t];
    }

public:
    EC(const Graph &G): SEARCH<Graph>(G), bcnt(0), low(G.V(), -1)
    { this->search(); }

    int count() const { return bcnt+1; }

    template <class T>
    friend const std::vector<int> &get_low(const T &t);
};

}	// namespace

#endif
