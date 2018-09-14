#include <fstream>
#include <iostream>
#include <stdlib.h>

#ifdef USE_DENSE_GRAPH
#include "DenseGRAPH.hpp"
#else
#include "SparseMultiGRAPH.hpp"
#endif

#include "FileIO.hpp"

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

	auto G = FileIO<GRAPH>::loadEZ(argv[1]);
	if (!G) {
		cout << "load graph from file \"" << argv[1] << "\" failed!" << endl;
		exit(1);
	}

	if (G->V() < 20) IO<GRAPH>::show(*G);
	cout << G->E() << " edges " << endl;

	return 0;
}
