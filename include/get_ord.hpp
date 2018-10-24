#ifndef GRAPH_ALGO_GET_ORD_HPP
#define GRAPH_ALGO_GET_ORD_HPP

#include <vector>

namespace graph_algo {

template <class T>
const std::vector<int> &get_ord(const T &t)
{
    return t.ord;
}

}	// namespace

#endif
