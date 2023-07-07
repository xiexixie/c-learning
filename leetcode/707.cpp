/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
#include <iostream>
class MyLinkedList
{
public:
  MyLinkedList()
  {
    // 这里的head实际是虚拟头节点
    head = new LinkedNode(0);
    size = 0;
  }

  int get(int index)
  {
    LinkedNode *current = head;
    int count = 0;
    while (current != nullptr)
    {
      if (count == index + 1)
      {
        return current->val;
      }
      current = current->next;
      count++;
    }
    return -1;
  }

  void addAtHead(int val)
  {
    LinkedNode *node = new LinkedNode(val);
    node->next = head->next;
    head->next = node;
    size++;
  }

  void addAtTail(int val)
  {
    LinkedNode *current = head;
    while (current->next != nullptr)
      current = current->next;
    LinkedNode *node = new LinkedNode(val);
    current->next = node;
    size++;
  }

  void addAtIndex(int index, int val)
  {
    if (index == 0)
    {
      addAtHead(val);
      return;
    }
    if (index > size)
      return;
    LinkedNode *node = head;
    int count = 0;

    while (node != nullptr)
    {
      if (count == index)
        break;
      count++;
      node = node->next;
    }
    LinkedNode *new_node = new LinkedNode(val);
    LinkedNode *temp = node->next;
    node->next = new_node;
    new_node->next = temp;
    size++;
  }

  void deleteAtIndex(int index)
  {
    if (index == 0)
    {
      LinkedNode *n = head->next;
      head->next = n->next;
      delete n;
      size--;
      return;
    }
    if (index >= size)
      return;
    LinkedNode *node = head;
    int count = 0;
    while (node != nullptr)
    {
      if (count == index)
        break;
      count++;
      node = node->next;
    }
    LinkedNode *temp = node->next->next;
    delete node->next;
    node->next = temp;
    size--;
  }

private:
  struct LinkedNode
  {
    int val;
    LinkedNode *next;
    LinkedNode(int val) : val(val), next(nullptr) {}
  };
  LinkedNode *head;
  int size;
};

/*
["MyLinkedList","addAtHead","deleteAtIndex","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtTail","get","deleteAtIndex","deleteAtIndex"]
[[],[2],[1],[2],[7],[3],[2],[5],[5],[5],[6],[4]]*/
int main()
{
  MyLinkedList *obj = new MyLinkedList();
  obj->addAtHead(2);
  obj->deleteAtIndex(1);
  obj->addAtHead(2);
  obj->addAtHead(7);
  obj->addAtHead(3);
  obj->addAtHead(2);
  obj->addAtHead(5);
  obj->addAtTail(5);
  int param_1 = obj->get(5);
  obj->deleteAtIndex(6);
  obj->deleteAtIndex(4);

  std::cout << param_1 << std::endl;
}
