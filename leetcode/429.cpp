#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val)
  {
    val = _val;
  }

  Node(int _val, vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

class Solution
{
public:
  vector<vector<int>> levelOrder(Node *root)
  {
    vector<vector<int>> result;
    queue<Node *> que;
    if (root != nullptr)
      que.push(root);
    while (!que.empty())
    {
      int size = que.size();
      vector<int> vec;
      for (int i = 0; i < size; i++)
      {
        Node *node = que.front();
        que.pop();
        vec.push_back(node->val);
        for (int j = 0; j < node->children.size(); j++)
        {
          if (node->children[j] != nullptr)
            que.push(node->children[j]);
        }
      }
      result.push_back(vec);
    }
    return result;
  }
};
