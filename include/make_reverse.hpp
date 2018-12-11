#ifndef GRAPH_ALGO_MAKE_REVERSE_HPP
#define GRAPH_ALGO_MAKE_REVERSE_HPP

#include "reverse.hpp"

namespace graph_algo {

template <class Graph>
std::shared_ptr<Graph> make_reverse(const Graph &G)
{
     auto R = std::make_shared<Graph>(G.V(), G.directed());
     reverse(G, *R);
     return R;
}

}	// namespace

#endif
