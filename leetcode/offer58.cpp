#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
  string reverseLeftWords(string s, int n)
  {
    // 1.翻转前n个字符串
    reverse(s.begin(), s.begin() + n);
    // 2.反转n到末尾的字符串
    reverse(s.begin() + n, s.end());
    // 3.翻转整个字符串
    reverse(s.begin(), s.end());
    return s;
  }
};