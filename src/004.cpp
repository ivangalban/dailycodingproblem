// This problem was asked by Stripe.

// Given an array of integers, find the first missing positive integer
// in linear time and constant space. In other words, find the lowest
// positive integer that does not exist in the array. The array can contain
// duplicates and negative numbers as well.

// For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

// You can modify the input array in-place.

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <assert.h>
#include <random>
#include <time.h>

using namespace std;

#define DB(x) cout << #x << " = " << x << "\n";

int missing_number1(vector<int> &v)
{
  int l = 0, n = v.size();
  for (int i = 0; i < n; ++i)
    if (v[i] < 0)
      swap(v[i], v[l]), v[l++] *= -1;

  for (int i = l; i < n; ++i)
    if (abs(v[i]) - 1 < n)
      v[abs(v[i]) - 1] = -abs(v[abs(v[i]) - 1]);

  for (int i = 0; i < n; ++i)
    if (v[i] >= 0)
      return i + 1;

  return n;
}

int missing_number2(vector<int> &v)
{
  const int size = v.size();

  for (int i = 0; i < size; ++i)
    while (v[i] != i && v[v[i]] != v[i] && v[i] >= 0 && v[i] < size)
      swap(v[i], v[v[i]]);

  for (int i = 1; i < size; ++i)
    if (v[i] != i)
      return i;

  return size;
}

vector<int> generate_vector()
{
  int n = rand() % 100;
  int m = rand() % 100;
  vector<int> v(n + m);

  for (int i = 0; i < n; ++i)
    v[i] = rand() % 100;

  for (int i = n; i < n + m; ++i)
    v[i] = -(rand() % 100);

  random_shuffle(begin(v), end(v));

  return v;
}

int main()
{
  srand(time(NULL));
  int nc = 100;

  for (int i = 0; i < 1000; ++i)
  {
    auto v = generate_vector();
    vector<int> v1(v), v2(v);
    assert(missing_number1(v1) == missing_number2(v2));
  }

  return 0;
}