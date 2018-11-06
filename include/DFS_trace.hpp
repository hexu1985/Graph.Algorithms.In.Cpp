#ifndef GRAPH_ALGO_DFS_TRACE_HPP
#define GRAPH_ALGO_DFS_TRACE_HPP

#include <iostream>
#include "SEARCH.hpp"

namespace graph_algo {

template <class Graph> 
class DFS: public SEARCH<Graph> { 
    std::vector<int> st;
    int depth = 0;

    void searchC(Edge e)
    { 
        int w = e.w; 
        this->ord[w] = this->cnt++; st[e.w] = e.v;
        std::cout << std::string(depth, '\t') << e.v << '-' << e.w << " tree\n";
        depth++;
        typename Graph::adjIterator A(this->G, w);
        for (int t = A.beg(); !A.end(); t = A.nxt()) {
            if (this->ord[t] == -1) searchC(Edge(w, t));
            else 
            {
                std::cout << std::string(depth, '\t') << w << '-' << t;
                if (t == st[w])
                    std::cout << " parent\n";
                else if (this->ord[t] < this->ord[w])
                    std::cout << " back\n";
                else
                    std::cout << " down\n";
            }
        }
        depth--;
    }

public:
    DFS(const Graph &G): SEARCH<Graph>(G), st(G.V(), -1) 
    { this->search(); } 

    int ST(int v) const { return st[v]; }

    template <class T>
    friend const std::vector<int> &get_st(const T &t);
};

}	// namespace

#endif
