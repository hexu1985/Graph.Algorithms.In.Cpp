#ifndef GRAPH_ALGO_EULER_HPP
#define GRAPH_ALGO_EULER_HPP

#include <iostream>
#include "SEARCH.hpp"

namespace graph_algo {

template <class Graph> 
class EULER : public SEARCH<Graph> { 
    void searchC(Edge e)
    { 
        int v = e.v, w = e.w;
        this->ord[w] = this->cnt++;
        std::cout << "-" << w; 
        typename Graph::adjIterator A(this->G, w);
        for (int t = A.beg(); !A.end(); t = A.nxt()) 
            if (this->ord[t] == -1) searchC(Edge(w, t))
                ;
            else if (this->ord[t] < this->ord[v])
                std::cout << "-" << t << "-" << w;

        if (v != w) 
            std::cout << "-" << v; 
        else 
            std::cout << std::endl;  
    }

public:
    EULER(const Graph &G) : SEARCH<Graph>(G) 
    { this->search(); }
};

}	// namespace

#endif
