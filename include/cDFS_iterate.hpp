#ifndef GRAPH_ALGO_CDFS_HPP
#define GRAPH_ALGO_CDFS_HPP

#include <vector>
#include <memory>
#include "STACK.hpp"
#include "QUEUE.hpp"

namespace graph_algo {

template <class Graph> 
class cDFS { 
private:
    const Graph &G;
    int cnt = 0;
    std::vector<int> ord; 

    std::shared_ptr<QUEUE<int>> make_adj_queue(int v)
    {
        auto Q = std::make_shared<QUEUE<int>>();
        typename Graph::adjIterator A(G, v);
        for (int t = A.beg(); !A.end(); t = A.nxt())
            if (ord[t] == -1) 
                Q->put(t);
        return Q;
    }

    void searchC(int v)
    { 
        STACK<std::shared_ptr<QUEUE<int>>> S;
        ord[v] = cnt++;
        S.push(make_adj_queue(v));

        while (!S.empty()) {
            auto Q = S.peek();
            bool has_new_pushed = false;
            while (!Q->empty()) {
                int t = Q->get();
                if (ord[t] == -1) {
                    ord[t] = cnt++;
                    S.push(make_adj_queue(t));
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
    cDFS(const Graph &G, int v = 0) : 
        G(G), cnt(0), ord(G.V(), -1) 
    { searchC(v); }

    int count() const { return cnt; }
    int operator [](int v) const { return ord[v]; }

    template <class T>
    friend const std::vector<int> &get_ord(const T &t);
};

}    // namespace

#endif
