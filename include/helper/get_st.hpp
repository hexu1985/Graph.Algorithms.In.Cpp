#ifndef GRAPH_ALGO_GET_ST_HPP
#define GRAPH_ALGO_GET_ST_HPP

#include <vector>

namespace graph_algo {

template <class T>
const std::vector<int> &get_st(const T &t)
{
    return t.st;
}

}	// namespace

#endif
