#ifndef GRAPH_ALGO_GET_TSI_HPP
#define GRAPH_ALGO_GET_TSI_HPP

#include <vector>

namespace graph_algo {

template <class T>
const std::vector<int> &get_tsI(const T &t)
{
    return t.tsI;
}

}	// namespace

#endif
