#ifndef GRAPH_ALGO_GET_POST_HPP
#define GRAPH_ALGO_GET_POST_HPP

#include <vector>

namespace graph_algo {

template <class T>
const std::vector<int> &get_post(const T &t)
{
    return t.post;
}

}	// namespace

#endif
