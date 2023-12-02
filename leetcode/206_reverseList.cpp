#include <iostream>

using namespace std;

struct ListNode
{
    ListNode(int v) : val(v) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}
    int val = 0;
    ListNode* next = nullptr;

    void insertNode(ListNode* pNode)
    {
        next = pNode;
    }
    ListNode* insert(int v)
    {
        next = new ListNode(v);
        return next;
    }
};


void show(ListNode* head)
{
    auto* it = head;
    while (it != nullptr)
    {
        std::cout << it->val << ",";
        it = it->next;
    }
    std::cout << std::endl;
}

ListNode* reverseList(ListNode* head)
{
    if (head == nullptr)
    {
        return head;
    }
    ListNode* p = nullptr;
    ListNode* n = nullptr;
    while (head != nullptr)
    {
        n = head->next;
        head->next = p;
        p = head;
        head = n;
        // std::cout << p->val << endl;
    }
    return p;
}

int main (int argc, char* argv[])
{
    ListNode* head = new ListNode(1);
    auto* cur = head->insert(2);
    cur = cur->insert(3);
    cur = cur->insert(5);
    cur = cur->insert(7);
    cur = cur->insert(10);
    show(head);
    auto* result = reverseList(head);
    show(result);

    return 0;
}
