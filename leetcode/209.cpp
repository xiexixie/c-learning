#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
  // 滑动窗口法 o(n)
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int result = INT32_MAX;
    int sum = 0;
    int length = 0;
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
      sum += nums[j];
      while (sum >= target)
      {
        length = j - i + 1;
        result = result > length ? length : result;
        sum -= nums[i];
        i++;
      }
    }
    return result == INT32_MAX ? 0 : result;
  }
};

int main()
{
  std::vector<int> v = {1, 1, 1, 1, 1, 1, 1, 1};
  Solution s;
  std::cout << s.minSubArrayLen(25, v);
}