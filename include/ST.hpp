#ifndef GRAPH_ALGO_ST_HPP
#define GRAPH_ALGO_ST_HPP

#include <string>

namespace graph_algo {

class ST { 
private:
	struct node { 
		int v, d; 
		node *l, *m, *r;
		node(int d) : v(-1), d(d), l(0), m(0), r(0) {}
	};

	typedef node *link;
	link head;
	int N, val;

	link indexR(link h, const std::string &s, int w)
	{ 
		int i = s[w];
		if (h == 0) h = new node(i);
		if (i == 0) {
			if (h->v == -1) h->v = N++;
			val = h->v;
			return h;
		}
		if (i < h->d) h->l = indexR(h->l, s, w);
		if (i == h->d) h->m = indexR(h->m, s, w+1);
		if (i > h->d) h->r = indexR(h->r, s, w);
		return h;
	}

public:
	ST() : head(0), N(0) { }

	int index(const std::string &key)
	{
		head = indexR(head, key, 0); 
		return val; 
	}
};

}	// namespace 

#endif

