#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
  // 对数组扩容，使用双指针
  string replaceSpace(string s)
  {
    // 判断字符串中空格的个数
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == ' ')
        count++;
    }
    int old = s.size();
    // 字符串扩容
    s.resize(s.size() + count * 2);
    int now = s.size();
    for (int i = old, j = now; j != i; i--, j--)
    {
      if (s[i] == ' ')
      {
        s[j] = '0';
        s[j - 1] = '2';
        s[j - 2] = '%';
        j = j - 2;
      }
      else
      {
        s[j] = s[i];
      }
    }
    return s;
  }
};

int main()
{
  string str = "we are happy";
  Solution s;
  string str1 = s.replaceSpace(str);
  std::cout << str1;
}