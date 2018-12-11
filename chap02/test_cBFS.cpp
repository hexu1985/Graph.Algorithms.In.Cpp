#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <iterator>

#include "GRAPH.hpp"
#include "IO.hpp"
#include "JsonFileIO.hpp"
#ifdef USE_CBFS_ORIGIN
#include "cBFS_origin.hpp"
#else
#include "cBFS.hpp"
#endif
#include "get_ord.hpp"
#include "inverseMap.hpp"

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

    cout << "Depth-first search test, cin vertex search begin with, like: 0 (entry negative to exit)\n";
    while (true) {
        cout << "$ ";
        int v = 0;
        //		cin >> v;
        if (v < 0 || !cin)
            break;
        if (v >= G->V()) {
            cout << "invalid vertex\n";
            continue;
        }

        cBFS<GRAPH> bfs(*G, v);
        cout << "\nvisit sequence of bfs begin with vertex " << v << ": " << endl;
        auto vec = inverseMap(get_ord(bfs));
        copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ", "));
        cout << "\n";
        break;
    }

    cout << endl;

    return 0;
}

