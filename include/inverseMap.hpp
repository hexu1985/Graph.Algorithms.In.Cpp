#ifndef GRAPH_ALGO_INVERSEMAP_HPP
#define GRAPH_ALGO_INVERSEMAP_HPP

#include <vector>

namespace graph_algo {

std::vector<int> inverseMap(const std::vector<int> &vec)
{
    const int N = vec.size();
    std::vector<int> res(N);
    for (int i = 0; i < N; ++i) {
        res[vec[i]] = i;
    }

    return res;
}

}	// namespace

#endif
