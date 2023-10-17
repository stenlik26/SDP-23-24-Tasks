#ifndef _priority_queue
#define _priority_queue
#include <vector>
#include <iostream>
template <typename T>
struct PriorityPair
{
	T el;
	int priority;
};

template <typename T>
class PriorityQueue
{
private:
	std::vector<PriorityPair<T>> elements;

	void balance_priority();

public:
	void push(const T& element, int priority);
	const T& pop();
	const T& peek();
	bool empty() const;

	void print() const;
};

#endif // !_priority_queue

template<typename T>
void PriorityQueue<T>::balance_priority()
{
	int i, j;
	bool swapped;
	for (i = 0; i < elements.size() - 1; i++)
	{
		swapped = false;
		for (j = 0; j < elements.size() - i - 1; j++)
		{
			if (elements[j].priority <= elements[j + 1].priority)
			{
				std::swap(elements[j], elements[j + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

template<typename T>
void PriorityQueue<T>::push(const T& element, int prior)
{
	elements.push_back({ element, prior });
	balance_priority();
}

template<typename T>
const T& PriorityQueue<T>::pop()
{
	T el = this->peek();
	elements.pop_back();
	return el;
}

template<typename T>
const T& PriorityQueue<T>::peek()
{
	return elements[elements.size() - 1].el;
}

template<typename T>
bool PriorityQueue<T>::empty() const
{
	return elements.empty();
}

template<typename T>
void PriorityQueue<T>::print() const
{
	for (size_t i = 0; i < elements.size(); i++)
	{
		std::cout << "(" << elements[i].el << ", p:" << elements[i].priority << ") -> ";
	}
	std::cout << std::endl;
}
