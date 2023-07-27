#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
  class m_greater
  {
  public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
      return a.second > b.second;
    }
  };

public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> m_map; //<num,频率>
    for (int i = 0; i < nums.size(); i++)
      m_map[nums[i]]++;

    // 小顶堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, m_greater> p_que;
    // 创建一个大小为k的优先队列
    for (auto it = m_map.begin(); it != m_map.end(); it++)
    {
      p_que.push(*it);
      if (p_que.size() > k)
        p_que.pop();
    }

    vector<int> result;
    for (int i = 0; i < k; i++)
    {
      result.push_back(p_que.top().first);
      p_que.pop();
    }
    return result;
  }
};

int main()
{
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  Solution s;
  s.topKFrequent(nums, k);
}