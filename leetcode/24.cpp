
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
  ListNode *swapPairs(ListNode *head)
  {
    ListNode *empty_head = new ListNode();
    empty_head->next = head;
    ListNode *cur = empty_head;
    while (cur->next != nullptr && cur->next->next != nullptr) // 空链表或只有一个数据的链表
    {
      ListNode *temp = cur->next;
      ListNode *temp1 = cur->next->next->next;
      cur->next = cur->next->next;
      cur->next->next = temp;
      cur->next->next->next = temp1;
      cur = cur->next->next;
    }
    return empty_head->next;
  }
};