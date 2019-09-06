/*
This problem was recently asked by Google.
Given a list of numbers and a number k, return whether any two
numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool solve_sort(vector<int> v, int k)
{
  sort(begin(v), end(v));
  int l = 0, r = v.size() - 1;

  while (l <= r)
  {
    if (v[l] + v[r] == k)
      return true;
    if (v[l] + v[r] > k)
      --r;
    if (v[l] + v[r] < k)
      ++l;
  }
  return false;
}

bool solve_hash(vector<int> v, int k)
{
  unordered_set<int> us;
  for (auto x : v)
  {
    if (us.count(k - x))
      return true;
    us.insert(x);
  }
  return false;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> v(n);

  for (auto &x : v)
    cin >> x;

  bool ans_sort = solve_sort(v, k);
  cout << "ans_sort = " << ans_sort << "\n";

  bool ans_hash = solve_hash(v, k);
  cout << "ans_hash = " << ans_hash << "\n";

  return 0;
}