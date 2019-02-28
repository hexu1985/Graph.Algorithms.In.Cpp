#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <cassert>

#include "GRAPH.hpp"
#include "IO.hpp"
#include "JsonFileIO.hpp"
#include "dagTS_source_queue_based.hpp"
#include "get_ts.hpp"
#include "get_tsI.hpp"

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

	cout << "\nReverse Topological Sort test\n";
    dagTS<GRAPH> Gts(*G);

    cout << "\n\n";
    cout << "   |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << i;
    cout << '\n';

    cout << "----";
    for (int i = 0; i < G->V(); i++) cout << "---";
    cout << '\n';

    auto ts = get_ts(Gts);
    assert(ts.size() == G->V());
    cout << "ts |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << ts[i];
    cout << '\n';

    auto tsI = get_tsI(Gts);
    assert(tsI.size() == G->V());
    cout << "tsI|";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << tsI[i];
    cout << '\n';

    cout << endl;
	return 0;
}

