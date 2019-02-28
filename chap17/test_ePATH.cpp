#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "GRAPH.hpp"
#include "IO.hpp"
#include "JsonFileIO.hpp"
#include "ePATH.hpp"

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
	IO<GRAPH>::show(*G);
	cout << endl;

	cout << "total edges: " << G->E() << endl;

	cout << "path exists test, cin vertex pair, like: 3 7 (entry negative to exit)\n";
	while (true) {
		cout << "$ ";
		int v, w;
		cin >> v >> w;
		if (v < 0 || w < 0 || !cin)
			break;
		if (v >= G->V() || w >= G->V()) {
			cout << "invalid vertex\n";
			continue;
		}

		ePATH<GRAPH> epath(*G, v, w); 
		cout << (epath.exists() ? "Have " : "Have no ") 
			<< "path between " << v << " and " << w << endl;
		if (epath.exists()) {
			epath.show();
		}
	}

	return 0;
}

