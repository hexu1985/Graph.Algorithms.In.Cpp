#ifndef GRAPH_ALGO_FILEIO_HPP
#define GRAPH_ALGO_FILEIO_HPP

#include <stdexcept>
#include <memory>
#include <fstream>
#include "IO.hpp"

namespace graph_algo {

template <class Graph> 
class FileIO {
public:
	static std::shared_ptr<Graph> loadEZ(const char *file_path, bool digraph=false);
};

template <class Graph> 
std::shared_ptr<Graph> FileIO<Graph>::loadEZ(const char *file_path, bool digraph)
{
	std::ifstream ifile(file_path);
	if (!ifile) {
		throw std::runtime_error(std::string("FileIO<Graph>::loadEZ file: \"")+file_path+"\" failed");
	}

	int V; 
	ifile >> V;
	auto G = std::make_shared<Graph>(V, digraph);
	IO<Graph>::scanEZ(ifile, *G);
	return G;
}

}	// namespace 

#endif
