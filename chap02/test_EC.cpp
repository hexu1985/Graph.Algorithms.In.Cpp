#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <cassert>

#include "GRAPH.hpp"
#include "IO.hpp"
#include "JsonFileIO.hpp"
#include "EC.hpp"
#include "get_ord.hpp"
#include "get_low.hpp"

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

	cout << G->E() << " edges ";

	EC<GRAPH> Gec(*G);
	cout << Gec.count() << " edge-connected components" << endl;

	cout << "\n\n";
    cout << "    |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << i;
    cout << '\n';

    cout << "-----";
    for (int i = 0; i < G->V(); i++) cout << "---";
    cout << '\n';

    auto ord = get_ord(Gec);
    assert(ord.size() == G->V());
    cout << "ord |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << ord[i];
    cout << '\n';

    auto low = get_low(Gec);
    assert(low.size() == G->V());
    cout << "low |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << low[i];
    cout << '\n';

    cout << endl;
	return 0;
}

