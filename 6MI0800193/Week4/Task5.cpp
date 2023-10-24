#include <iostream>
#include <stack>

struct ListNode
{
    int data;
    ListNode* next;
};

void print_list(ListNode* head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

ListNode* add_numbers(ListNode* a, ListNode* b)
{
    if (a == nullptr && b == nullptr)
        return nullptr;

    std::stack<int> a_vals;
    std::stack<int> b_vals;

    while (a != nullptr)
    {
        a_vals.push(a->data);
        a = a->next;
    }

    while (b != nullptr)
    {
        b_vals.push(b->data);
        b = b->next;
    }

    ListNode* output = new ListNode{ 0, nullptr };
    ListNode* output_current = output;

    int carry = 0;
    while (!a_vals.empty() || !b_vals.empty())
    {
        int to_add_a = 0, to_add_b = 0;

        if (!a_vals.empty())
        {
            to_add_a = a_vals.top();
            a_vals.pop();
        }

        if (!b_vals.empty())
        {
            to_add_b = b_vals.top();
            b_vals.pop();
        }

        output_current->data = (to_add_a + to_add_b) % 10 + carry;
        carry = (to_add_a + to_add_b) / 10;

        if (!a_vals.empty() || !b_vals.empty())
        {
            output_current->next = new ListNode{ 0, nullptr };
            output_current = output_current->next;
        }
    }
    return output;
}

int main()
{
    ListNode* a = new ListNode{ 2, new ListNode{4, new ListNode{3, nullptr}} };
    ListNode* b = new ListNode{ 5, new ListNode{6, new ListNode{4, nullptr}} };

    ListNode* sum = add_numbers(a, b);

    print_list(sum);
}
