#include <fstream>
#include <iostream>
#include <stdlib.h>

#include "GRAPH.hpp"
#include "IO.hpp"

using namespace std;
using namespace graph_algo;

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
