#ifndef GRAPH_ALGO_JSONIO_HPP
#define GRAPH_ALGO_JSONIO_HPP

#include <memory>
#include <string>
#include <iostream>
#include "nlohmann/json.hpp"

#include "Edge.hpp"

namespace graph_algo {

template <class Graph> 
class JsonIO {
public:
	static std::shared_ptr<Graph> loadEZ(const std::string &);
	static std::shared_ptr<Graph> loadEZ(std::istream &);

private:
	static std::shared_ptr<Graph> loadHelper(const nlohmann::json &);
};

template <class Graph> 
std::shared_ptr<Graph> JsonIO<Graph>::loadHelper(const nlohmann::json &json)
{
	int V = json["V"].get<int>();
	bool digraph = json["digraph"].get<bool>();
	auto G = std::make_shared<Graph>(V, digraph);

	auto &edges = json["edges"];
	int v, w;
	for (auto &edge: edges) {
		v = edge[0].get<int>();
		w = edge[1].get<int>();
		if (v < V && w < V)
			G->insert(Edge(v, w));
	}
	return G;
}

template <class Graph> 
std::shared_ptr<Graph> JsonIO<Graph>::loadEZ(const std::string &str)
{
	const auto json = nlohmann::json::parse(str);
	return loadHelper(json);
}

template <class Graph> 
std::shared_ptr<Graph> JsonIO<Graph>::loadEZ(std::istream &in)
{
	nlohmann::json json;
	in >> json;
	return loadHelper(json);
}

}	// namespace 

#endif

