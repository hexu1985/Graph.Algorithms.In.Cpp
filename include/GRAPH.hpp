
class GRAPH { private:
	// Implementation-dependent code
public:
	GRAPH(int, bool);
	~GRAPH();

	int V() const;
	int E() const;
	bool directed() const;
	int insert(Edge);
	int remove(Edge);
	bool edge(int, int);

	class adjIterator {
	public:
		adjIterator(const GRAPH &, int);
		int beg();
		int nxt();
		bool end();
	};
};
