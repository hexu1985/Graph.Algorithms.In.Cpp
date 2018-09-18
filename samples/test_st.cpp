#include <iostream>
#include <string>
#include "ST.hpp"

using namespace std;
using namespace graph_algo;

int main(int argc, char *argv[])
{
	string str;
	ST st;
	int i;
	while (getline(cin, str)) {
		i = st.index(str);
		cout << str << ": " << i << "\n";
	}
	cout << endl;

	return 0;
}
