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