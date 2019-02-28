#include <fstream>
#include <iostream>
#include <stdlib.h>

#include "GRAPH.hpp"
#include "FileIO.hpp"

using namespace std;
using namespace graph_algo;

int main(int argc, char *argv[])
{ 
	if (argc != 2) {
		cout << "usage: " << argv[0] << " filepath" << endl;
		exit(1);
	}

	auto G = FileIO<GRAPH>::loadEZ(argv[1]);
	if (G->V() < 20) IO<GRAPH>::show(*G);
	cout << G->E() << " edges " << endl;

	return 0;
}
