#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <cassert>

#ifdef USE_DENSE_GRAPH
#include "DenseGRAPH.hpp"
#else
#include "SparseMultiGRAPH.hpp"
#endif

#include "IO.hpp"
#include "JsonFileIO.hpp"
#include "BI.hpp"
#include "get_vc.hpp"

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

	auto G = JsonFileIO<GRAPH>::loadEZ(argv[1]);
	cout << "============== graph show ==============\n";
	IO<GRAPH>::show(*G);
	cout << endl;

	cout << G->E() << " edges ";

	BI<GRAPH> Gbi(*G);
	cout << "graph is bipartite? " << std::boolalpha << Gbi.bipartite() << endl;

    if (!Gbi.bipartite()) {
        return 1;
    }

	cout << "\n\n";
    cout << "    |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << i;
    cout << '\n';

    cout << "-----";
    for (int i = 0; i < G->V(); i++) cout << "---";
    cout << '\n';

    auto vc = get_vc(Gbi);
    assert(vc.size() == G->V());
    cout << "vc  |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << vc[i];
    cout << '\n';

    cout << endl;
	return 0;
}

