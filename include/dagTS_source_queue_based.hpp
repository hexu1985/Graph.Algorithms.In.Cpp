#ifndef GRAPH_ALGO_DAGTS_SOURCE_QUEUE_BASED_HPP
#define GRAPH_ALGO_DAGTS_SOURCE_QUEUE_BASED_HPP

#include "QUEUE.hpp"

namespace graph_algo {

// Source-queue–based topological sort
// prog19.8
template <class Dag> 
class dagTS { 
private:
    const Dag &D;
    std::vector<int> in, ts, tsI;

public:
    dagTS(const Dag &D) : D(D), 
        in(D.V(), 0), ts(D.V(), -1), tsI(D.V(), -1) 
    { 
        QUEUE<int> Q;

        for (int v = 0; v < D.V(); v++) 
        {
            typename Dag::adjIterator A(D, v);
            for (int t = A.beg(); !A.end(); t = A.nxt()) 
                in[t]++;
        }

        for (int v = 0; v < D.V(); v++)
            if (in[v] == 0) Q.put(v);

        for (int j = 0; !Q.empty(); j++) 
        {
            ts[j] = Q.get(); tsI[ts[j]] = j;
            typename Dag::adjIterator A(D, ts[j]);
            for (int t = A.beg(); !A.end(); t = A.nxt()) 
                if (--in[t] == 0) Q.put(t);
        }
    }

    int operator[](int v) const { return ts[v]; }
    int relabel(int v) const { return tsI[v]; }

    template <class T>
    friend const std::vector<int> &get_ts(const T &t);

    template <class T>
    friend const std::vector<int> &get_tsI(const T &t);
};

}	// namespace

#endif
