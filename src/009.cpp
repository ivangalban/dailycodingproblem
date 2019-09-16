/*
This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest
sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6,
and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

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