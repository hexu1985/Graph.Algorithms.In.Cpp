#ifndef GRAPH_ALGO_GET_VC_HPP
#define GRAPH_ALGO_GET_VC_HPP

#include <vector>

namespace graph_algo {

template <class T>
const std::vector<int> &get_vc(const T &t)
{
    return t.vc;
}

}	// namespace

#endif

