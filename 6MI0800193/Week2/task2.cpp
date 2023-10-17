#include <iostream>
#include <stack>
#include <string>
using namespace std;

void print_stack(stack<int> c)
{
	while (!c.empty())
	{
		cout << c.top() << " ";
		c.pop();
	}
	cout << endl;
}


int main()
{
	int n, p;
	cin >> n;

	stack<int> plants;

	for (size_t i = 0; i < n; i++)
	{
		cin >> p;

		if (plants.empty())
		{
			plants.push(p);
			continue;
		}

		if (plants.top() >= p)
			plants.push(p);
	}
	//print_stack(plants);
	cout << plants.size() << endl;
}
