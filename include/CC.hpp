#ifndef GRAPH_ALGO_CC_HPP
#define GRAPH_ALGO_CC_HPP

#include <vector>

namespace graph_algo {

template <class Graph> 
class CC { 
    const Graph &G;
    int ccnt;
    std::vector<int> id; 

    void ccR(int w)
    { 
        id[w] = ccnt;
        typename Graph::adjIterator A(G, w);
        for (int v = A.beg(); !A.end(); v = A.nxt()) 
            if (id[v] == -1) ccR(v);
    }

public:
    CC(const Graph &G) : G(G), ccnt(0), id(G.V(), -1) 
    { 
        for (int v = 0; v < G.V(); v++)
            if (id[v] == -1) { ccR(v); ccnt++; } 
    }

    int count() const { return ccnt; }

    bool connect(int s, int t) const 
    { return id[s] == id[t]; }

    template <class T>
    friend const std::vector<int> &get_id(const T &t);
};

}	// namespace

#endif
