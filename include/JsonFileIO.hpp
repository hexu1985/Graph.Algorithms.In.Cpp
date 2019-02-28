#ifndef GRAPH_ALGO_JSONFILEIO_HPP
#define GRAPH_ALGO_JSONFILEIO_HPP

#include <fstream>
#include "JsonIO.hpp"

namespace graph_algo {

template <class Graph> 
class JsonFileIO {
public:
	static std::shared_ptr<Graph> loadEZ(const char *file_path);
};

template <class Graph> 
std::shared_ptr<Graph> JsonFileIO<Graph>::loadEZ(const char *file_path)
{
	std::ifstream ifile(file_path);
	if (!ifile) {
		throw std::runtime_error(std::string("JsonFileIO<Graph>::loadEZ file: \"")+file_path+"\" failed");
	}

	return JsonIO<Graph>::loadEZ(ifile);
}

}	// namespace 

#endif

