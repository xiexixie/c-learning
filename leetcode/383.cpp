#include <string>
using namespace std;

class Solution
{
public:
  // 暴力解法
  bool canConstruct(string ransomNote, string magazine)
  {
    for (int i = 0; i < magazine.size(); i++)
    {
      for (int j = 0; j < ransomNote.size(); j++)
      {
        if (ransomNote[j] == magazine[i])
        {
          ransomNote.erase(ransomNote.begin() + j);
          break;
        }
      }
    }
    if (ransomNote.size() == 0)
      return true;
    else
      return false;
  }

  // 哈希解法，使用数组
  bool canConstruct1(string ransomNote, string magazine)
  {
    int hash[26] = {0};
    for (int i = 0; i < magazine.size(); i++)
      hash[magazine[i] - 'a']++;
    for (int j = 0; j < ransomNote.size(); j++)
    {
      hash[ransomNote[j] - 'a']--;
      if (hash[ransomNote[j] - 'a'] < 0)
        return false;
    }
    return true;
  }
};