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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *fast, *slow;
    fast = head;
    slow = head;
    while (n--)
    {
      fast = fast->next;
    }
    if (fast == nullptr)
    {
      ListNode *temp = head->next;
      delete head;
      return temp;
    }
    while (fast->next != nullptr)
    {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
  }
};