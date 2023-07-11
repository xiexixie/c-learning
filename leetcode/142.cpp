
// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  // 双指针法
  ListNode *detectCycle(ListNode *head)
  {
    ListNode *fast = head;
    ListNode *slow = head;
    // 不存在环，即链表中存在末尾
    while (fast != nullptr && fast->next != nullptr) // 注意必须fast判断在前，fast->next判断在后
    {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow)
      {
        ListNode *p1 = head;
        ListNode *p2 = fast;
        while (p1 != p2)
        {
          p1 = p1->next;
          p2 = p2->next;
        }
        return p1;
      }
    }
    return nullptr;
  }
};