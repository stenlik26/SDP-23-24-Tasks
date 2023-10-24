#include <iostream>
#include <list>

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

ListNode* get_min(ListNode* head, ListNode* min)
{
    if (head == nullptr)
        return min;

    if (min->data > head->data)
        return get_min(head->next, head);
    else
        return get_min(head->next, min);
}

ListNode* sort_list(ListNode* head)
{
    ListNode* head_cpy = head;
    while (head->next != nullptr)
    {
        ListNode* min = get_min(head->next, head->next);

        std::swap(head->data, min->data);

        head = head->next;
    }
    return head_cpy;
}

int main()
{
    ListNode* list1 = new ListNode{ 4,
        new ListNode{ 2,
        new ListNode{1,
        new ListNode{3,
        nullptr}}} };

    print_list(list1);

    sort_list(list1);

    print_list(list1);
}
