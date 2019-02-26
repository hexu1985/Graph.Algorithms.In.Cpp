#ifndef GRAPH_ALGO_DFS_DIRECTED_HPP
#define GRAPH_ALGO_DFS_DIRECTED_HPP

#include <iostream>
#include <vector>

namespace graph_algo {

// DFS of a digraph
// prog19.2
template <class Graph> 
class DFS { 
    const Graph &G;
    int depth, cnt, cntP;
    std::vector<int> pre, post;

    void show(const char *s, Edge e)
    { 
        for (int i = 0; i < depth; i++) 
            std::cout << "  ";
        std::cout << e.v << "-" << e.w << s << std::endl; 
    }

    void dfsR(Edge e)
    { 
        int w = e.w; show(" tree", e);
        pre[w] = cnt++; depth++;
        typename Graph::adjIterator A(G, w);
        for (int t = A.beg(); !A.end(); t = A.nxt())
        { 
            Edge x(w, t);
            if (pre[t] == -1) dfsR(x);
            else if (post[t] == -1) show(" back", x);
            else if (pre[t] > pre[w]) show(" down", x);
            else show(" cross", x);
        }
        post[w] = cntP++; depth--;
    }

public:
    DFS(const Graph &G) : G(G), depth(0), cnt(0), cntP(0), 
        pre(G.V(), -1), post(G.V(), -1)
    { 
        for (int v = 0; v < G.V(); v++) 
            if (pre[v] == -1) dfsR(Edge(v, v)); 
    }

    template <class T>
    friend const std::vector<int> &get_pre(const T &t);

    template <class T>
    friend const std::vector<int> &get_post(const T &t);
};

}	// namespace

#endif
