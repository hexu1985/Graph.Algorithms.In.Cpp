#ifndef GRAPH_ALGO_GRAPH_HPP
#define GRAPH_ALGO_GRAPH_HPP

#ifdef USE_DENSE_GRAPH
#include "DenseGRAPH.hpp"
#elif defined USE_SPARSE_MAULTI_GRAPH_ORIGIN
#include "SparseMultiGRAPH_origin.hpp"
#else
#include "SparseMultiGRAPH.hpp"
#endif

namespace graph_algo {

#ifdef USE_DENSE_GRAPH
using GRAPH = DenseGRAPH;
#else
using GRAPH = SparseMultiGRAPH;
#endif

}   // namespace

#endif
