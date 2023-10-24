#include <iostream>
#include <list>
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

ListNode* reverse_linked_list_iter(ListNode* head)
{
    ListNode* current = head, * prev = nullptr, * next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    return prev;
}

ListNode* reverse_linked_list_stack(ListNode* head)
{
    std::stack<int> values;

    if (head == nullptr)
        return nullptr;

    while (head != nullptr)
    {
        values.push(head->data);
        head = head->next;
    }

    ListNode* reversed_head = new ListNode{0, nullptr};
    ListNode* reversed_current = reversed_head;

    while (!values.empty())
    {
        reversed_current->data = values.top();
        values.pop();

        if (values.empty())
            break;

        reversed_current->next = new ListNode{ 0, nullptr };
        reversed_current = reversed_current->next;
    }

    return reversed_head;
}

ListNode* reverse_linked_list_rec(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* rest = reverse_linked_list_rec(head->next);

    head->next->next = head;

    head->next = nullptr;

    return rest;
}

int main()
{
    ListNode* head = new ListNode{ 1, new ListNode{ 2, new ListNode{3, new ListNode{4, new ListNode{5, nullptr}}} } };


    print_list(head);
    //ListNode* reversed = reverse_linked_list_rec(head);
    //ListNode* reversed = reverse_linked_list_iter(head);
    ListNode* reversed = reverse_linked_list_stack(head);
    print_list(reversed);

}
