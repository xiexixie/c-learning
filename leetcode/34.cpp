#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int border = binary_search(nums, target);
    if (border == -1)
    {
      return {-1, -1};
    }
    else
    {
      int left = border;
      int right = border;
      while (left - 1 >= 0 && nums[left - 1] == target)
      {
        left--;
      }
      while (right + 1 < nums.size() && nums[right + 1] == target)
      {
        right++;
      }
      return {left, right};
    }
  }

private:
  int binary_search(vector<int> &nums, int target)
  {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
      int middle = (left + right) / 2;
      if (nums[middle] > target)
        right = middle - 1;
      else if (nums[middle] < target)
        left = middle + 1;
      else
        return middle;
    }
    return -1;
  }
};
int main()
{
  vector<int> nums = {1};
  vector<int> a;
  Solution s;
  a = s.searchRange(nums, 1);
  std::cout << a[0] << " " << a[1] << std::endl;
  return 0;
}