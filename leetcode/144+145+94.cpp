#include <vector>

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
  // 前序遍历，根左右
  void traversal1(TreeNode *node, vector<int> &res)
  {
    if (node == nullptr)
      return;
    res.push_back(node->val);
    traversal1(node->left, res);
    traversal1(node->right, res);
  }

  // 后序遍历，左右根
  void traversal2(TreeNode *node, vector<int> &res)
  {
    if (node == nullptr)
      return;
    traversal2(node->left, res);
    traversal2(node->right, res);
    res.push_back(node->val);
  }

  // 中序遍历，左根右
  void traversal3(TreeNode *node, vector<int> &res)
  {
    if (node == nullptr)
      return;
    traversal3(node->left, res);
    res.push_back(node->val);
    traversal3(node->right, res);
  }

  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> result;
    traversal1(root, result);
    return result;
  }
};