#include <iostream>
#include "priority_queue.h"
int main()
{
    PriorityQueue<int> p_q;

    p_q.push(7, 1);
    p_q.push(5, 1);
    p_q.push(5, 2);
    p_q.push(3, 2);
    p_q.push(3, 6);
    p_q.push(20, 3);

    p_q.print();

    p_q.pop();
    p_q.pop();
    p_q.pop();
    p_q.push(132, 8);

    p_q.print();
}
