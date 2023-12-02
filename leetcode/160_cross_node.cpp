#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

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
};

ListNode* insert(ListNode* pNode, int val)
{
    pNode->next = new ListNode(val);
    return pNode->next;
}

ListNode* getCrossNode(ListNode* headA, ListNode* headB)
{
    if (headA == nullptr || headB == nullptr)
    {
        return nullptr;
    }
    unordered_map<ListNode*, int> flagHash;
    while (headA != nullptr)
    {
        flagHash[headA] = 1;
        headA = headA->next;
    }
    while (headB != nullptr)
    {
        if (flagHash.find(headB) != flagHash.end())
        {
            return headB;
        }
        headB = headB->next;
    }
    return nullptr;
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
    ListNode* headA = new ListNode(1);
    ListNode* headB = new ListNode(2);
    auto* pCur = insert(headA, 3);
    pCur = insert(pCur, 5);
    pCur = insert(pCur, 7);
    auto* p7 = pCur;
    pCur = insert(pCur, 8);
    pCur = insert(pCur, 9);
    pCur = insert(pCur, 10);

    pCur = insert(headB, 4);
    pCur = insert(pCur, 6);
    pCur->insertNode(p7);

    show(headA);
    show(headB);
    auto* pCrossNode = getCrossNode(headA, headB);
    show(pCrossNode);
    return 0;
}
