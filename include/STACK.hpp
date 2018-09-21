#ifndef GRAPH_ALGO_STACK_HPP
#define GRAPH_ALGO_STACK_HPP

#include <deque>

namespace graph_algo {

template <class Item>
class STACK {
private:
	std::deque<Item> c;

public:
	int empty() const
	{
		return c.empty();
	}

	void push(Item item)
	{
		c.push_back(item);
	}

	Item pop()
	{
		if (c.empty()) {
			throw std::underflow_error("STACK empty when pop");
		}
		Item elem(c.back());
		c.pop_back();
		return elem;
	}
};

}	// namespace

#endif

