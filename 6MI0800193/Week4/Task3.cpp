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

ListNode* merge_lists(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr && l2 == nullptr)
        return nullptr;

    ListNode* merged_head = new ListNode;
    ListNode* merged_current = merged_head;


    while (l1 != nullptr && l2 != nullptr)
    {
        int min_el = l1->data;

        if (l2->data < min_el)
        {
            min_el = l2->data;
            l2 = l2->next;
        }
        else
            l1 = l1->next;

        merged_current->data = min_el;
        
        if (l1 != nullptr && l2 != nullptr)
        {
            merged_current->next = new ListNode;
            merged_current = merged_current->next;
        }
    }

    ListNode* leftover = (l1) ? l1 : l2;

    while (leftover != nullptr)
    {
        merged_current->data = leftover->data;

        if (leftover->next != nullptr)
        {
            merged_current->next = new ListNode;
            merged_current = merged_current->next;
        }

        leftover = leftover->next;

    }

    return merged_head;
}

int main()
{
    ListNode* list1 = new ListNode{ 1,  new ListNode{ 2, new ListNode{4, nullptr}}};
    ListNode* list2 = new ListNode{ 1,  new ListNode{ 3, new ListNode{4, nullptr}}};

    print_list(list1);
    print_list(list2);

    ListNode* merged = merge_lists(list1, list2);

    print_list(merged);


}
