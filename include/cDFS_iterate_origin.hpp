#ifndef GRAPH_ALGO_CDFS_ORIGIN_HPP
#define GRAPH_ALGO_CDFS_ORIGIN_HPP

#include <vector>
#include "STACK.hpp"
#include "AdjIterator.hpp"

namespace graph_algo {

template <class Graph> 
class cDFS { 
private:
    const Graph &G;
    int cnt = 0;
    std::vector<int> ord; 

    void searchC(int v)
    { 
        typedef AdjIterator<Graph> adjIterator; 
        STACK<adjIterator> S;
        ord[v] = cnt++;
        S.push(adjIterator(G, v));

        while (!S.empty()) {
            adjIterator &A = S.peek();
            bool has_new_pushed = false;
            while (A.hasNext()) {
                int t = A.next();
                if (ord[t] == -1) {
                    ord[t] = cnt++;
                    S.push(adjIterator(G, t));
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
