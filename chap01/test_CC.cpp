#include <iostream>
#include <stdlib.h>

#include "GRAPH.hpp"
#include "IO.hpp"
#include "CC.hpp"

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
	if (V < 20) IO<GRAPH>::show(G);
	cout << G.E() << " edges ";

	CC<GRAPH> Gcc(G);
	cout << Gcc.count() << " components" << endl;

	return 0;
}
