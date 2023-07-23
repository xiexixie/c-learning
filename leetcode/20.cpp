#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> st;
    if (s.size() % 2 != 0) // 有奇数个符号，一定无法匹配
      return false;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
        st.push(')');
      else if (s[i] == '[')
        st.push(']');
      else if (s[i] == '{')
        st.push('}');
      else if (st.empty() || st.top() != s[i])
        return false;
      else
        st.pop();
    }
    return st.empty();
  }
};