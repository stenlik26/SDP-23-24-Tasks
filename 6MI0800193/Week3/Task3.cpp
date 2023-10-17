#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool check_sorted(int n, queue<int> elem)
{
	for (size_t i = 1; i <= n; i++)
	{
		if (elem.front() != i)
			return false;
		elem.pop();
	}
	return true;
}

bool can_be_sorted(int n, queue<int> el)
{
	int current = 1;
	queue<int> result_queue;
	stack<int> cache;

	while (!el.empty())
	{
		if (el.front() == current)
		{
			result_queue.push(el.front());
			current++;
			el.pop();
		}
		else if (!cache.empty() && cache.top() == current)
		{
			result_queue.push(cache.top());
			current++;
			cache.pop();
		}
		else
		{
			cache.push(el.front());
			el.pop();
		}

	}

	while (!cache.empty())
	{
		if (cache.top() != current)
			return false;

		result_queue.push(cache.top());
		cache.pop();
		current++;
	}
	return check_sorted(n, result_queue);
}

int main()
{
	int n;
	cin >> n;
	queue<int> input;

	for (size_t i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		input.push(temp);
	}

	cout << (can_be_sorted(n, input) ? "Yes" : "No") << endl;
}
