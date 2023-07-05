#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    unordered_map<char, int> hs, ht;
    for (auto c : t)
      ht[c]++;
    string res;
    int cnt = 0;
    for (int right = 0, left = 0; right < s.size(); right++)
    {
      hs[s[right]]++;
      if (hs[s[right]] <= ht[s[right]])
        cnt++;

      while (hs[s[left]] > ht[s[left]])
      {
        hs[s[left]]--;
        left++;
      }
      if (cnt == t.size())
      {
        if (res.empty() || right - left + 1 < res.size())
          res = s.substr(left, right - left + 1);
      }
    }
    return res;
  }
};

int main()
{
  std::string s = "ancbacbbsda";
  std::string t = "abc";
  Solution s0;
  std::cout << s0.minWindow(s, t);
  std::unordered_map<char, int> hash;
  std::cout << hash['n'];
}
