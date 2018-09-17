#ifndef GRAPH_ALGO_JSONIO_HPP
#define GRAPH_ALGO_JSONIO_HPP

#include <memory>
#include <string>
#include "json11/json11.hpp"
#include "Edge.hpp"

namespace graph_algo {

template <class Graph> 
class JsonIO {
public:
	static std::shared_ptr<Graph> loadEZ(const json11::Json &);
	static std::shared_ptr<Graph> loadEZ(const std::string &);
};

template <class Graph> 
std::shared_ptr<Graph> JsonIO<Graph>::loadEZ(const json11::Json &json)
{
	int V = json["V"].int_value();
	bool digraph = json["digraph"].bool_value();
	auto G = std::make_shared<Graph>(V, digraph);

	auto &edges = json["edges"];
	int v, w;
	for (auto &edge: edges.array_items()) {
		v = edge[0].int_value();
		w = edge[1].int_value();
		if (v < V && w < V)
			G->insert(Edge(v, w));
	}
	return G;
}

template <class Graph> 
std::shared_ptr<Graph> JsonIO<Graph>::loadEZ(const std::string &str)
{
	std::string err;
	const auto json = json11::Json::parse(str, err);
	if (!err.empty()) {
		throw std::runtime_error("JsonIO<Graph>::loadEZ(\""+str+"\") error: "+err);
	}

	return loadEZ(json);
}

}	// namespace 

#endif

