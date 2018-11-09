#ifndef GRAPH_ALGO_QUEUE_HPP
#define GRAPH_ALGO_QUEUE_HPP

#include <deque>
#include <stdexcept>

namespace graph_algo {

template <class Item>
class QUEUE {
private:
	std::deque<Item> c;

public:
    int empty()
	{
		return c.empty();
	}

    void put(Item item)
    {
		c.push_back(item);
    }

    Item get()
	{
		if (c.empty()) {
			throw std::underflow_error("QUEUE empty when get");
		}
		Item elem(c.front());
		c.pop_front();
		return elem;
	}
};

}	// namespace

#endif

