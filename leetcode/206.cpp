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
  // 递归法2
  ListNode *reverseList2(ListNode *head)
  {
    // 边缘条件判断
    if (head == nullptr)
      return nullptr;
    if (head->next == nullptr)
      return head;

    // 递归调用，翻转第二个节点开始往后的链表
    ListNode *last = reverseList(head->next);
    // 翻转头节点与第二个节点的指向
    head->next->next = head;
    // 此时的 head 节点为尾节点，next 需要指向 NULL
    head->next = nullptr;
    return last;
  }
};