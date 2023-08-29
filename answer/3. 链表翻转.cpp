#include <iostream>

// 链表翻转
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x, ListNode *n = nullptr) : val(x), next(n) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head);
    ListNode *reverseList_recur(ListNode *head);
    void deleteList(ListNode *head);
    void print(ListNode *head);
};

void Solution::deleteList(ListNode *head)
{
    ListNode *p = head;
    ListNode *q = nullptr;

    while (p != nullptr)
    {
        q = p->next;
        delete p;
        p = q;
    }
    std::cout << "deleteList" << std::endl;
}

ListNode *Solution::reverseList(ListNode *head)
{
    ListNode *cur = head;
    ListNode *prv = nullptr;
    ListNode *nxt = nullptr;

    while (cur != nullptr)
    {
        nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
    }
    return prv;
}

ListNode *reverseList_recur(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *newHead = reverseList_recur(head->next);
    head->next->next = newHead;
    return head;
}

void Solution::print(ListNode *head)
{
    ListNode *p = head;

    while (p != nullptr)
    {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main(void)
{
    // 测试代码
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution s;
    s.print(head);
    head = s.reverseList_recur(head);
    s.print(head);
    s.deleteList(head);
    return 0;
}