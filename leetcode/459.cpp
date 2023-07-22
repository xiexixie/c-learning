#include <string>
using namespace std;

class Solution
{
public:
  // 移动匹配法，两个相同字符串拼接在一起的时候，如果掐头去尾后还可以找到，说明符合条件
  bool repeatedSubstringPattern(string s)
  {
    string t = s + s;
    t.erase(t.begin());
    t.erase(t.end() - 1);
    if (t.find(s) != -1)
      return true;
    return false;
  }
};