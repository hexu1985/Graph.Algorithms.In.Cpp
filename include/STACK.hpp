#ifndef GRAPH_ALGO_STACK_HPP
#define GRAPH_ALGO_STACK_HPP

#include <deque>
#include <stdexcept>

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

	Item &peek()
	{
		if (c.empty()) {
			throw std::underflow_error("STACK empty when pop");
		}
		return c.back();
	}
};

}	// namespace

#endif

