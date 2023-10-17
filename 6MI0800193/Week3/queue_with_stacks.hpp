#ifndef _queue_with_stacks
#define _queue_with_stacks

#include <stack>
template <typename T>
class QueueSt
{
private:
	std::stack<T> queue;
	std::stack<T> cache;

	void copy_to_cache();
	void copy_from_cache();

public:
	void push(const T& el);
	void pop();
	const T& peek();
	bool empty() const;
};
#endif

template<typename T>
void QueueSt<T>::copy_to_cache()
{
	while (!queue.empty())
	{
		cache.push(queue.top());
		queue.pop();
	}
}

template<typename T>
void QueueSt<T>::copy_from_cache()
{
	while (!cache.empty())
	{
		queue.push(cache.top());
		cache.pop();
	}
}

template<typename T>
void QueueSt<T>::push(const T& el)
{
	copy_to_cache();
	queue.push(el);
	copy_from_cache();
}

template<typename T>
void QueueSt<T>::pop()
{
	queue.pop();
}

template<typename T>
const T& QueueSt<T>::peek()
{
	return queue.top();
}

template<typename T>
inline bool QueueSt<T>::empty() const
{
	return queue.empty();
}
