
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
// 链表相交
class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    int lenA = getLen(headA);
    int lenB = getLen(headB);
    ListNode *cura = headA;
    ListNode *curb = headB;
    int gap;
    if (lenA > lenB)
    {
      gap = lenA - lenB;
      while (gap--)
        cura = cura->next;
      while (lenB--)
      {
        if (cura == curb)
          return cura;
        cura = cura->next;
        curb = curb->next;
      }
      return nullptr;
    }
    else
    {
      gap = lenB - lenA;
      while (gap--)
        curb = curb->next;
      while (lenA--)
      {
        if (cura == curb)
          return cura;
        cura = cura->next;
        curb = curb->next;
      }
      return nullptr;
    }
  }
  int getLen(ListNode *head)
  {
    int count = 0;
    while (head != nullptr)
    {
      head = head->next;
      count++;
    }
    return count;
  }
};