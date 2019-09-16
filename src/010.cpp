/*
This problem was asked by Apple.

Implement a job scheduler which takes in a function f and an integer
n, and calls f after n milliseconds.
*/

#include <iostream>
#include <windows.h>

using namespace std;

void f()
{
  cout << "foo" << endl;
}

void dispatch_delay(void (*f)(), int ms)
{
  Sleep(ms);
  f();
}

int main()
{
  int ms = 3000;
  cout << "waiting " << ms << "ms\n";
  dispatch_delay(f, 3000);

  return 0;
}