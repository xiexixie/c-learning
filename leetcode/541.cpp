#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
  string reverseStr(string str, int k)
  {
    for (int i = 0; i < str.size(); i += 2 * k)
    {
      if (i + k <= str.size())
        reverse(str.begin() + i, str.begin() + i + k);
      else
        reverse(str.begin() + i, str.end());
    }
    return str;
  }
};