#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "GRAPH.hpp"
#include "IO.hpp"
#include "JsonFileIO.hpp"
#include "DEGREE.hpp"

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

	DEGREE<GRAPH> dgree(*G);
	cout << "\n============== graph dgree ==============\n";
	int total_degrees = 0;
	for (int s = 0; s < G->V(); s++) {
		cout << setw(2) << s << ":" << setw(2) << dgree[s] << "\n";
		total_degrees += dgree[s];
	}
	cout << endl;

	cout << "total degrees: " << total_degrees << endl;

	return 0;
}
