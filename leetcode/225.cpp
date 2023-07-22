#include <queue>
using namespace std;

class MyStack
{
private:
  // 一个用于辅助
  queue<int> queue1, queue2;

public:
  MyStack()
  {
  }

  void push(int x)
  {
    queue1.push(x);
  }

  int pop()
  {
    int size = queue1.size();
    while (size > 1)
    {
      queue2.push(queue1.front());
      queue1.pop();
      size--;
    }
    int result = queue1.front();
    queue1.pop();
    queue1 = queue2;
    while (!queue2.empty())
      queue2.pop();
    return result;
  }

  int top()
  {
    int result = queue1.back();
    return result;
  }

  bool empty()
  {
    if (queue1.empty() && queue2.empty())
      return true;
    return false;
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */