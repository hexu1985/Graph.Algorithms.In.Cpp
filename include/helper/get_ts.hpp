#ifndef GRAPH_ALGO_GET_TS_HPP
#define GRAPH_ALGO_GET_TS_HPP

#include <vector>

namespace graph_algo {

template <class T>
const std::vector<int> &get_ts(const T &t)
{
    return t.ts;
}

}	// namespace

#endif
