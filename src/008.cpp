/*
This problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
*/

#include <iostream>
#include <vector>

using namespace std;

#define left(x) (2 * x + 1)
#define right(x) (2 * x + 2)
#define DB(x) cout << #x << " = " << x << "\n";

vector<int> t;
vector<int> dp[2];

void dfs(int u)
{
  if (t[u] == -1)
    return;

  dfs(left(u));
  dfs(right(u));

  if (t[left(u)] == -1 && t[right(u)] == -1)
    dp[1][u] = 1;

  else if (t[left(u)] == t[right(u)] && t[u] == t[left(u)] &&
           dp[1][left(u)] == 1 && dp[1][right(u)] == 1)
    dp[1][u] = 1;

  dp[0][u] = dp[1][u] + dp[0][left(u)] + dp[0][right(u)];
}

int solve()
{
  dfs(0);
  return dp[0][0];
}

int main()
{
  int n = 7;
  t = vector<int>(4 * n, -1);
  dp[0] = vector<int>(4 * n);
  dp[1] = vector<int>(4 * n);

  t[0] = 0;
  t[1] = 1;
  t[2] = 0;

  t[5] = 1;
  t[6] = 0;

  t[11] = 1;
  t[12] = 1;

  cout << solve() << endl;

  return 0;
}