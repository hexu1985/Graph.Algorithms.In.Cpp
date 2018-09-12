#include <iostream>
#include <stdlib.h>
#include "DenseGRAPH.hpp"
#include "IO.hpp"

using GRAPH = DenseGRAPH;

using namespace std;

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

	return 0;
}
