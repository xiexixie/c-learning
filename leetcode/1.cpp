#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  // map中key存放数组的值，value存放下标
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
      if (map.find(target - nums[i]) != map.end())
      {
        return {i, map[target - nums[i]]};
      }
      map.insert(pair<int, int>(nums[i], i));
    }
    return {};
  }
};