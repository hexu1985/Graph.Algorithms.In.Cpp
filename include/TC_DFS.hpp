#ifndef GRAPH_ALGO_TC_DFS_HPP
#define GRAPH_ALGO_TC_DFS_HPP

#include "Edge.hpp"

namespace graph_algo {

template <class Graph> 
class TC { 
private:
    Graph T; 
    const Graph &G;

    void tcR(int v, int w)
    { 
        T.insert(Edge(v, w));
        typename Graph::adjIterator A(G, w);
        for (int t = A.beg(); !A.end(); t = A.nxt())
            if (!T.edge(v, t)) tcR(v, t);
    }

public:
    TC(const Graph &G) : G(G), T(G.V(), true)
    { for (int v = 0; v < G.V(); v++) tcR(v, v); }

    bool reachable(int v, int w)
    { return T.edge(v, w); }

    template <class G>
    friend const G &get_Graph_TC(const TC<G> &tc);
};

template <class G>
const G &get_Graph_TC(const TC<G> &tc)
{
    return tc.T;
}

}	// namespace

#endif

