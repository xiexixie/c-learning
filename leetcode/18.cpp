#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
      // 剪枝处理,不然会运行超时
      if (nums[i] > target && nums[i] >= 0)
        break; // 这里使用break，统一通过最后的return返回

      if (i > 0 && nums[i] == nums[i - 1]) // 去重
        continue;

      for (int j = i + 1; j < nums.size(); j++)
      {
        if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
          break;

        if (j > i + 1 && nums[j] == nums[j - 1]) // 去重
          continue;

        int left = j + 1;
        int right = nums.size() - 1;
        while (right > left)
        {
          if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) // long,不然溢出
            right--;
          else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
            left++;
          else
          {
            result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
            while (right > left && nums[right] == nums[right - 1]) // 去重
              right--;
            while (right > left && nums[left] == nums[left + 1]) // 去重
              left++;

            // 收缩
            right--;
            left++;
          }
        }
      }
    }
    return result;
  }
};

int main()
{
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  int target = 0;
  Solution s;
  s.fourSum(nums, target);
}