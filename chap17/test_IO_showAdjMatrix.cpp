#include <iostream>
#include <stdlib.h>

#include "GRAPH.hpp"
#include "IO.hpp"

using namespace std;
using namespace graph_algo;

int main(int argc, char *argv[])
{ 
	if (argc != 2) {
		cout << "usage: " << argv[0] << " vcount" << endl;
		exit(1);
	}

	int V = atoi(argv[1]);
	GRAPH G(V);
	IO<GRAPH>::scanEZ(G);
	if (V < 20) IO<GRAPH>::showAdjMatrix(G);
	cout << G.E() << " edges " << endl;

	return 0;
}
