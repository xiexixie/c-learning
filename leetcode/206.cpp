/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    // 双指针法
    ListNode *pre = nullptr;
    ListNode *cur = head;
    ListNode *temp;
    while (cur != nullptr)
    {
      temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }
    return pre;
  }
  // 递归法
  ListNode *reverse(ListNode *pre, ListNode *cur)
  {
    if (cur == nullptr)
      return pre;
    ListNode *temp = cur->next;
    cur->next = pre;
    return reverse(cur, temp);
  }
  ListNode *reverseList1(ListNode *head)
  {
    return reverse(nullptr, head);
  }
};