#ifndef GRAPH_ALGO_GET_POSTI_HPP
#define GRAPH_ALGO_GET_POSTI_HPP

#include <vector>

namespace graph_algo {

template <class T>
const std::vector<int> &get_postI(const T &t)
{
    return t.postI;
}

}	// namespace

#endif
