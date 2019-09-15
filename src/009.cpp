#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &v)
{
  int n = v.size();
  vector<int> dp(n + 1);

  dp[1] = v[0];
  for (int i = 2; i <= n; ++i)
    dp[i] = max(dp[i - 1], dp[i - 2] + v[i - 1]);

  return dp[n];
}

int main()
{
  vector<int> v1 = {2, 4, 6, 2, 5};
  vector<int> v2 = {5, 1, 1, 5};

  cout << solve(v1) << endl; // 13
  cout << solve(v2) << endl; // 10

  return 0;
}