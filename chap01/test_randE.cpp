#include <iostream>
#include <stdlib.h>

#ifdef USE_DENSE_GRAPH
#include "DenseGRAPH.hpp"
#else
#include "SparseMultiGRAPH.hpp"
#endif

#include "IO.hpp"
#include "randE.hpp"

using namespace std;
using namespace graph_algo;

#ifdef USE_DENSE_GRAPH
using GRAPH = DenseGRAPH;
#else
using GRAPH = SparseMultiGRAPH;
#endif

int main(int argc, char *argv[])
{ 
	if (argc != 3) {
		cout << "usage: " << argv[0] << " vcount ecount" << endl;
		exit(1);
	}

	int V = atoi(argv[1]);
	int E = atoi(argv[2]);
	GRAPH G(V);
	randE(G, E);
	if (V < 20) IO<GRAPH>::show(G);
	cout << G.E() << " edges " << endl;

	return 0;
}
