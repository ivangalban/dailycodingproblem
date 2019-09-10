/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element
at index i of the new array is the product of all the numbers in the
original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would
be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output
would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> solve_bonus(vector<int> v)
{
  int n = v.size();
  vector<int> pref(n + 1), suff(n + 1), ans(n);
  pref[0] = suff[n] = 1;

  for (int i = 1; i <= n; ++i)
  {
    pref[i] = pref[i - 1] * v[i - 1];
    suff[n - i] = suff[n - i + 1] * v[n - i];
  }

  for (int i = 0; i < n; ++i)
    ans[i] = pref[i] * suff[i + 1];

  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);

  for (auto &x : v)
    cin >> x;

  auto ans = solve_bonus(v);

  for (auto x : ans)
    cout << x << " ";

  return 0;
}