#ifndef GRAPH_ALGO_GET_PRE_HPP
#define GRAPH_ALGO_GET_PRE_HPP

#include <vector>

namespace graph_algo {

template <class T>
const std::vector<int> &get_pre(const T &t)
{
    return t.pre;
}

}	// namespace

#endif
