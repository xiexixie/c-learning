#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_set<int> result;
    unordered_set<int> num(nums1.begin(), nums1.end());
    for (int i = 0; i < nums2.size(); i++)
    {
      if (num.find(nums2[i]) != num.end())
      {
        result.insert(nums2[i]);
      }
    }
    return vector<int>(result.begin(), result.end());
  }
};