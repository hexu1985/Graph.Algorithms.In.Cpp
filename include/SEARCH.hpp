#ifndef GRAPH_ALGO_SEARCH_HPP
#define GRAPH_ALGO_SEARCH_HPP

#include <vector>
#include "Edge.hpp"

namespace graph_algo {

template <class Graph> 
class SEARCH {
protected:
    const Graph &G;
    int cnt;

    std::vector<int> ord;
    virtual void searchC(Edge) = 0;

    void search()
    { 
        for (int v = 0; v < G.V(); v++)
            if (ord[v] == -1) searchC(Edge(v, v)); 
    }

public:
    SEARCH (const Graph &G): G(G), cnt(0), 
        ord(G.V(), -1) { }

    int operator[](int v) const { return ord[v]; }
    const std::vector<int> &ord_array() const { return ord; }
};

}	// namespace

#endif
