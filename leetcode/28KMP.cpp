#include <string>
using namespace std;

class Solution
{
public:
  // KMP算法
  void getNext(int *next, string &s)
  {
    int j = -1;
    next[0] = j;
    for (int i = 1; i < s.size(); i++)
    { // 注意i从1开始
      while (j >= 0 && s[i] != s[j + 1])
      {              // 前后缀不相同了
        j = next[j]; // 向前回退
      }
      if (s[i] == s[j + 1])
      { // 找到相同的前后缀
        j++;
      }
      next[i] = j; // 将j（前缀的长度）赋给next[i]
    }
  }
  int strStr(string haystack, string needle)
  {
    int next[needle.size()];
    getNext(next, needle);
    int j = -1; // next数组起始记录位置为-1
    for (int i = 0; i < haystack.size(); i++)
    {
      // 不匹配
      while (j >= 0 && haystack[i] != needle[j + 1])
        j = next[j]; // 回退

      // 匹配
      if (haystack[i] == needle[j + 1])
        j++;

      // 匹配到needle
      if (j == needle.size() - 1)
        return (i - needle.size() + 1);
    }
    return -1;
  }
};