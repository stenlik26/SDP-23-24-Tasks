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

void remove_element(ListNode* element)
{
    while (element != nullptr && element->next != nullptr)
    {
        element->data = element->next->data;

        if (element->next->next == nullptr)
            element->next = nullptr;

        element = element->next;
    }
}

int main()
{
    ListNode* d = new ListNode{ 4, nullptr };
    ListNode* c = new ListNode{ 3, d };
    ListNode* b = new ListNode{ 2, c };
    ListNode* a = new ListNode{ 1, b };
    ListNode* list = new ListNode{ 0, a };

    remove_element(c);
    print_list(list);
}
