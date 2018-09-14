#include <fstream>
#include <iostream>
#include <stdlib.h>

#ifdef USE_DENSE_GRAPH
#include "DenseGRAPH.hpp"
#else
#include "SparseMultiGRAPH.hpp"
#endif

#include "IO.hpp"

using namespace std;
using namespace graph_algo;

#ifdef USE_DENSE_GRAPH
using GRAPH = DenseGRAPH;
#else
using GRAPH = SparseMultiGRAPH;
#endif

int main(int argc, char *argv[])
{ 
	if (argc != 2) {
		cout << "usage: " << argv[0] << " filepath" << endl;
		exit(1);
	}

	ifstream ifile(argv[1]);
	if (!ifile) {
		cout << "open graph data file \"" << argv[1] << "\" failed!" << endl;
		exit(1);
	}

	int V; 
	ifile >> V;
	GRAPH G(V);
	IO<GRAPH>::scanEZ(ifile, G);
	if (V < 20) IO<GRAPH>::show(G);
	cout << G.E() << " edges " << endl;

	return 0;
}
