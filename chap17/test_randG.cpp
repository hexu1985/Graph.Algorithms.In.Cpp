#include <iostream>
#include <stdlib.h>

#include "GRAPH.hpp"
#include "IO.hpp"
#include "randG.hpp"

using namespace std;
using namespace graph_algo;

int main(int argc, char *argv[])
{ 
	if (argc != 3) {
		cout << "usage: " << argv[0] << " vcount ecount" << endl;
		exit(1);
	}

	int V = atoi(argv[1]);
	int E = atoi(argv[2]);
	GRAPH G(V);
	randG(G, E);
	if (V < 20) IO<GRAPH>::show(G);
	cout << G.E() << " edges " << endl;

	return 0;
}
