#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <iterator>

#ifdef USE_DENSE_GRAPH
#include "DenseGRAPH.hpp"
#else
#include "SparseMultiGRAPH.hpp"
#endif

#include "IO.hpp"
#include "JsonFileIO.hpp"
#ifdef USE_CDFS_ITERATE
#include "cDFS_iterate.hpp"
#elif defined USE_CDFS_ITERATE_ORIGIN
#include "cDFS_iterate_origin.hpp"
#else
#include "cDFS.hpp"
#endif
#include "get_ord.hpp"
#include "inverseMap.hpp"

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

	cout << "total edges: " << G->E() << endl;

	cout << "Depth-first search test, cin vertex search begin with, like: 0 (entry negative to exit)\n";
	while (true) {
		cout << "$ ";
		int v;
		cin >> v;
		if (v < 0 || !cin)
			break;
		if (v >= G->V()) {
			cout << "invalid vertex\n";
			continue;
		}

        cDFS<GRAPH> dfs(*G, v);
		cout << "\nvisit sequence of dfs begin with vertex " << v << ": " << endl;
        auto vec = inverseMap(get_ord(dfs));
        copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ", "));
        cout << "\n";
	}

    cout << endl;

	return 0;
}

