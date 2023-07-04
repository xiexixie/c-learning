#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
  // 暴力解法  o(n+lgn)
  vector<int> sortedSquares(vector<int> &nums)
  {
    for (int i = 0; i < nums.size(); i++)
    {
      nums[i] *= nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
  }
  // 双指针法 一个位于开始，一个位于末尾   o(n)
  vector<int> sortedSquares1(vector<int> &nums)
  {
    int k = nums.size() - 1;
    vector<int> result(nums.size(), 0);
    for (int i = 0, j = nums.size() - 1; i <= j;)
    {
      if (nums[i] * nums[i] > nums[j] * nums[j])
      {
        result[k] = nums[i] * nums[i];
        k--;
        i++;
      }
      else
      {
        result[k] = nums[j] * nums[j];
        k--;
        j--;
      }
    }
    return result;
  }
};

int main()
{
  std::vector<int> nums = {-7, -3, 2, 3, 11};
  Solution s;
  std::vector<int> result = s.sortedSquares1(nums);
  for (int i = 0; i < result.size(); i++)
    std::cout << result[i] << " ";
}