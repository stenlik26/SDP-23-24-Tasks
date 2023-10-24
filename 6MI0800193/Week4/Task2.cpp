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

bool is_there_cycle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while (slow != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        std::cout << slow->data << " " << fast->data << std::endl;

        if (slow == fast)
            return true;
    }
    return false;
}


int main()
{
    ListNode* head = new ListNode{};
    head->data = 1;
    head->next = new ListNode{ 2, new ListNode{3, new ListNode{4, new ListNode{5, head}}} };
    is_there_cycle(head);

}
