#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
  // 滑动窗口法和哈希表
  int totalFruit(vector<int> &fruits)
  {
    int left = 0, right;
    int result = 0;
    std::map<int, int> backet;
    for (right = 0; right < fruits.size(); right++)
    {
      backet[fruits[right]]++;
      while (backet.size() > 2)
      {
        backet[fruits[left]]--;
        if (backet[fruits[left]] == 0)
          backet.erase(fruits[left]);
        left++;
      }
      result = result > (right - left + 1) ? result : (right - left + 1);
    }
    return result;
  }
};

int main()
{
  std::vector<int> v = {1, 2, 3, 2, 2};
  Solution s;
  std::cout << s.totalFruit(v);
}