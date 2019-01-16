#ifndef GRAPH_ALGO_DAGTS_HPP
#define GRAPH_ALGO_DAGTS_HPP

namespace graph_algo {

template <class Dag> 
class dagTS { 
private:
    const Dag &D;
    int cnt, tcnt;
    std::vector<int> pre, post, postI;

    void tsR(int v)
    { 
        pre[v] = cnt++;
        for (int w = 0; w < D.V(); w++)
            if (D.edge(w, v))
                if (pre[w] == -1) tsR(w);
        post[v] = tcnt; postI[tcnt++] = v;
    }

public:
    dagTS(const Dag &D) : D(D), tcnt(0), cnt(0),
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
