#ifndef GRAPH_ALGO_DFS_HPP
#define GRAPH_ALGO_DFS_HPP

#include <memory>
#include "SEARCH.hpp"
#include "STACK.hpp"
#include "QUEUE.hpp"

namespace graph_algo {

template <class Graph> 
class DFS: public SEARCH<Graph> { 
    std::vector<int> st;

    typedef QUEUE<Edge> EdgeQueue;
    typedef std::shared_ptr<EdgeQueue> EdgeQueuePtr;

    EdgeQueuePtr make_adj_queue(int w)
    {
        auto Q = std::make_shared<EdgeQueue>();
        typename Graph::adjIterator A(this->G, w);
        for (int t = A.beg(); !A.end(); t = A.nxt())
            if (this->ord[t] == -1) 
                Q->put(Edge(w, t));
        return Q;
    }

    void searchC(Edge e)
    { 
        STACK<EdgeQueuePtr> S;
        int w = e.w; 
        this->ord[w] = this->cnt++; st[e.w] = e.v;
        S.push(make_adj_queue(e.w));

        while (!S.empty()) {
            auto Q = S.peek();
            bool has_new_pushed = false;
            while (!Q->empty()) {
                e = Q->get();
                w = e.w;
                if (this->ord[w] == -1) {
                    this->ord[w] = this->cnt++; st[e.w] = e.v;
                    S.push(make_adj_queue(e.w));
                    has_new_pushed = true;
                    break;
                }
            }
            if (!has_new_pushed) {
                S.pop();
            }
        }
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
