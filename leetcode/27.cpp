#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
  // 暴力解法  时间复杂度o(n^2) 空间复杂度o(1)
  int removeElement(vector<int> &nums, int val)
  {
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
      if (nums[i] == val)
      {
        for (int j = i; j < size - 1; j++)
        {
          nums[j] = nums[j + 1];
        }
        size--;
        i--;
      }
    }
    return size;
  }
  // 双指针法，时间复杂度o(n)，空间复杂度o(1)
  int removeElement1(vector<int> &nums, int val)
  {
    int slow_index = 0;
    for (int fast_index = 0; fast_index < nums.size(); fast_index++)
    {
      if (nums[fast_index] != val)
      {
        nums[slow_index] = nums[fast_index];
        slow_index++;
      }
    }
    return slow_index;
  }
};

int main()
{
  std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  Solution s;
  int size = s.removeElement1(nums, 2);
  std::cout << size << std::endl;
  for (int i = 0; i < size; i++)
    std::cout << nums[i] << " ";
}