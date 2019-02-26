#ifndef GRAPH_ALGO_DAGTS_REVERSED_HPP
#define GRAPH_ALGO_DAGTS_REVERSED_HPP

namespace graph_algo {

// Reverse topological sort
// prog19.6
template <class Dag> 
class dagTS { 
private:
    const Dag &D;
    int cnt, tcnt;
    std::vector<int> pre, post, postI;

    void tsR(int v)
    { 
        pre[v] = cnt++;
        typename Dag::adjIterator A(D, v);
        for (int t = A.beg(); !A.end(); t = A.nxt()) 
            if (pre[t] == -1) tsR(t);
        post[v] = tcnt; postI[tcnt++] = v;
    }

public:
    dagTS(const Dag &D) : D(D), cnt(0), tcnt(0),
        pre(D.V(), -1), post(D.V(), -1), postI(D.V(), -1)
    { 
        for (int v = 0; v < D.V(); v++)
            if (pre[v] == -1) tsR(v); 
    }

    int operator [](int v) const { return postI[v]; }
    int relabel(int v) const { return post[v]; }

    template <class T>
    friend const std::vector<int> &get_pre(const T &t);

    template <class T>
    friend const std::vector<int> &get_post(const T &t);

    template <class T>
    friend const std::vector<int> &get_postI(const T &t);
};

}	// namespace

#endif
