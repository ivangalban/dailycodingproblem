/*
This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message,
count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded
as 'aaa', 'ka', and 'ak'.
*/
#include <iostream>
#include <vector>

using namespace std;

int to_num(char d, char u)
{
  return (d - '0') * 10 + (u - '0');
}

int solve(string s)
{
  int n = s.length();
  vector<int> dp(n + 1);

  dp[0] = dp[1] = 1;
  for (int i = 2; i <= n; ++i)
    dp[i] = dp[i - 1] + dp[i - 2] * (to_num(s[i - 2], s[i - 1]) <= 26 ? 1 : 0);

  return dp[n];
}

int main()
{
  string s;
  cin >> s;
  cout << solve(s);
  return 0;
}