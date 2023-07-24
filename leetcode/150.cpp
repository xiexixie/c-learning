#include <vector>
#include <string>
#include <stdio.h>
#include <stack>

using namespace std;

class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> st;

    for (int i = 0; i < tokens.size(); i++)
    {
      if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
      {
        int x2 = st.top();
        st.pop();
        int x1 = st.top();
        st.pop();
        if (tokens[i] == "+")
          st.push(x1 + x2);
        if (tokens[i] == "-")
          st.push(x1 - x2);
        if (tokens[i] == "*")
          st.push(x1 * x2);
        if (tokens[i] == "/")
          st.push(x1 / x2);
      }
      else
        st.push(stoi(tokens[i]));
    }
    return st.top();
  }
};