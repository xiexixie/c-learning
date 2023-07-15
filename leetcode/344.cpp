#include <vector>
using namespace std;

class Solution
{
public:
  // 双指针法
  void reverseString(vector<char> &s)
  {
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
    {
      int temp = s[j];
      s[j] = s[i];
      s[i] = temp;
    }
  }
};