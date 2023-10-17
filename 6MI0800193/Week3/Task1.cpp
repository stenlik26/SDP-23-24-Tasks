#include <iostream>
#include "queue_with_stacks.hpp"
using namespace std;
void print_queue(QueueSt<int> t)
{
    while (!t.empty())
    {
        cout << t.peek() << " <- ";
        t.pop();
    }
    cout << endl;
}

int main()
{
    QueueSt<int> test_queue;

    test_queue.push(2);
    test_queue.push(3);
    test_queue.push(4);
    test_queue.push(5);

    print_queue(test_queue);

    test_queue.pop();
    test_queue.pop();

    test_queue.push(9);
    test_queue.push(19);

    print_queue(test_queue);
}
