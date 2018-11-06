#ifndef GRAPH_ALGO_GET_LOW_HPP
#define GRAPH_ALGO_GET_LOW_HPP

#include <vector>

namespace graph_algo {

template <class T>
const std::vector<int> &get_low(const T &t)
{
    return t.low;
}

}	// namespace

#endif
