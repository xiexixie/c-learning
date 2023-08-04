#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<double> averageOfLevels(TreeNode *root)
  {
    vector<double> result;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
      double sum = 0;
      int size = que.size();
      for (int i = 0; i < size; i++)
      {
        TreeNode *node;
        node = que.front();
        que.pop();
        sum += node->val;
        if (node->left != nullptr)
          que.push(node->left);
        if (node->right != nullptr)
          que.push(node->right);
      }
      result.push_back(sum / size);
    }
    return result;
  }
};