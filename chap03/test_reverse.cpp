#include <iostream>
#include <stdlib.h>

#include "GRAPH.hpp"
#include "IO.hpp"
#include "JsonFileIO.hpp"
#include "make_reverse.hpp"

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

    auto R = make_reverse(*G);
	cout << "============== reverse graph show ==============\n";
	IO<GRAPH>::show(*R);
	cout << endl;

	cout << "total edges: " << R->E() << endl;

	return 0;
}
