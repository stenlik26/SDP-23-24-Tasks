#include <iostream>
#include "linked_list.h"

//-----------------------Sort Func-----------------------------------------
/*
template<typename T>
void LinkedList<T>::sort(int(*cmp)(const T&, const T&))
{
	for (auto i = this->begin(); i != this->end(); ++i)
	{
		for (auto j = this->begin(); j != this->end(); ++j)
		{
			if ((*cmp)(*i, *j) == 1)
			{
				std::swap(*i, *j);	
			}
		}
	}
}
*/
//-------------------------------------------------------------------------


bool even(const int x)
{
    return x % 2 == 0;
}

bool odd(const int x)
{
    return x % 2 != 0;
}

template <typename T>
int compare_asc(const T& x, const T& y)
{
    if (x == y)
        return 0;
    if (x < y)
        return 1;
    else
        return -1;
}
template <typename T>
int compare_desc(const T& x, const T& y)
{
    if (x == y)
        return 0;
    if (x < y)
        return -1;
    else
        return 1;
}

template <typename T>
int even_odd_sort(const T& x, const T& y)
{
    if (even(x) == odd(y))
        return odd(x);
    else
        return even(x) ? (x > y) : (y > x);
}

void print_list(LinkedList<int> test)
{
    for (auto x : test)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main()
{
    LinkedList<int> test;
    test.insertFirst(6);
    test.insertFirst(2);
    test.insertFirst(3);
    test.insertFirst(7);
    test.insertFirst(1);
    test.insertFirst(4);
    test.insertFirst(5);
    test.insertFirst(8);
    test.insertFirst(9);
    test.insertFirst(10);

    print_list(test);

    /*
    test.sort(compare_asc);
    print_list(test);

    test.sort(compare_desc);
    print_list(test);
    */

    test.sort(even_odd_sort);
    print_list(test);
}
