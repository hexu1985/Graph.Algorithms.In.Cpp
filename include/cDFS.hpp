#ifndef GRAPH_ALGO_CDFS_HPP
#define GRAPH_ALGO_CDFS_HPP

#include <vector>

namespace graph_algo {

template <class Graph> 
class cDFS { 
private:
    int cnt = 0;
    const Graph &G;
    std::vector<int> ord; 

    void searchC(int v)
    { 
        ord[v] = cnt++;
        typename Graph::adjIterator A(G, v);
        for (int t = A.beg(); !A.end(); t = A.nxt()) 
            if (ord[t] == -1) searchC(t);
    }

public:
    cDFS(const Graph &G, int v = 0) : 
        G(G), cnt(0), ord(G.V(), -1) 
    { searchC(v); }

    int count() const { return cnt; }
    int operator [](int v) const { return ord[v]; }
};

}	// namespace

#endif
