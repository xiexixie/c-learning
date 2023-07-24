#include <vector>
#include <deque>

using namespace std;

class Solution
{
private:
  class Mydeque
  {
  private:
    deque<int> de;

  public:
    // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
    // 同时pop之前判断队列当前是否为空。
    void pop(int value)
    {
      if (!de.empty() && value == de.front())
      {
        de.pop_front();
      }
    }
    // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
    // 这样就保持了队列里的数值是单调从大到小的了。
    void push(int value)
    {
      while (!de.empty() && value > de.back())
      {
        de.pop_back();
      }
      de.push_back(value);
    }
    // 返回最大值
    int front()
    {
      return de.front();
    }
  };

public:
  // 单调队列
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    vector<int> result;
    Mydeque de;
    // 向单调队列中压入前K个
    for (int i = 0; i < k; i++)
    {
      de.push(nums[i]);
    }
    result.push_back(de.front());
    for (int i = k; i < nums.size(); i++)
    {
      de.pop(nums[i - k]);
      de.push(nums[i]);
      result.push_back(de.front());
    }
    return result;
  }
};