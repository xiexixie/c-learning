#include <unordered_set>

using namespace std;

class Solution
{
public:
  int getSum(int n)
  {
    int sum = 0;
    while (n)
    {
      sum += (n % 10) * (n % 10);
      n = n / 10;
    }
    return sum;
  }
  bool isHappy(int n)
  {
    unordered_set<int> set;
    while (1)
    {
      n = getSum(n);
      if (n == 1)
        return true;
      if (set.find(n) != set.end())
      {
        return false;
      }
      set.insert(n);
    }
  }
};