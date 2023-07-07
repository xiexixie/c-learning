#include <iostream>

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
  ListNode *removeElements(ListNode *head, int val)
  {
    // 虚拟头节点
    ListNode *empty_head = new ListNode(0, head);
    empty_head->next = head;
    ListNode *current = empty_head;
    while (current->next != nullptr)
    {
      if (current->next->val == val)
      {
        ListNode *temp = current->next;
        current->next = temp->next;
        delete temp;
      }
      else
      {
        current = current->next;
      }
    }
    head = empty_head->next;
    delete empty_head;
    return head;
  }
  ListNode *removeElements1(ListNode *head, int val)
  {
    // 一般方法   注意一定要判断当前是不是空指针
    while (head != nullptr && head->val == val)
    {
      ListNode *temp = head;
      head = head->next;
      delete temp;
    }
    ListNode *current = head;
    while (current != nullptr && current->next != nullptr)
    {
      if (current->next->val == val)
      {
        ListNode *temp = current->next;
        current->next = temp->next;
        delete temp;
      }
      else
      {
        current = current->next;
      }
    }
    return head;
  }
};