#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <cassert>

#include "GRAPH.hpp"
#include "IO.hpp"
#include "JsonFileIO.hpp"
#include "dagTS_reversed.hpp"
#include "get_pre.hpp"
#include "get_post.hpp"
#include "get_postI.hpp"

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
    dagTS<GRAPH> ts(*G);

    cout << "\n\n";
    cout << "     |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << i;
    cout << '\n';

    cout << "------";
    for (int i = 0; i < G->V(); i++) cout << "---";
    cout << '\n';

    auto pre = get_pre(ts);
    assert(pre.size() == G->V());
    cout << "pre  |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << pre[i];
    cout << '\n';

    auto post = get_post(ts);
    assert(post.size() == G->V());
    cout << "post |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << post[i];
    cout << '\n';

    auto postI = get_postI(ts);
    assert(postI.size() == G->V());
    cout << "postI|";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << postI[i];
    cout << '\n';

    cout << endl;
	return 0;
}

