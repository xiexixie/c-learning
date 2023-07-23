#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string removeDuplicates(string s)
  {
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
      if (!st.empty() && st.top() == s[i])
        st.pop();
      else
        st.push(s[i]);
    }
    string res;
    while (!st.empty())
    {
      res.push_back(st.top());
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main()
{
  string s = "abbaca";
  Solution solu;
  string res = solu.removeDuplicates(s);
}