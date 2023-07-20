#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
  void delete_space(string &s)
  {
    int slow = 0;
    for (int fast = 0; fast < s.size(); fast++)
    {
      if (s[fast] != ' ')
      {
        // 每个单词前方添加空格，首个单词除外
        if (slow != 0)
        {
          s[slow] = ' ';
          slow++;
        }
        while (fast < s.size() && s[fast] != ' ')
        {
          s[slow] = s[fast];
          fast++;
          slow++;
        }
      }
    }
    s.resize(slow);
  }
  void reverse(string &s, int start, int end)
  {
    for (int i = start, j = end; i < j; i++, j--)
    {
      swap(s[i], s[j]);
    }
  }
  string reverseWords(string s)
  {
    // 删除空格
    delete_space(s);
    // 反转整个字符串
    reverse(s, 0, s.size() - 1);
    int count = 0;
    int start = 0;
    for (int i = 0; i <= s.size(); i++)
    {
      if (s[i] != ' ' && s[i] != '\0')
      {
        count++;
      }
      else
      {
        reverse(s, start, start + count - 1);
        start = i + 1;
        count = 0;
      }
    }
    return s;
  }
};

int main()
{
  string str = "  hello world  ";
  Solution s;
  std::cout << s.reverseWords(str);
}