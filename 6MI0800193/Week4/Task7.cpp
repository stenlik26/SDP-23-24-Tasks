#include <iostream>
#include <vector>

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

void delete_nth_from_end(ListNode* head, int nth)
{
    //Edge case, remove_element doesn't work with the last one;
    if (nth == 1)
    {
        while (head->next->next != nullptr)
        {
            head = head->next;
        }
        head->next = nullptr;
        return;
    }

    std::vector<ListNode*> nodes;

    while (head != nullptr)
    {
        nodes.push_back(head);
        head = head->next;
    }

    remove_element(nodes[nodes.size() - nth]);
}

int main()
{
    ListNode* d = new ListNode{ 4, nullptr };
    ListNode* c = new ListNode{ 3, d };
    ListNode* b = new ListNode{ 2, c };
    ListNode* a = new ListNode{ 1, b };
    ListNode* list = new ListNode{ 0, a };

    delete_nth_from_end(list, 1);
    print_list(list);
}
