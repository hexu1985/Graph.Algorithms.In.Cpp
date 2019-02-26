#ifndef GRAPH_ALGO_DAGTC_HPP
#define GRAPH_ALGO_DAGTC_HPP

#include <vector>
#include "Edge.hpp"

namespace graph_algo {

// Transitive closure of a DAG
// prog19.9
template <class tcDag, class Dag> 
class dagTC { 
private:
    const Dag &D;
    tcDag T; 
    int cnt;
    std::vector<int> pre;

    void tcR(int w)
    { 
        T.insert(Edge(w, w));
        pre[w] = cnt++;
        typename Dag::adjIterator A(D, w);
        for (int t = A.beg(); !A.end(); t = A.nxt())
        { 
            T.insert(Edge(w, t));
            if (pre[t] > pre[w]) continue;  // down edge
            if (pre[t] == -1) tcR(t);
            for (int i = 0; i < T.V(); i++)
                if (T.edge(t, i)) T.insert(Edge(w, i));
        }
    }

public:
    dagTC(const Dag &D): D(D), T(D.V(), true), cnt(0), pre(D.V(), -1)
    { 
        for (int v = 0; v < D.V(); v++) 
            if (pre[v] == -1) tcR(v); 
    }

    bool reachable(int v, int w) const 
    { return T.edge(v, w); }

    template <class T>
    friend const std::vector<int> &get_pre(const T &t);

    template <class TcD, class D>
    friend const TcD &get_Graph_TC(const dagTC<TcD, D> &tc);
};

template <class TcD, class D>
const TcD &get_Graph_TC(const dagTC<TcD, D> &tc)
{
    return tc.T;
}

}	// namespace

#endif
