#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <cassert>

#include "GRAPH.hpp"
#include "IO.hpp"
#include "JsonFileIO.hpp"
#include "CC.hpp"
#include "get_id.hpp"

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

	CC<GRAPH> Gcc(*G);
	cout << Gcc.count() << " components" << endl;

	cout << "\n\n";
    cout << "    |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << i;
    cout << '\n';

    cout << "-----";
    for (int i = 0; i < G->V(); i++) cout << "---";
    cout << '\n';

    auto id = get_id(Gcc);
    assert(id.size() == G->V());
    cout << "id  |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << id[i];
    cout << '\n';

    cout << endl;
	return 0;
}

