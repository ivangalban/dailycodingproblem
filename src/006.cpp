/*
This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field
named both, which is an XOR of the next node and the previous node.
Implement an XOR linked list; it has an add(element) which adds the
element to the end, and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python), you can
assume you have access to get_pointer and dereference_pointer functions
that converts between nodes and memory addresses.
*/
#include <iostream>
#include <cstdint>

using namespace std;

#define bit(i) (1 << i)
#define DB(x) cout << #x << " = " << x << "\n";

struct XorLinkedList
{
  int length = 0;
  struct Node
  {
    int val;
    Node *both = 0;
  } root;

  uintptr_t inv_xor(bool ans, bool a)
  {
    return ans == 0 ? a : 1 - a;
  }

  // This is the interesant function
  // calc next such that both = prev xor next
  uintptr_t f(uintptr_t prev, uintptr_t both)
  {
    uintptr_t next = 0;
    for (int i = 0; i < 32; ++i)
      next |= (inv_xor(both & (1 << i), prev & (1 << i)) << i);
    return next;
  }

  void add(int element)
  {
    Node *last = get_index(length);
    Node *new_node = new Node();

    last->val = element;
    last->both = (Node *)(reinterpret_cast<uintptr_t>(last->both) ^
                          reinterpret_cast<uintptr_t>(new_node));
    new_node->both = last;
    length++;
  }

  Node *get_index(int index)
  {
    Node *node = &root, *prev = 0, *tmp;
    for (int i = 0; i < index; ++i)
    {
      tmp = (Node *)f(reinterpret_cast<uintptr_t>(prev),
                      reinterpret_cast<uintptr_t>(node->both));
      prev = node;
      node = tmp;
    }

    return node;
  }
};

int main()
{
  XorLinkedList pepe;
  pepe.add(100);
  pepe.add(12);
  pepe.add(45);
  pepe.add(5);

  cout << pepe.get_index(0)->val << endl; // 100
  cout << pepe.get_index(1)->val << endl; // 12
  cout << pepe.get_index(2)->val << endl; // 45
  cout << pepe.get_index(3)->val << endl; // 5

  return 0;
}