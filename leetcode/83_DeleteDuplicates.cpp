#include <iostream>

using namespace std;

struct ListNode
{
    ListNode(int v) : val(v) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}
    int val = 0;
    ListNode* next = nullptr;
};

ListNode* insert(ListNode* pNode, int val)
{
    pNode->next = new ListNode(val);
    return pNode->next;
}

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* itPre = head;
    ListNode* itCur = head->next;
    while (itCur != nullptr)
    {
        if (itCur->val == itPre->val)
        {
            // 前一个节点指向下一个节点
            itPre->next = itCur->next;
            // 销毁当前节点
            delete itCur;
            // 遍历下个节点
        }
        else
        {
            itPre = itCur;
        }
        itCur = itPre->next;
    }
    return head;
}

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

int main (int argc, char* argv[])
{
    std::cout << std::endl;
    ListNode* head = new ListNode(1);
    auto* cur = insert(head, 1);
    cur = insert(cur, 1);
    cur = insert(cur, 2);
    cur = insert(cur, 2);
    cur = insert(cur, 2);
    cur = insert(cur, 3);
    cur = insert(cur, 3);
    show (head);
    deleteDuplicates(head);
    show (head);
    return 0;
}
