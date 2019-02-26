#ifndef GRAPH_ALGO_CBFS_HPP
#define GRAPH_ALGO_CBFS_HPP

#include <vector>
#include "QUEUE.hpp"

namespace graph_algo {

template <class Graph> 
class cBFS { 
private:
    const Graph &G;
    int cnt = 0;
    std::vector<int> ord; 

    void searchC(int v)
    { 
        QUEUE<int> Q;  
        Q.put(v); ord[v] = cnt++;
		while (!Q.empty()) 
        {
            v = Q.get();
            typename Graph::adjIterator A(G, v);
            for (int t = A.beg(); !A.end(); t = A.nxt())
                if (ord[t] == -1) 
                { Q.put(t); ord[t] = cnt++; }
        }
    }

public:
    cBFS(const Graph &G, int v = 0) : 
        G(G), cnt(0), ord(G.V(), -1) 
    { searchC(v); }

    int count() const { return cnt; }
    int operator [](int v) const { return ord[v]; }

    template <class T>
    friend const std::vector<int> &get_ord(const T &t);
};

}	// namespace

#endif
