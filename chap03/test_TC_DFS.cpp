#include <iostream>
#include <stdlib.h>

#include "GRAPH.hpp"
#include "IO.hpp"
#include "JsonFileIO.hpp"
#include "TC_DFS.hpp"

using namespace std;
using namespace graph_algo;

int main(int argc, char *argv[])
{ 
	if (argc != 2) {
		cout << "usage: " << argv[0] << " filepath" << endl;
		exit(1);
	}

	auto G = JsonFileIO<GRAPH>::loadEZ(argv[1]);
	cout << "============== graph show ==============\n";
    IO<GRAPH>::showAdjMatrix(*G);
	cout << endl;

	cout << "total edges: " << G->E() << endl;

	cout << "\nTransitive Closure with Warshall's algorithm test\n";
    TC<GRAPH> tc(*G);

	cout << "============== TC graph show ==============\n";
    IO<GRAPH>::showAdjMatrix(get_Graph_TC(tc));
	cout << endl;

	cout << "total edges: " << get_Graph_TC(tc).E() << endl;

	return 0;
}

