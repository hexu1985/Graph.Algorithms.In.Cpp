#ifndef GRAPH_ALGO_GET_ID_HPP
#define GRAPH_ALGO_GET_ID_HPP

#include <vector>

namespace graph_algo {

template <class T>
const std::vector<int> &get_id(const T &t)
{
    return t.id;
}

}	// namespace

#endif
