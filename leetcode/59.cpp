#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> generateMatrix(int n)
  {
    vector<vector<int>> mat(n, vector<int>(n, 0)); // 定义一个二维数组
    int startx = 0, starty = 0;
    int loop = n / 2; // 循环次数
    int count = 1;    // 给每个位置赋值
    int offset = 1;   // 缩减步数
    int i, j;
    while (loop)
    {
      for (j = starty; j < n - offset; j++)
      {
        mat[startx][j] = count;
        count++;
      }
      for (i = startx; i < n - offset; i++)
      {
        mat[i][j] = count;
        count++;
      }
      for (; j > starty; j--)
      {
        mat[i][j] = count;
        count++;
      }
      for (; i > startx; i--)
      {
        mat[i][j] = count;
        count++;
      }
      startx++;
      starty++;
      offset++;
      loop--;
    }
    if (n % 2 != 0)
    {
      mat[n / 2][n / 2] = n * n;
    }
    return mat;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> mat = s.generateMatrix(3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      std::cout << mat[i][j] << " ";
}