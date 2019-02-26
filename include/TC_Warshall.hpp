#ifndef GRAPH_ALGO_TC_WARSHALL_HPP
#define GRAPH_ALGO_TC_WARSHALL_HPP

#include "Edge.hpp"

namespace graph_algo {

// Warshall’s algorithm
// computes the transitive closure
// prog19.3
template <class tcGraph, class Graph> 
class TC { 
    tcGraph T;

public:
    TC(const Graph &G) : T(G) 
    { 
        for (int s = 0; s < T.V(); s++) 
            T.insert(Edge(s, s));
        for (int i = 0; i < T.V(); i++)
            for (int s = 0; s < T.V(); s++)
                if (T.edge(s, i))
                    for (int t = 0; t < T.V(); t++)
                        if (T.edge(i, t))
                            T.insert(Edge(s, t));
    }

    bool reachable(int s, int t) const
    { return T.edge(s, t); }

    template <class TcG, class G>
    friend const TcG &get_Graph_TC(const TC<TcG, G> &tc);
};

template <class TcG, class G>
const TcG &get_Graph_TC(const TC<TcG, G> &tc)
{
    return tc.T;
}

}	// namespace

#endif

